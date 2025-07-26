#include "../config.H"

SC_MODULE(MEM){
    sc_in_clk clk;                      // clock signal
    sc_in< bool > rst;                  // reset signal, rise edge, synchronous
    sc_in< sc_lv<DATA_WIDTH> > addr;    // address for read / write
    sc_in< bool > mem_wr;               // memory write signal
    sc_in< sc_lv<DATA_WIDTH> > data_i;  // data needed to write
    sc_in< bool > mem_rd;               // memory read signal
    
    sc_out< sc_lv<DATA_WIDTH> >data_o;  // data readed from memory
    
    sc_lv<DATA_WIDTH> memory [NUM_MEM]; // memory function

    void memory_read_write();
    void print_memory();
    SC_CTOR(MEM){
        SC_CTHREAD(memory_read_write, clk);

    }

};