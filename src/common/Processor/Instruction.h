
/**
 * Processor instructions header
 * Since this is machine specific, enums should be defined in the target machine directory
 * Empty enums are used here, @see generics.h
 */


#ifndef PROCESSOR_INSTRUCTION_HEADER
#define PROCESSOR_INSTRUCTION_HEADER

#include "generics.h"




/**
 * Forward declaration, @see Instruction.c
 */
typedef struct Instruction Instruction;




/**
 * Creates a new instruction and returns it
 * 
 * @param opcode - opcode of the instruction, @see generics.h
 * @param addressingMode - the adressing mode of the instruction, @see generics.h
 * @param flags - flags modified by the instruction, @see generics.h
 * @param cycles - how many cycles the instruction takes
 * @param operandSize - size of the operand (in bytes)
 * 
 * @return - the created instruction
 */
Instruction * Instruction_create(
	enum OpCode opcode, 
	enum AddressingMode addressingMode, 
	enum Flag flags, 
	unsigned char cycles, 
	unsigned char operandSize
);


/**
 * Deletes the instruction and sets it to NULL
 * 
 * @param this - the instruction to delete
 */
void Instruction_delete(Instruction ** this);




#endif /* PROCESSOR_INSTRUCTION_HEADER */
