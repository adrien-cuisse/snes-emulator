
/**
 * SNES instructions header
 * Informations extracted from https://wiki.superfamicom.org/65816-reference#toc-3
 */


#ifndef SNES_INSTRUCTION_HEADER
#define SNES_INSTRUCTION_HEADER

#include "AddressingMode.h"
#include "Flag.h"
#include "OpCode.h"




/**
 * Forward declaration, @see Instruction.c
 */
typedef struct Instruction Instruction;




/**
 * Creates a new instruction and returns it
 * 
 * @param opcode - opcode of the instruction, @see OpCode.h
 * @param addressingMode - the adressing mode of the instruction, @see AdressingMode.h
 * @param flags - flags modified by the instruction, @see Flag.h
 * @param cycles - how many cycles the instruction takes
 * @param operandSize - size of the operand (in bytes)
 * 
 * @return - the created instruction
 */
Instruction * Instruction_create(
	OpCode opcode, 
	AddressingMode addressingMode, 
	Flag flags, 
	unsigned char cycles, 
	unsigned char operandSize
);


/**
 * Deletes the instruction and sets it to NULL
 * 
 * @param this - the instruction to delete
 */
void Instruction_delete(Instruction ** this);





#endif /* SNES_INSTRUCTION_HEADER */
