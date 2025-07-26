#ifndef CONFIG_H
#define CONFIG_H

#include <systemc.h>
#include "sysc/kernel/sc_module.h"

#define DATA_WIDTH 32                  // data width
#define ADDR_WIDTH 5                   // address width
#define NUM_REG    (1 << ADDR_WIDTH)   // how many register 

#define OP_WIDTH   6                   // opcode width
#define FUNC_WDITH 6                   // funct width


#endif
