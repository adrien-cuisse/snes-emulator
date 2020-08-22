
/**
 * SNES adressing modes header
 * Informations extracted from https://wiki.superfamicom.org/65816-reference#toc-2
 */

#ifndef SNES_ADDRESSING_MODE_HEADER
#define SNES_ADDRESSING_MODE_HEADER




/**
 * An addressing mode for instructions
 */
typedef enum SnesInstructionAddressingMode
{
	AddressingMode_Implied,
	AddressingMode_ImmediateMemoryFlag,
	AddressingMode_ImmediateIndexFlag,
	AddressingMode_Immediate8bits,
	AddressingMode_Relative,
	AddressingMode_RelativeLong,
	AddressingMode_Direct,
	AddressingMode_DirectIndexedX,
	AddressingMode_DirectIndexedY,
	AddressingMode_DirectIndirect,
	AddressingMode_DirectIndexedIndirect,
	AddressingMode_DirectIndirectIndexed,
	AddressingMode_DirectIndirectLong,
	AddressingMode_DirectIndirectIndexedLong,
	AddressingMode_Absolute,
	AddressingMode_AbsoluteIndexedX,
	AddressingMode_AbsoluteIndexedY,
	AddressingMode_AbsoluteLong,
	AddressingMode_AbsoluteIndexedLong,
	AddressingMode_StackRelative,
	AddressingMode_StackRelativeIndirectIndexed,
	AddressingMode_AbsoluteIndirect,
	AddressingMode_AbsoluteIndirectLong,
	AddressingMode_AbsoluteIndexedIndirect,
	AddressingMode_ImpliedAccumulator,
	AddressingMode_BlockMove
} AddressingMode;




#endif /* SNES_ADDRESSING_MODE_HEADER */
