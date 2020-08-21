
/**
 * SNES registers header
 * Informations extracted from http://6502.org/tutorials/65c816opcodes.html#4
 */


#ifndef SNES_REGISTER_HEADER
#define SNES_REGISTER_HEADER




/**
 * Register names for the SNES
 * Renamed for better reading, official names are in comment
 */
typedef enum RegisterName
{
	Register_Accumulator, /* A, the math register. It stores one of two operands or the result of most arithmetic and logical operations */
	Register_DataBank, /* DBR or DB, holds the default bank for memory transfers */
	Register_DirectPage, /* D or DP, used for direct page addressing modes. Holds the memory bank address of the data the CPU is accessing */
	Register_ProcessorStatus, /* P, holds various important flags, results of tests and 65816 processing states */
	Register_ProgramBank, /* PBR or PB, holds the bank address of all instruction fetches */
 	Register_ProgramCounter, /* PC, holds the memory address of the current CPU instruction */
	Register_StackPointer, /* S, points to the next available(unused) location on the stack */
	Register_X, /* X, index register, can be used to reference memory, to pass data to memory, or as counters for loops */
	Register_Y, /* Y, index register, can be used to reference memory, to pass data to memory, or as counters for loops */

	RegisterCount
} RegisterName;


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
Register * Register_create(RegisterName name, unsigned char size);


/**
 * Deletes the register and sets its to NULL
 * 
 * @param this - the register to delete
 */
void Register_delete(Register ** this);


/**
 * Reads the content if the register and returns it
 * 
 * @param this - the register to read
 * 
 * @return - the content of the register
 */
unsigned short Register_read(const Register * const this);


/**
 * Updates the content of the register
 * 
 * @param this - the register to update
 * @param value - the value to store in the register
 */
void Register_store(Register * const this, unsigned short value);




#endif /* SNES_REGISTER_HEADER */
