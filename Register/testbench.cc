#include <systemc.h>
#include "registerfile.H"
#include "config.H"

SC_MODULE(testbench){

    // To-Driven-Signal to DUT
    sc_signal< bool > clk;
    sc_signal< bool > rst;
    // read port
    sc_signal< sc_lv<ADDR_WIDTH> > rs1;
    sc_signal< sc_lv<ADDR_WIDTH> > rs2;
    sc_signal< sc_lv<DATA_WIDTH> > rdata1;
    sc_signal< sc_lv<DATA_WIDTH> > rdata2;
    // write port
    sc_signal< bool> wr;
    sc_signal< sc_lv<ADDR_WIDTH> > waddr;
    sc_signal< sc_lv<DATA_WIDTH> > wdata; 


    // store answer
    sc_lv<DATA_WIDTH> ans_registers[NUM_REG];

    // instantiate DUT
    RegisterFile *registerfile;

    void write_test(){
        
    }

    void read_test(){

    }

    SC_CTOR(testbench){
        registerfile = new RegisterFile("Register");
        registerfile->clk    (clk);
        registerfile->rst    (rst);
        registerfile->rs1    (rs1);
        registerfile->rs2    (rs2);
        registerfile->rdata1 (rdata1);
        registerfile->rdata2 (rdata2);
        registerfile->wr     (wr);
        registerfile->waddr  (waddr);
        registerfile->wdata  (wdata);
    }


    
};

int sc_main(){

}