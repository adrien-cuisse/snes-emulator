
#include <stdio.h>
#include <stdlib.h>

#include "Emulator.h"
#include "Processor/Instruction.h"
#include "Processor/Processor.h"
#include "Stack/Stack.h"




/**
 * An emulator
 */ 
struct Emulator
{
	/**
	 * The processor of the emulator
	 */
	Processor * processor;

	/**
	 * Translation table from native to computer instructions
	 * One callback per instruction
	 */
	void (** callbacks)(Emulator * this);

	/**
	 * Stack of the emulator
	 */
	Stack * stack;
};




Emulator * Emulator_create(Processor * processor, void (** callbacks)(Emulator * this))
{
	Emulator * this;

	this = malloc(sizeof(* this));
	if (NULL == this) {
		fprintf(stderr, "Memory allocation failed for emulator\n");
		return NULL;
	}

	this->processor = processor;
	this->callbacks = callbacks;
	this->stack = Stack_create();

	return this;
}


void Emulator_delete(Emulator ** this, unsigned int instructionsCount, unsigned registersCount)
{
	if (NULL == this) {
		fprintf(stderr, "Warning, tried to delete NULL emulator\n");
		return;
	}

	if (NULL == * this) {
		fprintf(stderr, "Warning: tried to delete emulator, but it was already NULL\n");
		return;
	}

	Processor_delete(& (* this)->processor, instructionsCount, registersCount);
	free((* this)->callbacks);
	Stack_delete(& (* this)->stack);
}
