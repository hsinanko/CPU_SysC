#include "registerfile.H"

void RegisterFile::read_write(){
    while(true){
        wait();
        if(rst.read()){
            // initialize registers to zero 
            for(int i = 0; i < NUM_REG; i++){
        	    registers[i] = 0;
    	    }
        }else if(wr.read()){ 
            // write the data to the address of register
            registers[waddr.read().to_uint()] = wdata.read();
        }else{
            // read data from the rs1 and rs2
            rdata1.write(registers[rs1.read().to_uint()]);
            rdata2.write(registers[rs2.read().to_uint()]);
        }
    }

}

void RegisterFile::print_info(){
    for(int i = 0; i < NUM_REG; i++){
        cout << "registers[" << i << "] = " << registers[i] << endl; 
    }
}