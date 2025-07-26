#include "../config.H"
#include "alu.H"

SC_MODULE(testbench_alu){
    sc_in_clk                   clk;
    sc_in< bool >               rst;
    sc_in< sc_lv<OP_WIDTH> >    opcode;
    sc_in< sc_lv<FUNC_WDITH> >  funct;
    sc_in< sc_lv<DATA_WIDTH> >  rdata1;
    sc_in< sc_lv<DATA_WIDTH> >  rdata2;

    sc_out< sc_lv<DATA_WIDTH> > rout;
    sc_out< bool >            zero;

    ALU *alu;

    SC_CTOR(testbench_alu){
        alu = new ALU("testbench");
        alu->clk(clk);
        alu->rst(rst);
        alu->opcode(opcode);
        alu->funct(funct);
        alu->rdata1(rdata1);
        alu->rdata2(rdata2);
        alu->rout(rout);
        alu->zero(zero);
    }
};

int sc_main(){

}