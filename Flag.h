
/**
 * SNES flags header
 * Informations extracted from http://6502.org/tutorials/65c816opcodes.html#4
 */


#ifndef SNES_FLAG_HEADER
#define SNES_FLAG_HEADER




/**
 * Flags for the 65c816 chip
 * Renamed for better reading, official names are in comment
 */
typedef enum Flag
{
	/* E = 0x??, 6502 emulation mode */
	Flag_Carry = 0x01, /* C */
	Flag_Zero = 0x02, /* Z */
	Flag_DisableIRQ = 0x04, /* I */
	Flag_Decimal = 0x08, /* D */
	Flag_IndexSize = 0x10, /* X, index register size (native mode only) (0 = 16-bit, 1 = 8-bit) */
	Flag_Break = 0x10, /* B, emulation mode only */
	Flag_AccumulatorSize = 0x20, /* M, accumulator register size (native mode only) (0 = 16-bit, 1 = 8-bit) */
	Flag_Overflow = 0x40, /* V */
	Flag_Negative = 0x80 /* N */
} Flag;

/*
    P register bit 0: c carry flag 
    P register bit 1: z zero flag
    P register bit 2: i interrupt disabled flag
    P register bit 3: d decimal mode flag
    P register bit 4: x indefx register width flag (native mode), b flag (emulation mode)
    P register bit 5: m accumulator and memory width flag (native mode)
    P register bit 6: v overflow flag
    P register bit 7: n negative flag
*/



#endif /* SNES_FLAG_HEADER */
