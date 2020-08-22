
#include <stdio.h>
#include <stdlib.h>

#include "Instruction.h"




/** 
 * A processor instruction
 */
struct Instruction
{
	/** 
	 * OpCode of the instruction to execute
	 */
	enum OpCode opcode;
	
	/** 
	 * Addressing mode of the instruction
	 */
	enum AddressingMode addressingMode;
	
	/**
	 * Flags modified by the instruction
	 */ 
	enum Flag flags;
	
	/**
	 * How many cycles the instruction takes
	 */
	unsigned char cycles;
	
	/**
	 * Size of the operand in bytes
	 */
	unsigned char operandSize;
};




Instruction * Instruction_create(
	enum OpCode opcode, 
	enum AddressingMode addressingMode, 
	enum Flag flags, 
	unsigned char cycles, 
	unsigned char operandSize
) {
	Instruction * this;

	this = malloc(sizeof(* this));
	if (NULL == this) {
		fprintf(stderr, "Error: Instruction %d memory allocation failed\n", opcode);
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
	if (NULL == this) {
		fprintf(stderr, "Warning: tried to delete NULL instruction\n");
		return;
	}

	if (NULL == * this) {
		fprintf(stderr, "Warning: tried to delete instruction, but it was already NULL\n");
		return;
	}

	free(* this);
	* this = NULL;
}
