
#include <stdio.h>
#include <stdlib.h>

#include "../common/Emulator.h"
#include "../common/Processor/Instruction.h"
#include "../common/Processor/Processor.h"
#include "../common/Stack/Stack.h"

#include "AddressingMode.h"
#include "callbacks.h"
#include "Flag.h"
#include "OpCode.h"
#include "RegisterName.h"




/** TODO: OpCode.h -> rename opcodes to be unique */
/** TODO: callbacks.c::snesCallback_Break() -> stack usage */
/** TODO: emulator.c::createInstructions() -> add innstructions */
/** TODO: emulator.c::createCallbacks() -> add callbacks */




/**
 * Creates the registers of the 65c618 chip
 * 
 * @see ../common/Processor/Register.h for definition
 * @see ../common/Processor/Processor.h for usage
 * 
 * @return - the registers set of the SNES processor, or NULL if allocation failed
 */
static Register ** createRegisters(void);


/**
 * Creates the flags register of the 65c618 chip
 * 
 * @see ../common/Processor/Register.h for definition
 * @see ../common/Processor/Processor.h for usage
 * @see Flag.h for stored content definition
 * 
 * @return - the flags register of the SNES processor, or NULL if allocation failed
 */
static Register * createFlagsRegisters(void);


/**
 * Creates a 65c618 chip and returns it
 * 
 * @see ../common/Processor/Processor.h for definition
 * @see ../common/Emulator.h for usage
 * 
 * @return - the processor of the SNES, , or NULL if any required allocation failed
 */
static Processor * createProcessor(void);


/**
 * Creates a SNES emulator and returns it
 * 
 * @see ../common/Emulator.h for definition
 * 
 * @return - the created SNES emulator, or NULL of any required allocation failed
 */
static Emulator * createEmulator(void);


/**
 * Deletes the SNES emulator and sets it to NULL
 * 
 * @see ../common/Emulator.h for definition
 * 
 * @param emulator - the emulator to delete
 */
static void deleteEmulator(Emulator ** emulator);


/** 
 * Creates the instructions for the 65c618 chip
 * 
 * @see ../common/Processor/Instruction.h for definition
 * @see ../common/Processor/Processor.h for usage
 * 
 * @return - the instructions set of the SNES processor, or NULL if allocatail failed
 */
static Instruction ** createInstructions(void);


/**
 * Creates the callbacks array for the 65c618 chip
 * 
 * @see callbacks.h for callbacks definitions
 * @see ../common/Emulator.h for usage
 * 
 * @return - array of function pointers, where each entry is a callback for a SNES instruction, or NULL if allocation failed
 */
static void (** createCallbacks(void))(Emulator *);





int main(void)
{
	Emulator * emulator;

	emulator = createEmulator();
	fprintf(stdout, "SNES emulator running...\n");
	deleteEmulator(& emulator);


	return EXIT_SUCCESS;
}




static Register ** createRegisters(void)
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


static Register * createFlagsRegisters(void)
{
	return Register_create(Register_ProcessorStatus, 8);
}


static Processor * createProcessor(void)
{
	Instruction ** instructions;
	Register ** registers;
	Register * flags;

	instructions = createInstructions();
	if (NULL == instructions) {
		return NULL;
	}

	registers = createRegisters();
	if (NULL == registers) {
		free(instructions);
		* instructions = NULL;
		return NULL;
	}

	flags = createFlagsRegisters();
	if (NULL == flags) {
		free(instructions);
		* instructions = NULL;
		free(registers);
		* registers = NULL;
		return NULL;
	}

	return Processor_create(instructions, registers, flags);
}


static Emulator * createEmulator(void)
{
	Processor * processor;
	void (** callbacks)(Emulator *);

	processor = createProcessor();
	if (NULL == processor) {
		return NULL;
	}

	callbacks = createCallbacks();
	if (NULL == callbacks) {
		Processor_delete(& processor, OpCode_Count, Register_Count);
		return NULL;
	}

	return Emulator_create(processor, callbacks);
}


static void deleteEmulator(Emulator ** emulator)
{
	Emulator_delete(emulator, OpCode_Count, Register_Count);
}


static Instruction ** createInstructions(void)
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


static void (** createCallbacks(void))(Emulator *)
{
	void (** callbacks)(Emulator *);

	callbacks = malloc(sizeof(* callbacks) * OpCode_Count);
	if (NULL == callbacks) {
		fprintf(stderr, "Error: callbacks memory allocation failed\n");
		return NULL;
	}

	callbacks[OpCode_Break] = snesCallback_Break;

	return callbacks;
}
