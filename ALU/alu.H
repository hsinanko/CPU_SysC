#include "../config.H"
#include "../opcode.H"
#include "../funct.H"

SC_MODULE(ALU){
    sc_in_clk                   clk;
    sc_in< bool >               rst;
    sc_in< sc_lv<OP_WIDTH> >    opcode;
    sc_in< sc_lv<FUNC_WDITH> >  funct;
    sc_in< sc_lv<DATA_WIDTH> >  rdata1;
    sc_in< sc_lv<DATA_WIDTH> >  rdata2;

    sc_out< sc_lv<DATA_WIDTH> > rout;
    sc_out< bool >              zero;


    void calculate();

    void print_result();

    SC_CTOR(ALU){
        SC_CTHREAD(calculate, clk.pos());

        SC_METHOD(print_result);
        sensitive << rout;
    }

};
