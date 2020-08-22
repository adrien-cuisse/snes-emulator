
#include <stdio.h>
#include <stdlib.h>

#include "../common/Emulator.h"
#include "../common/Processor/Instruction.h"
#include "../common/Processor/Processor.h"
#include "../common/Stack/Stack.h"

#include "AddressingMode.h"
#include "Flag.h"
#include "OpCode.h"
#include "RegisterName.h"




/** TODO: OpCode.h -> rename opcodes to be unique */
/** TODO: Emulator.c::__callbackBreak() -> stack usage */
/** TODO: Emulator.c::__initInstructions() -> store instructions and make callbacks */



/** 
 * Creates the instructions for the 65c618 chip
 * 
 * @return - instructions set of the SNES
 */
static Instruction ** createSnesProcessorInstructions(void);


/**
 * Creates the registers of the 65c618 chip
 * 
 * @return - the registers set of the SNES processor
 */
static Register ** createSnesProcessorRegisters(void);


/**
 * Creates the flags register of the 65c618 chip
 * 
 * @return - the flags register of the SNES processor
 */
static Register * createSnesProcessorFlagsRegister(void);


/**
 * Creates a 65c618 chip and returns it
 * 
 * @return - the processor of the SNES
 */
static Processor * createSnesProcessor(void);


/**
 * Creates a SNES emulator and returns it
 * 
 * @return - the created SNES emulator, or NULL of any allocation failed
 */
static Emulator * createSnesEmulator(void);


/**
 * Deletes the SNES emulator and sets it to NULL
 * 
 * @param emulator - the emulator to delete
 */
static void deleteSnesEmulator(Emulator ** emulator);




int main(void)
{
	Emulator * emulator;

	emulator = createSnesEmulator();
	fprintf(stdout, "SNES emulator running...\n");
	deleteSnesEmulator(& emulator);


	return EXIT_SUCCESS;
}




static Instruction ** createSnesProcessorInstructions(void)
{
	Instruction ** instructions;

	instructions = malloc(sizeof(* instructions) * OpCode_Count);
	if (NULL == instructions) {
		fprintf(stderr, "Memory allocation failed for SNES instruction table\n");
		return NULL;
	}

	instructions[OpCode_Break] = Instruction_create(
		OpCode_Break, 
		AddressingMode_Implied,
		Flag_DisableIRQ | Flag_Decimal, 
		2,
		8
	);

	return instructions;
}


static Register ** createSnesProcessorRegisters(void)
{
	Register ** registers;

	registers = malloc(sizeof(* registers) * Register_Count);
	if (NULL == registers) {
		fprintf(stderr, "Memory allocation failed for SNES registers set\n");
		return NULL;
	}

	registers[Register_Accumulator] = Register_create(Register_Accumulator, 16);
	registers[Register_DataBank] = Register_create(Register_DataBank, 8);
	registers[Register_DirectPage] = Register_create(Register_DirectPage, 16);
	registers[Register_ProgramBank] = Register_create(Register_ProgramBank, 8);
	registers[Register_ProgramCounter] = Register_create(Register_ProgramCounter, 16);
	registers[Register_StackPointer] = Register_create(Register_StackPointer, 16);
	registers[Register_X] = Register_create(Register_X, 16);
	registers[Register_Y] = Register_create(Register_Y, 16);

	return registers;
}


static Register * createSnesProcessorFlagsRegister(void)
{
	return Register_create(Register_ProcessorStatus, 8);
}


static Processor * createSnesProcessor(void)
{
	Instruction ** instructions;
	Register ** registers;
	Register * flags;

	instructions = createSnesProcessorInstructions();
	if (NULL == instructions) {
		return NULL;
	}

	registers = createSnesProcessorRegisters();
	if (NULL == registers) {
		free(instructions);
		* instructions = NULL;
		return NULL;
	}

	flags = createSnesProcessorFlagsRegister();
	if (NULL == flags) {
		free(instructions);
		* instructions = NULL;
		free(registers);
		* registers = NULL;
		return NULL;
	}

	return Processor_create(instructions, registers, flags);
}


static Emulator * createSnesEmulator(void)
{
	Processor * processor;
	void (** callbacks)(Emulator *);

	processor = createSnesProcessor();
	if (NULL == processor) {
		return NULL;
	}

	callbacks = NULL;
	/* 
		callbacks = createSnesInstructionsCallbacks();
		if (NULL == callbacks) {
			Processor_delete(& processor, OpCode_Count, Register_Count);
			return NULL;
		}
	*/
	
	return Emulator_create(processor, callbacks);
}


static void deleteSnesEmulator(Emulator ** emulator)
{
	Emulator_delete(emulator, OpCode_Count, Register_Count);
}
