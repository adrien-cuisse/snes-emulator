
/**
 * SNES intructions opcodes header
 * Informations extracted from https://wiki.superfamicom.org/65816-reference#toc-3
 */


#ifndef SNES_OP_CODE_HEADER
#define SNES_OP_CODE_HEADER




/**
 * OpCodes for the 65c816 chip
 */
typedef enum SnesInstructionOpCode
{
	OpCode_Break = 0x00, /* Break */

#if 0 /* Not implemented */
	ORA = 0x01, /* OR Accumulator with Memory */
	COP = 0x02, /* Co-Processor Enable */
	ORA = 0x03, /* OR Accumulator with Memory */
	TSB = 0x04, /* Test and Set Memory Bits Against Accumulator */
	ORA = 0x05, /* OR Accumulator with Memory */
	ASL = 0x06, /* Arithmetic Shift Left */
	ORA = 0x07, /* OR Accumulator with Memory */
	PHP = 0x08, /* Push Processor Status Register */
	ORA = 0x09, /* OR Accumulator with Memory */
	ASL = 0x0A, /* Arithmetic Shift Left */
	PHD = 0x0B, /* Push Direct Page Register */
	TSB = 0x0C, /* Test and Set Memory Bits Against Accumulator */
	ORA = 0x0D, /* OR Accumulator with Memory */
	ASL = 0x0E, /* Arithmetic Shift Left */
	ORA = 0x0F, /* OR Accumulator with Memory */
	BPL = 0x10, /* Branch if Plus */
	ORA = 0x11, /* OR Accumulator with Memory */
	ORA = 0x12, /* OR Accumulator with Memory */
	ORA = 0x13, /* OR Accumulator with Memory */
	TRB = 0x14, /* Test and Reset Memory Bits Against Accumulator */
	ORA = 0x15, /* OR Accumulator with Memory */
	ASL = 0x16, /* Arithmetic Shift Left */
	ORA = 0x17, /* OR Accumulator with Memory */
	CLC = 0x18, /* Clear Carry */
	ORA = 0x19, /* OR Accumulator with Memory */
	INC = 0x1A, /* Increment */
	TCS = 0x1B, /* Transfer 16-bit Accumulator to Stack Pointer */
	TRB = 0x1C, /* Test and Reset Memory Bits Against Accumulator */
	ORA = 0x1D, /* OR Accumulator with Memory */
	ASL = 0x1E, /* Arithmetic Shift Left */
	ORA = 0x1F, /* OR Accumulator with Memory */
	JSR = 0x20, /* Jump to Subroutine */
	AND = 0x21, /* AND Accumulator with Memory */
	JSR = 0x22, /* Jump to Subroutine */
	AND = 0x23, /* AND Accumulator with Memory */
	BIT = 0x24, /* Test Bits */
	AND = 0x25, /* AND Accumulator with Memory */
	ROL = 0x26, /* Rotate Memory or Accumulator Left */
	AND = 0x27, /* AND Accumulator with Memory */
	PLP = 0x28, /* Pull Processor Status Register */
	AND = 0x29, /* AND Accumulator with Memory */
	ROL = 0x2A, /* Rotate Memory or Accumulator Left */
	PLD = 0x2B, /* Pull Direct Page Register */
	BIT = 0x2C, /* Test Bits */
	AND = 0x2D, /* AND Accumulator with Memory */
	ROL = 0x2E, /* Rotate Memory or Accumulator Left */
	AND = 0x2F, /* AND Accumulator with Memory */
	BMI = 0x30, /* Branch if Minus */
	AND = 0x31, /* AND Accumulator with Memory */
	AND = 0x32, /* AND Accumulator with Memory */
	AND = 0x33, /* AND Accumulator with Memory */
	BIT = 0x34, /* Test Bits */
	AND = 0x35, /* AND Accumulator with Memory */
	ROL = 0x36, /* Rotate Memory or Accumulator Left */
	AND = 0x37, /* AND Accumulator with Memory */
	SEC = 0x38, /* Set Carry Flag */
	AND = 0x39, /* AND Accumulator with Memory */
	DEC = 0x3A, /* Decrement */
	TSC = 0x3B, /* Transfer Stack Pointer to 16-bit Accumulator */
	BIT = 0x3C, /* Test Bits */
	AND = 0x3D, /* AND Accumulator with Memory */
	ROL = 0x3E, /* Rotate Memory or Accumulator Left */
	AND = 0x3F, /* AND Accumulator with Memory */
	RTI = 0x40, /* Return from Interrupt */
	EOR = 0x41, /* Exclusive-OR Accumulator with Memory */
	WDM = 0x42, /* Reserved for Future Expansion */
	EOR = 0x43, /* Exclusive-OR Accumulator with Memory */
	MVP = 0x44, /* Block Move Positive */
	EOR = 0x45, /* Exclusive-OR Accumulator with Memory */
	LSR = 0x46, /* Logical Shift Memory or Accumulator Right */
	EOR = 0x47, /* Exclusive-OR Accumulator with Memory */
	PHA = 0x48, /* Push Accumulator */
	EOR = 0x49, /* Exclusive-OR Accumulator with Memory */
	LSR = 0x4A, /* Logical Shift Memory or Accumulator Right */
	PHK = 0x4B, /* Push Program Bank Register */
	JMP = 0x4C, /* Jump */
	EOR = 0x4D, /* Exclusive-OR Accumulator with Memory */
	LSR = 0x4E, /* Logical Shift Memory or Accumulator Right */
	EOR = 0x4F, /* Exclusive-OR Accumulator with Memory */
	BVC = 0x50, /* Branch if Overflow Clear */
	EOR = 0x51, /* Exclusive-OR Accumulator with Memory */
	EOR = 0x52, /* Exclusive-OR Accumulator with Memory */
	EOR = 0x53, /* Exclusive-OR Accumulator with Memory */
	MVN = 0x54, /* Block Move Negative */
	EOR = 0x55, /* Exclusive-OR Accumulator with Memory */
	LSR = 0x56, /* Logical Shift Memory or Accumulator Right */
	EOR = 0x57, /* Exclusive-OR Accumulator with Memory */
	CLI = 0x58, /* Clear Interrupt Disable Flag */
	EOR = 0x59, /* Exclusive-OR Accumulator with Memory */
	PHY = 0x5A, /* Push Index Register Y */
	TCD = 0x5B, /* Transfer 16-bit Accumulator to Direct Page Register */
	JMP = 0x5C, /* Jump */
	EOR = 0x5D, /* Exclusive-OR Accumulator with Memory */
	LSR = 0x5E, /* Logical Shift Memory or Accumulator Right */
	EOR = 0x5F, /* Exclusive-OR Accumulator with Memory */
	RTS = 0x60, /* Return from Subroutine */
	ADC = 0x61, /* Add With Carry */
	PER = 0x62, /* Push Effective PC Relative Indirect Address */
	ADC = 0x63, /* Add With Carry */
	STZ = 0x64, /* Store Zero to Memory */
	ADC = 0x65, /* Add With Carry */
	ROR = 0x66, /* Rotate Memory or Accumulator Right */
	ADC = 0x67, /* Add With Carry */
	PLA = 0x68, /* Pull Accumulator */
	ADC = 0x69, /* Add With Carry */
	ROR = 0x6A, /* Rotate Memory or Accumulator Right */
	RTL = 0x6B, /* Return from Subroutine Long */
	JMP = 0x6C, /* Jump */
	ADC = 0x6D, /* Add With Carry */
	ROR = 0x6E, /* Rotate Memory or Accumulator Right */
	ADC = 0x6F, /* Add With Carry */
	BVS = 0x70, /* Branch if Overflow Set */
	ADC = 0x71, /* Add With Carry */
	ADC = 0x72, /* Add With Carry */
	ADC = 0x73, /* Add With Carry */
	STZ = 0x74, /* Store Zero to Memory */
	ADC = 0x75, /* Add With Carry */
	ROR = 0x76, /* Rotate Memory or Accumulator Right */
	ADC = 0x77, /* Add With Carry */
	SEI = 0x78, /* Set Interrupt Disable Flag */
	ADC = 0x79, /* Add With Carry */
	PLY = 0x7A, /* Pull Index Register Y */
	TDC = 0x7B, /* Transfer Direct Page Register to 16-bit Accumulator */
	JMP = 0x7C, /* Jump */
	ADC = 0x7D, /* Add With Carry */
	ROR = 0x7E, /* Rotate Memory or Accumulator Right */
	ADC = 0x7F, /* Add With Carry */
	BRA = 0x80, /* Branch Always */
	STA = 0x81, /* Store Accumulator to Memory */
	BRL = 0x82, /* Branch Long Always */
	STA = 0x83, /* Store Accumulator to Memory */
	STY = 0x84, /* Store Index Register Y to Memory */
	STA = 0x85, /* Store Accumulator to Memory */
	STX = 0x86, /* Store Index Register X to Memory */
	STA = 0x87, /* Store Accumulator to Memory */
	DEY = 0x88, /* Decrement Index Register Y */
	BIT = 0x89, /* Test Bits */
	TXA = 0x8A, /* Transfer Index Register X to Accumulator */
	PHB = 0x8B, /* Push Data Bank Register */
	STY = 0x8C, /* Store Index Register Y to Memory */
	STA = 0x8D, /* Store Accumulator to Memory */
	STX = 0x8E, /* Store Index Register X to Memory */
	STA = 0x8F, /* Store Accumulator to Memory */
	BCC = 0x90, /* Branch if Carry Clear */
	STA = 0x91, /* Store Accumulator to Memory */
	STA = 0x92, /* Store Accumulator to Memory */
	STA = 0x93, /* Store Accumulator to Memory */
	STY = 0x94, /* Store Index Register Y to Memory */
	STA = 0x95, /* Store Accumulator to Memory */
	STX = 0x96, /* Store Index Register X to Memory */
	STA = 0x97, /* Store Accumulator to Memory */
	TYA = 0x98, /* Transfer Index Register Y to Accumulator */
	STA = 0x99, /* Store Accumulator to Memory */
	TXS = 0x9A, /* Transfer Index Register X to Stack Pointer */
	TXY = 0x9B, /* Transfer Index Register X to Index Register Y */
	STZ = 0x9C, /* Store Zero to Memory */
	STA = 0x9D, /* Store Accumulator to Memory */
	STZ = 0x9E, /* Store Zero to Memory */
	STA = 0x9F, /* Store Accumulator to Memory */
	LDY = 0xA0, /* Load Index Register Y from Memory */
	LDA = 0xA1, /* Load Accumulator from Memory */
	LDX = 0xA2, /* Load Index Register X from Memory */
	LDA = 0xA3, /* Load Accumulator from Memory */
	LDY = 0xA4, /* Load Index Register Y from Memory */
	LDA = 0xA5, /* Load Accumulator from Memory */
	LDX = 0xA6, /* Load Index Register X from Memory */
	LDA = 0xA7, /* Load Accumulator from Memory */
	TAY = 0xA8, /* Transfer Accumulator to Index Register Y */
	LDA = 0xA9, /* Load Accumulator from Memory */
	TAX = 0xAA, /* Transfer Accumulator to Index Register X */
	PLB = 0xAB, /* Pull Data Bank Register */
	LDY = 0xAC, /* Load Index Register Y from Memory */
	LDA = 0xAD, /* Load Accumulator from Memory */
	LDX = 0xAE, /* Load Index Register X from Memory */
	LDA = 0xAF, /* Load Accumulator from Memory */
	BCS = 0xB0, /* Branch if Carry Set */
	LDA = 0xB1, /* Load Accumulator from Memory */
	LDA = 0xB2, /* Load Accumulator from Memory */
	LDA = 0xB3, /* Load Accumulator from Memory */
	LDY = 0xB4, /* Load Index Register Y from Memory */
	LDA = 0xB5, /* Load Accumulator from Memory */
	LDX = 0xB6, /* Load Index Register X from Memory */
	LDA = 0xB7, /* Load Accumulator from Memory */
	CLV = 0xB8, /* Clear Overflow Flag */
	LDA = 0xB9, /* Load Accumulator from Memory */
	TSX = 0xBA, /* Transfer Stack Pointer to Index Register X */
	TYX = 0xBB, /* Transfer Index Register Y to Index Register X */
	LDY = 0xBC, /* Load Index Register Y from Memory */
	LDA = 0xBD, /* Load Accumulator from Memory */
	LDX = 0xBE, /* Load Index Register X from Memory */
	LDA = 0xBF, /* Load Accumulator from Memory */
	CPY = 0xC0, /* Compare Index Register Y with Memory */
	CMP = 0xC1, /* Compare Accumulator with Memory */
	REP = 0xC2, /* Reset Processor Status Bits */
	CMP = 0xC3, /* Compare Accumulator with Memory */
	CPY = 0xC4, /* Compare Index Register Y with Memory */
	CMP = 0xC5, /* Compare Accumulator with Memory */
	DEC = 0xC6, /* Decrement */
	CMP = 0xC7, /* Compare Accumulator with Memory */
	INY = 0xC8, /* Increment Index Register Y */
	CMP = 0xC9, /* Compare Accumulator with Memory */
	DEX = 0xCA, /* Decrement Index Register X */
	WAI = 0xCB, /* Wait for Interrupt */
	CPY = 0xCC, /* Compare Index Register Y with Memory */
	CMP = 0xCD, /* Compare Accumulator with Memory */
	DEC = 0xCE, /* Decrement */
	CMP = 0xCF, /* Compare Accumulator with Memory */
	BNE = 0xD0, /* Branch if Not Equal */
	CMP = 0xD1, /* Compare Accumulator with Memory */
	CMP = 0xD2, /* Compare Accumulator with Memory */
	CMP = 0xD3, /* Compare Accumulator with Memory */
	PEI = 0xD4, /* Push Effective Indirect Address */
	CMP = 0xD5, /* Compare Accumulator with Memory */
	DEC = 0xD6, /* Decrement */
	CMP = 0xD7, /* Compare Accumulator with Memory */
	CLD = 0xD8, /* Clear Decimal Mode Flag */
	CMP = 0xD9, /* Compare Accumulator with Memory */
	PHX = 0xDA, /* Push Index Register X */
	STP = 0xDB, /* Stop Processor */
	JMP = 0xDC, /* Jump */
	CMP = 0xDD, /* Compare Accumulator with Memory */
	DEC = 0xDE, /* Decrement */
	CMP = 0xDF, /* Compare Accumulator with Memory */
	CPX = 0xE0, /* Compare Index Register X with Memory */
	SBC = 0xE1, /* Subtract with Borrow from Accumulator */
	SEP = 0xE2, /* Reset Processor Status Bits */
	SBC = 0xE3, /* Subtract with Borrow from Accumulator */
	CPX = 0xE4, /* Compare Index Register X with Memory */
	SBC = 0xE5, /* Subtract with Borrow from Accumulator */
	INC = 0xE6, /* Increment */
	SBC = 0xE7, /* Subtract with Borrow from Accumulator */
	INX = 0xE8, /* Increment Index Register X */
	SBC = 0xE9, /* Subtract with Borrow from Accumulator */
	NOP = 0xEA, /* No Operation */
	XBA = 0xEB, /* Exchange B and A 8-bit Accumulators */
	CPX = 0xEC, /* Compare Index Register X with Memory */
	SBC = 0xED, /* Subtract with Borrow from Accumulator */
	INC = 0xEE, /* Increment */
	SBC = 0xEF, /* Subtract with Borrow from Accumulator */
	BEQ = 0xF0, /* Branch if Equal */
	SBC = 0xF1, /* Subtract with Borrow from Accumulator */
	SBC = 0xF2, /* Subtract with Borrow from Accumulator */
	SBC = 0xF3, /* Subtract with Borrow from Accumulator */
	PEA = 0xF4, /* Push Effective Absolute Address */
	SBC = 0xF5, /* Subtract with Borrow from Accumulator */
	INC = 0xF6, /* Increment */
	SBC = 0xF7, /* Subtract with Borrow from Accumulator */
	SED = 0xF8, /* Set Decimal Flag */
	SBC = 0xF9, /* Subtract with Borrow from Accumulator */
	PLX = 0xFA, /* Pull Index Register X */
	XCE = 0xFB, /* Exchange Carry and Emulation Flags */
	JSR = 0xFC, /* Jump to Subroutine */
	SBC = 0xFD, /* Subtract with Borrow from Accumulator */
	INC = 0xFE, /* Increment */
	SBC = 0xFF, /* Subtract with Borrow from Accumulator */
#endif /* Not implemented */

	OpCode_Count
} OpCode;




#endif /* SNES_OP_CODE_HEADER */
