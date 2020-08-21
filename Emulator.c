
#include <stdio.h>
#include <stdlib.h>

#include "Emulator.h"
#include "Instruction.h"
#include "Register.h"
#include "Stack.h"




/**
 * A SNES emulator
 */ 
struct Emulator
{
	/**
	 * Registers for the 65c816 chip
	 * @see Register.h
	 */
	Register ** registers;

	/**
	 * Instructions set of the 65c816 chip
	 * @see Instructions.h
	 */
	Instruction ** instructions;

	/**
	 * Translation table from SNES to computer instructions
	 * One callback per instruction
	 */
	void (** callbacks)(Emulator * this);

	/**
	 * Stack of the emulator
	 */
	Stack * stack;
};




/**
 * Gets the given flag in the status register and returns it
 * 
 * @param this - the emulator to read flag from
 * @param flag - the flag to read
 * 
 * @return - 1 if the flag is set, 0 otherwise
 */
/*static unsigned char __getFlag(const Emulator * const this, Flag flag);*/


/**
 * Sets the given flag in the status register
 * 
 * @param this - the emulator to set the flag in
 * @param flag - the flag to set
 */
static void __setFlag(Emulator * const this, Flag flag);


/**
 * Removes the given flag in the status register
 * 
 * @param this - the emulator to remove the flag from
 * @param flag - the flag to remove
 */
static void __clearFlag(Emulator * const this, Flag flag);


/*static void __toggleFlag(Emulator * const this);*/


/**
 * Inits all registers
 */
static void __initRegisters(Emulator * const this);


/**
 * Inits all instructions
 */
static void __initInstructions(Emulator * const this);


/**
 * Inits callbacks,
 */
static void __initCallbacks(Emulator * const this);




/**
 * Callbacks for instructions
 */
static void __callback_Break(Emulator * const this);




Emulator * Emulator_create(void)
{
	Emulator * this;

	this = malloc(sizeof(* this));
	if (NULL == this) {
		fprintf(stderr, "Emulator memory allocation failed\n");
		return NULL;
	}

	this->registers = malloc(sizeof(* this->registers) * RegisterCount);
	if (NULL == this->registers) {
		fprintf(stderr, "Registers memory allocation failed\n");
		Emulator_delete(& this);
		return NULL;
	}
	__initRegisters(this);

	this->instructions = malloc(sizeof(* this->instructions) * OpCodeCount);
	if (NULL == this->instructions) {
		fprintf(stderr, "Instructions storage allocation failed\n");
		Emulator_delete(& this);
		return NULL;	
	}
	__initInstructions(this);

	this->callbacks = malloc(sizeof(* this->callbacks) * OpCodeCount);
	if (NULL == this->callbacks) {
		fprintf(stderr, "Callbacks storage allocation failed\n");
		Emulator_delete(& this);
		return NULL;
	}
	__initCallbacks(this);

	this->stack = Stack_create();

	return this;
}


void Emulator_delete(Emulator ** this)
{
	unsigned int registerIndex;

	if ((NULL == this) || (NULL == * this)) {
		return;
	}

	for (registerIndex = 0; registerIndex < RegisterCount; registerIndex++) {
		Register_delete(& (* this)->registers[registerIndex]);
	}

	free((* this)->registers);
	(* this)->registers = NULL;

	free(* this);
	* this = NULL;
}




static void __setFlag(Emulator * const this, Flag flag)
{
	Register * flagRegister;
	unsigned char flags;

	flagRegister = this->registers[Register_ProcessorStatus];
	flags = Register_read(flagRegister);
	
	if (flags & flag) { /* flag already set */
		return;
	}

	Register_store(flagRegister, flags | flag); 
}


static void __clearFlag(Emulator * const this, Flag flag)
{
	Register * flagRegister;
	unsigned char flags;

	flagRegister = this->registers[Register_ProcessorStatus];
	flags = Register_read(flagRegister);
	
	if (flags & flag) {
		Register_store(flagRegister, flags ^ flag); 
	}
}


static void __initRegisters(Emulator * const this)
{
	this->registers[Register_Accumulator] = Register_create(Register_Accumulator, 16);
	this->registers[Register_DataBank] = Register_create(Register_DataBank, 8);
	this->registers[Register_DirectPage] = Register_create(Register_DirectPage, 16);
	this->registers[Register_ProcessorStatus] = Register_create(Register_ProcessorStatus, 8);
	this->registers[Register_ProgramBank] = Register_create(Register_ProgramBank, 8);
	this->registers[Register_ProgramCounter] = Register_create(Register_ProgramCounter, 16);
	this->registers[Register_StackPointer] = Register_create(Register_StackPointer, 16);
	this->registers[Register_X] = Register_create(Register_X, 16);
	this->registers[Register_Y] = Register_create(Register_Y, 16);
}


static void __initInstructions(Emulator * const this)
{
	this->instructions[OpCode_Break] = Instruction_create(
		OpCode_Break, 
		AddressingMode_Implied,
		Flag_DisableIRQ | Flag_Decimal, 
		2,
		8
	);
}


static void __initCallbacks(Emulator * const this)
{
	this->callbacks[OpCode_Break] = __callback_Break;
}


static void __callback_Break(Emulator * const this)
{
	__clearFlag(this, Flag_Decimal);
	__setFlag(this, Flag_DisableIRQ);
}
