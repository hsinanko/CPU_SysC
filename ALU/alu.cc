#include "alu.H"

void ALU::calculate(){
    while(true){
        wait();
        if(rst.read() == 1){
            zero.write(false);
        }else{
            // used by branch instruction
            zero.write(rdata1.read().to_uint() == rdata2.read().to_uint());
            // 
            sc_lv< OP_WIDTH > op;

            if(opcode.read() == R_TYPE) 
                op = funct.read().to_uint();
            else if(opcode.read() == LW || opcode.read() == SW) 
                op = ADD;
            else 
                op = opcode.read();

            switch(op.to_uint()){
                case ADD: case ADDI:
                    rout.write(rdata1.read().to_int() + rdata2.read().to_int());             // add two signed 32-bit integers
                    break;
                case ADDU: case ADDIU:
                    rout.write(rdata1.read().to_uint() + rdata2.read().to_uint());           // add two unsigned 32-bit integers
                    break;
                case AND: case ANDI:
                    rout.write(rdata1.read() & rdata2.read());                               // and bit operation
                    break;
                case DIV:
                    rout.write(rdata1.read().to_int() / rdata2.read().to_int());             // divide two signed 32-bit integers
                    break;
                case DIVU:
                    rout.write(rdata1.read().to_int() / rdata2.read().to_int());             // divide two unsigned 32-bit integers
                    break;
                //case JALR: break;
                //case JR: break;
                case NOR: 
                    rout.write(~(rdata1.read() | rdata2.read()));                            // NOT OR bitwise operation
                    break;
                case OR: case ORI:
                    rout.write(rdata1.read() | rdata2.read());                               // NOT OR bitwise operation
                    break;
                    break;
                case SLL:                                                                           // shift left arithmatically
                    rout.write(rdata1.read().to_uint() << rdata2.read().to_uint());
                    break;
                case SLLV:                                                                          // shift left arithmatically
                    rout.write(rdata1.read().to_uint() << rdata2.read().to_uint());
                    break;
                case SLT: 
                    rout.write(rdata1.read().to_int() < rdata2.read().to_int());            // set if (rs1 < rs2)
                    break;
                case SLTU:
                    rout.write(rdata1.read().to_uint() < rdata2.read().to_uint());
                    break;
                case SRA:                                                                           // shift right arithmatically
                    if(rdata1.read()[DATA_WIDTH-1] == 1)
                        rout.write((rdata1.read().to_int() >> rdata2.read().to_uint()));
                    else
                        rout.write((rdata1.read().to_uint() >> rdata2.read().to_uint()));
                    break;
                case SRAV:                                                                          // shift right arithmatically
                    if(rdata1.read()[DATA_WIDTH-1] == 1)
                        rout.write((rdata1.read().to_int() >> rdata2.read().to_uint()));
                    else
                        rout.write((rdata1.read().to_uint() >> rdata2.read().to_uint()));
                    break;       
                case SRL:
                    rout.write(rdata1.read().to_uint() >> rdata2.read().to_uint());         // shift right logically
                    break;
                case SRLV:
                    rout.write(rdata1.read().to_uint() >> rdata2.read().to_uint());         // shift right logically
                    break;
                case SUB:
                    rout.write(rdata1.read().to_int() - rdata2.read().to_int());            // sub two signed 32-bit integers
                    break;
                case SUBU:
                    rout.write(rdata1.read().to_uint() - rdata2.read().to_uint());          // sub two signed 32-bit integers
                    break;
                //case SYSCALL:    break;
                case XOR: case XORI:
                    rout.write(rdata1.read().to_uint() ^ rdata2.read().to_uint());          // xor two signed 32-bit integers
                    break;
                case LUI:
                    rout.write(rdata2.read() << 16);
                    break;
                case SLTI: 
                    rout.write((rdata1.read().to_int() < rdata2.read().to_int()));
                    break;
                case SLTIU:
                    rout.write((rdata1.read().to_uint() < rdata2.read().to_uint()));
                    break;

            }


        }
    }
}

void ALU::print_result(){
    cout << "rdata1 = " << rdata1 << " ,rdata2 = " << rdata2 << ", rout = " << rout << endl;
}