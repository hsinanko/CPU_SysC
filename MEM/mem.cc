#include "mem.H"

void MEM::memory_read_write(){
    while(true){
        wait();
        if(rst.read() == true){
            for(int i = 0; i < NUM_MEM; i++){
                memory[i] = 0x00000000;
            }
        }else{
            // read operation
            if(mem_rd.read() == true){
                data_o.write(memory[addr.read().to_uint()]);
            }
            
            // write operation
            if(mem_wr.read() == false){
                memory[addr.read().to_uint()] = data_i;
            }
        }

    }
}

