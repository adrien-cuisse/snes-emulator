
/**
 * SNES registers name header
 * Informations extracted from http://6502.org/tutorials/65c816opcodes.html#4
 */


#ifndef SNES_REGISTER_NAME_HEADER
#define SNES_REGISTER_NAME_HEADER




/**
 * Snes processor's registers names
 */
typedef enum SnesProcessorRegisterName
{
	/**
	 * Official name: A
	 * Stores one of two operands or the result of most arithmetic and logical operations
	 */
	Register_Accumulator,

	/**
	 * Official name:  DBR / DB
	 * Holds the default bank for memory transfers
	 */
	Register_DataBank,

	/**
	 * Official name: D / DP
	 * Used for direct page addressing modes, holds the memory bank address of the data the CPU is accessing
	 */
	Register_DirectPage,

	/**
	 * Official name: PBR / PB
	 * Holds the bank address of all instruction fetches
	 */
	Register_ProgramBank,
 	
	/**
	 * Official name: PC
	 * Holds the memory address of the current CPU instruction
	 */
	Register_ProgramCounter,
	
	/**
	 * Official name: S
	 * Points to the next available (ie, unused) location on the stack
	 */
	Register_StackPointer,
	
	/**
	 * Official name: X
	 * Index register, can be used to reference memory, to pass data to memory, or as counters for loops
	 */
	Register_X,
	
	/**
	 * Official name: Y
	 * Index register, can be used to reference memory, to pass data to memory, or as counters for loops
	 */
	Register_Y,

	/**
	 * The number of registers in the set
	 */
	Register_Count,

	/**
	 * Official name: P
	 * Holds various important flags, results of tests and 65816 processing states
	 * Defined after Register_Count since its not in the set
	 */
	Register_ProcessorStatus
} RegisterName;




#endif /* SNES_REGISTER_NAME_HEADER */
