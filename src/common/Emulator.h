
/**
 * Emulator header, provides generic architecture
 */


#ifndef EMULATOR_HEADER
#define EMULATOR_HEADER

#include "Processor/Processor.h"




/**
 * Forward declaration, @see Emulator.c
 */
typedef struct Emulator Emulator;




/**
 * Creates an emulator and returns it
 * 
 * @param processor - the emulated processor
 * @param callbacks - array of callbacks, one per instruction in the processor instructions set (ordered the same way)
 *
 * @return - the created emulator
 */
Emulator * Emulator_create(Processor * processor, void (** callbacks)(Emulator * this));


/**
 * Deletes the emulator and sets it to NULL
 * The processor and the callbacks array are deleted as well
 * Sizes have to passed since it depends of the machine
 * 
 * @param this - the emulator to delete
 * @param instructionsCount - the size of the instructions set of the emulator's processor
 * @param registersCount - the size of the registers set of the emulator's processor
 */
void Emulator_delete(Emulator ** this, unsigned int instructionsCount, unsigned registersCount);




#endif /* EMULATOR_HEADER */
