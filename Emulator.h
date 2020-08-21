
#ifndef SNES_EMULATOR_HEADER
#define SNES_EMULATOR_HEADER

#include "Register.h"




/**
 * Forward declaration, @see Emulator.c
 */
typedef struct Emulator Emulator;




/**
 * Creates an emulator and returns it
 *
 * @return - the created emulator
 */
Emulator * Emulator_create(void);


/**
 * Deletes the emulator and sets it to NULL
 * 
 * @param this - the emulator to delete
 */
void Emulator_delete(Emulator ** this);




#endif /* SNES_EMULATOR_HEADER */
