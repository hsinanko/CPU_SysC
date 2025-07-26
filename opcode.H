#ifndef OPCODE_H
#define OPCODE_H

// Opcode (J-type)
#define J       0b000010
#define JAL     0b000011

// Opcode (I-type)
#define ADDI    0b001000
#define ADDIU   0b001001
#define ANDI    0b001100
#define ORI     0b001101
#define XORI    0b001110
#define LUI     0b001111
#define LW      0b100011
#define SW      0b101011
#define BEQ     0b000100
#define BNE     0b000101
#define SLTI    0b001010
#define SLTIU   0b001011


// Opcode (R-type)
#define R_TYPE  0b000000

#endif