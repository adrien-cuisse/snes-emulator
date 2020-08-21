
#include <stdio.h>
#include <stdlib.h>

#include "Emulator.h"
#include "Stack.h"




/*
	New architecture ?

	Emulator
		Processor processor
			Instruction[] instructions
				AdressingMode adressingMode
				OpCode opcode
			Register[] registers
		Stack * stack
		unsigned char[] ram
		unsigned char[] videoRam

	Emulator_create(processor, registers, ramSize, videoRamSize)
*/


/** TODO: OpCode.h -> rename opcodes to be unique */
/** TODO: Emulator.c::__callbackBreak() -> stack usage */
/** TODO: Emulator.c::__initInstructions() -> store instructions and make callbacks */




int main(void)
{
	Emulator * emulator;

	emulator = Emulator_create();
	Emulator_delete(& emulator);

	return EXIT_SUCCESS;
}
