
#include <stdio.h>
#include <stdlib.h>

#include "AddressingMode.h"
#include "Flag.h"
#include "Instruction.h"
#include "OpCode.h"




/** 
 * An instruction for the SNES 65c816 chip
 */
struct Instruction
{
	OpCode opcode; /** code of the instruction to execute, @see Instruction.h */
	AddressingMode addressingMode; /* the adressing mode of the instruction */
	Flag flags; /** flags modified by the instruction, @see Flag.h */
	unsigned char cycles; /* how many cycles the instruction takes */
	unsigned char operandSize; /* size of the operands in bytes (0-3) */
};


Instruction * Instruction_create(
	OpCode opcode, 
	AddressingMode addressingMode, 
	Flag flags, 
	unsigned char cycles, 
	unsigned char operandSize
) {
	Instruction * this;

	this = malloc(sizeof(* this));
	if (NULL == this) {
		fprintf(stderr, "Instruction %d memory allocation failed\n", opcode);
		return NULL;
	}

	this->opcode = opcode;
	this->addressingMode = addressingMode;
	this->flags = flags;
	this->cycles = cycles;
	this->operandSize = operandSize;

	return this;
}


/**
 * Deletes the instruction and sets it to NULL
 * 
 * @param this - the instruction to delete
 */
void Instruction_delete(Instruction ** this)
{
	(void)this;
}
