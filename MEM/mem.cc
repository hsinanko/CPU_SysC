#include "mem.H"

void MEM::memory_read(){
    while(true){
        wait();
        if(mem_rd.read() == true){
                data_o.write(memory[addr.read().to_uint()]);
        }
            
    }

}

void MEM::memory_write(){
    while(true){
        wait();
        if(rst.read() == true){
            for(int i = 0; i < NUM_MEM; i++){
                memory[i] = "XXXXXXX";
            }
        }else{  
            // write operation
            if(mem_wr.read() == true){
                memory[addr.read().to_uint()] = data_i;
            }
        }

    }
}

