
/**
 * Processor header
 */


#ifndef PROCESSOR_HEADER
#define PROCESSOR_HEADER

#include "Instruction.h"
#include "Register.h"




/**
 * Forward declaration, @see Processor.c
 */
typedef struct Processor Processor;




/**
 * Creates a new processor and returns it
 * 
 * @param instructions - instructions set for the processor, @see Instruction.h
 * @param registers - registers of the processor, @see Register.h
 * @param flags - flags register
 * 
 * @return - the created processor
 */
Processor * Processor_create(Instruction ** instructions, Register ** registers, Register * flags);


/**
 * Deletes the processor and sets it to NULL
 * Instructions and registers are deleted as well
 * Sizes have to passed since it depends of the machine
 * 
 * @param this - the processor to delete
 * @param instructionsCount - the size of the instructions set of the processor
 * @param registersCount - the size of the registers set of the processor
 */
void Processor_delete(Processor ** this, unsigned int instructionsCount, unsigned registersCount);


/**
 * Checks if the processor has the given flag set to 1
 * 
 * @param this - the processor to check flag in
 * @param flag - the flag to check in the processor
 * 
 * @return - 1 if the processor has the given flag set to 1, 0 otherwise
 */
int Processor_hasFlag(Processor const * const this, enum Flag flag);


/**
 * Sets the given flag
 * 
 * @param this - the processor to set the flag in
 * @param flag - the flag to set in the processor
 */
void Processor_setFlag(Processor * const this, enum Flag flag);


/**
 * Clears the flag in the processor
 * 
 * @param this - the processor to remove the flag from
 * @param flag - the flag to remove from the processor
 */
void Processor_clearFlag(Processor * const this, enum Flag flag);




#endif /* PROCESSOR_HEADER */
