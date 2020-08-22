
#include <stdio.h>
#include <stdlib.h>

#include "Processor.h"



/**
 * A processor
 */
struct Processor
{
	/**
	 * Instructions set of the processor, @see Instruction.h
	 */
	Instruction ** instructions;

	/**
	 * Registers of the processor, @see Register.h
	 */
	Register ** registers;

	/**
	 * Flags register, stored in its own property to ensure it's present
	 */
	Register * flags;
};




/**
 * Gets the position of the flag in the appropriate register
 * 
 * @param flag - the flag to find in the flags register, will be put in range for the destination byte
 * @param bytePosition - buffer to write the position of the byte containing the flag
 * @param bitPosition -  buffer to write the position of the bit containing the flag
 */
static void __getFlagPosition(enum Flag * flag, unsigned char * const bytePosition, unsigned char * const bitPosition);




Processor * Processor_create(Instruction ** instructions, Register ** registers, Register * flags)
{
	Processor * this;

	this = malloc(sizeof(* this));
	if (NULL == this) {
		fprintf(stderr, "Error: processor memory allocation failed\n");
		return NULL;
	}

	this->instructions = instructions;
	this->registers = registers;
	this->flags = flags;

	return this;
}


void Processor_delete(Processor ** this, unsigned int instructionsCount, unsigned registersCount)
{
	unsigned int index;

	if (NULL == this) {
		fprintf(stderr, "Warning: tried to delete NULL processor\n");
		return;
	}

	if (NULL == * this) {
		fprintf(stderr, "Warning: tried to delete processor, but it was already NULL\n");
		return;
	}

	for (index = 0; index < instructionsCount; index++) {
		Instruction_delete(& (* this)->instructions[index]);
	}
	free((* this)->instructions);
	(* this)->instructions = NULL;

	
	for (index = 0; index < registersCount; index++) {
		Register_delete(& ((* this)->registers[index]));
	}
	free((* this)->registers);
	(* this)->registers = NULL;
	
	free(* this);
	* this = NULL;
}


int Processor_hasFlag(Processor const * const this, enum Flag flag)
{
	unsigned char bytePosition;
	unsigned char bitPosition;
	unsigned char * flags;

	if (NULL == this) {
		fprintf(stderr, "Warning: tried to read flag from NULL processor\n");
		return 0;
	}

	__getFlagPosition(& flag, & bytePosition, & bitPosition);

	flags = Register_read(this->flags);

	return (flags[bytePosition] & flag) != 0;
}


void Processor_setFlag(Processor * const this, enum Flag flag)
{
	unsigned char bytePosition;
	unsigned char bitPosition;
	unsigned char * flags;

	if (NULL == this) {
		fprintf(stderr, "Warning: tried to set flag in NULL processor\n");
		return;
	}

	__getFlagPosition(& flag, & bytePosition, & bitPosition);

	flags = Register_read(this->flags);
	flags[bytePosition] |= flag;
	Register_store(this->flags, flags);
}


void Processor_clearFlag(Processor * const this, enum Flag flag)
{
	unsigned char bytePosition;
	unsigned char bitPosition;
	unsigned char * flags;

	if (NULL == this) {
		fprintf(stderr, "Warning: tried to clear flag from NULL processor\n");
		return;
	}

	if (Processor_hasFlag(this, flag)) {
		__getFlagPosition(& flag, & bytePosition, & bitPosition);

		flags = Register_read(this->flags);
		flags[bytePosition] ^= flag;
		Register_store(this->flags, flags);
	}
}




static void __getFlagPosition(enum Flag * flag, unsigned char * bytePosition, unsigned char * bitPosition)
{
	* bytePosition = 0;
	while (* flag > (1 << 8)) {
		* flag >>= 8;
		(* bytePosition)++;
	}

 	* bitPosition = 0;
	while (* flag) {
		* flag >>= 1;
		(* bitPosition)++;
	}
}
