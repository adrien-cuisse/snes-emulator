
/**
 * Processor registers header
 * Informations extracted from http://6502.org/tutorials/65c816opcodes.html#4
 */


#ifndef PROCESSOR_REGISTER_HEADER
#define PROCESSOR_REGISTER_HEADER

#include "generics.h"




/**
 * Forward declaration, @see Register.c
 */
typedef struct Register Register;




/**
 * Creates a new register and returns it
 * 
 * @param name - the name of the register
 * @param size - the size of the register (in bits)
 * 
 * @return - the created register
 */
Register * Register_create(enum RegisterName name, unsigned char size);


/**
 * Deletes the register and sets its to NULL
 * 
 * @param this - the register to delete
 */
void Register_delete(Register ** this);


/**
 * Returns the size of the register
 * 
 * @param this - the register to get the size from
 * 
 * @return - the size (in bits) of the register
 */
unsigned char Register_size(Register const * const this);


/**
 * Reads the content if the register and returns it
 * 
 * @param this - the register to read
 * 
 * @return - the content of the register
 */
unsigned char * Register_read(const Register * const this);


/**
 * Updates the content of the register
 * 
 * @param this - the register to update
 * @param value - the value to store in the register, must be the same size than the register
 */
void Register_store(Register * const this, unsigned char * value);




#endif /* PROCESSOR_REGISTER_HEADER */
