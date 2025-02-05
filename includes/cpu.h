#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "bus.h"
#include "../lib/cJSON/cJSON.h"

typedef struct CPU {
    uint64_t regs[32];          // 32 64-bit registers (x0-x31)
    uint64_t pc;                // 64-bit program counter
    uint64_t csr[4069];
    struct BUS bus;             // CPU connected to BUS
    cJSON *state;
} CPU;

void cpu_init(struct CPU *cpu);
uint32_t cpu_fetch(struct CPU *cpu);
int cpu_execute(struct CPU *cpu, uint32_t inst);
void dump_registers(struct CPU *cpu); 
void dump_json(CPU* cpu);

#endif
