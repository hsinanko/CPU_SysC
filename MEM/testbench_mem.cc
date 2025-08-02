#include "../config.H"
#include "mem.H"
#include "sysc/communication/sc_clock.h"
#include "sysc/kernel/sc_module.h"
#include "sysc/kernel/sc_object.h"
#include "sysc/tracing/sc_trace.h"

SC_MODULE(testbench_mem){

    sc_in    < bool >              clk;
    sc_signal< bool >              rst;
    sc_signal< sc_lv<NUM_MEM> > addr;
    sc_signal< bool >              mem_wr;
    sc_signal< sc_lv<DATA_WIDTH> > data_i;
    sc_signal< bool >              mem_rd;
    sc_signal< sc_lv<DATA_WIDTH> > data_o;

    MEM *mem;

    void reset(){
        
    }
    void stimulus(){
        cout << "@" << sc_time_stamp() <<" Starting test"<<endl;
        wait();
        cout << "@" << sc_time_stamp() <<" Asserting reset"<<endl;
        rst = true; 
        mem_rd = false;
        mem_wr = false;
        addr   = "XXXXXXXX";
        data_i = "XXXX";
        wait(2);
        cout << "@" << sc_time_stamp() <<" De-Asserting reset"<<endl;
        rst = false; 
        wait(3);
        cout << "@" << sc_time_stamp() <<" Asserting Data input"<<endl;
        mem_rd = true; 
        addr   =  6;
        mem_wr = false;
        wait(3);
        mem_rd = false; 
        addr   = 0;
        mem_wr = false;
        cout << "@" << sc_time_stamp() <<" De-Asserting Data input"<<endl;
        wait(3);
        cout << "@" << sc_time_stamp() <<" Terminating simulation"<<endl;
        sc_stop();
    }

    SC_CTOR(testbench_mem){

        mem = new MEM("MEM");
        mem->clk(clk);
        mem->rst(rst);
        mem->addr(addr);
        mem->mem_wr(mem_wr);
        mem->data_i(data_i);
        mem->mem_rd(mem_rd);
        mem->data_o(data_o);
        SC_THREAD(stimulus);
        sensitive << clk.neg();        
    }
};

int sc_main(int argc, char* argv[]){
    sc_clock clk("clock",sc_time(10, SC_NS), 0.5, sc_time(0, SC_NS), false);
    testbench_mem testbench("testbench_mem");
    testbench.clk(clk);
    
    // generate VCD file
    sc_trace_file *waveform = sc_create_vcd_trace_file("mem_waveform");
        sc_trace(waveform, testbench.clk, "clk");
        sc_trace(waveform, testbench.rst, "rst");
        sc_trace(waveform, testbench.addr, "addr");
        sc_trace(waveform, testbench.mem_wr, "mem_wr");
        sc_trace(waveform, testbench.data_i, "data_i");
        sc_trace(waveform, testbench.mem_rd, "mem_rd");
        sc_trace(waveform, testbench.data_o, "data_o");
    
    sc_start(1000, SC_NS); 
    sc_close_vcd_trace_file(waveform);
    cout<<"Terminating Simulation"<<endl;
    return 0;// Terminate simulation

}

