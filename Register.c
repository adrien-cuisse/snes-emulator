
#include <stdio.h>
#include <stdlib.h>

#include "Register.h"




/** 
 * A register of the SNES
 */
struct Register
{
	RegisterName name;
	unsigned char sizeInBits; /* 8 or 16 */
	unsigned char * content;
};




Register * Register_create(RegisterName name, unsigned char size)
{
	Register * this;

	this = malloc(sizeof (* this));
	if (NULL == this) {
		fprintf(stderr, "Register %d memory allocation failed\n", name);
		return NULL;
	}

	this->name = name;
	this->sizeInBits = size;

	this->content = malloc(sizeof(* this->content) * (size / 8));
	if (NULL == this->content) {
		fprintf(stderr, "Register %d storage memory allocation failed\n", name);
		Register_delete(& this);
		return NULL;
	}

	return this;
}


void Register_delete(Register ** this)
{
	if ((NULL == this) || (NULL == * this)) {
		return;
	}

	if ((* this)->content) {
		free((* this)->content);
		(* this)->content = NULL;
	}

	free(* this);
	* this = NULL;
}


unsigned short Register_read(const Register * const this)
{
	if (8 == this->sizeInBits) {
		return this->content[0];
	}

	return (this->content[1] << 8) | this->content[0];
}


void Register_store(Register * const this, unsigned short value)
{
	if (8 == this->sizeInBits) {
		this->content[0] = value & 0xff;
		return;
	}

	this->content[1] = (value & 0xff00) >> 8;
	this->content[0] = value & 0x00ff;
}
