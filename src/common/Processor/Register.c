
#include <stdio.h>
#include <stdlib.h>

#include "Register.h"




/** 
 * A register inside a processor
 */
struct Register
{
	enum RegisterName name;
	unsigned char sizeInBits;
	unsigned char * content;
};




Register * Register_create(enum RegisterName name, unsigned char size)
{
	Register * this;
	unsigned int sizeInBytes;

	this = malloc(sizeof (* this));
	if (NULL == this) {
		fprintf(stderr, "Error: Register %d memory allocation failed\n", name);
		return NULL;
	}

	this->name = name;
	this->sizeInBits = size;

	sizeInBytes = (size / 8) + ((size % 8) ? 1 : 0);

	this->content = malloc(sizeof(* this->content) * sizeInBytes);
	if (NULL == this->content) {
		fprintf(stderr, "Error: Register %d storage memory allocation failed\n", name);
		Register_delete(& this);
		return NULL;
	}

	return this;
}


void Register_delete(Register ** this)
{
	if (NULL == this) {
		fprintf(stderr, "Warning: tried to delete NULL register\n");
		return;
	}

	if (NULL == * this) {
		fprintf(stderr, "Warning: tried to delete register, but it was already NULL\n");
		return;
	}

	if ((* this)->content) {
		free((* this)->content);
		(* this)->content = NULL;
	}

	free(* this);
	* this = NULL;
}


unsigned char Register_size(Register const * const this)
{
	if (NULL == this) {
		fprintf(stderr, "Warning: requested size of NULL register\n");
		return 0;
	}

	return this->sizeInBits;
}


unsigned char * Register_read(const Register * const this)
{
	if (NULL == this) {
		fprintf(stderr, "Warning, tried to read from NULL register\n");
		return NULL;
	}

	return this->content;
}


void Register_store(Register * const this, unsigned char * value)
{
	unsigned char bytePosition;
	unsigned char sizeInBytes;

	if (NULL == this) {
		fprintf(stderr, "Warning, tried to store in NULL register\n");
		return;
	}

	sizeInBytes = Register_size(this);
	sizeInBytes = (sizeInBytes / 8) + ((sizeInBytes % 8) ? 1 : 0);

	for (bytePosition = 0; bytePosition < sizeInBytes; bytePosition++) {
		this->content[bytePosition] = value[bytePosition];
	}
}
