#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include "sysc/communication/sc_clock_ports.h"
#include "sysc/communication/sc_signal_ports.h"
#include "sysc/datatypes/bit/sc_lv.h"
#include "sysc/kernel/sc_module.h"
#include <systemc.h>
#include "../config.H"

SC_MODULE(RegisterFile){

	// inport
	sc_in_clk         clk;    // clock, positive sensitive
	sc_in<bool>       rst;	// reset signal, asynchronous
	sc_in<sc_lv<ADDR_WIDTH>>   rs1;	    // read address of register 1
	sc_in<sc_lv<ADDR_WIDTH>>   rs2;	    // read address of register 2
	sc_out<sc_lv<DATA_WIDTH>> rdata1;	// data in register 1
	sc_out<sc_lv<DATA_WIDTH>> rdata2;	// data in register 2
	sc_in<bool>       wr;       // read/write signal (rd = 0, wr = 1)
	sc_in<sc_lv<ADDR_WIDTH>>   waddr;    // write address
	sc_in<sc_lv<DATA_WIDTH>>  wdata;	// write data
	// outport



	// register

	sc_lv<DATA_WIDTH> registers[NUM_REG];
	/*=============== Function ========================*/


	// Read operation
	void read_write();	// read operation

	// print out function
	void print_info();

		// Constructor
	SC_CTOR(RegisterFile){

		SC_CTHREAD(read_write, clk.pos());
		reset_signal_is(rst, true);

		cout << "Constructed RegisterFile" << endl;

	}

};

#endif
