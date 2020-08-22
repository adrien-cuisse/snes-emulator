
/**
 * SNES callbacks header
 * This is where the translation from native to computer code is made
 * Each callback must take the emulator in parameter
 * For further informations on emulated instructions, @see OpCode.h
 */


#ifndef SNES_CALLBACKS_HEADER
#define SNES_CALLBACKS_HEADER

#include "../common/Emulator.h"



/**
 * Callback for the Break instruction
 */
void snesCallback_Break(Emulator * emulator);




#endif /* SNES_CALLBACKS_HEADER */
