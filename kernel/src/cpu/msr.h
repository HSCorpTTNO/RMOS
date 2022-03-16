#ifndef MSR_H
#define MSR_H

#include <cpu/cpuid.h>
#include <stdint.h>


uint8_t msr_supported();
void cpu_get_msr(uint32_t msr, uint32_t* low, uint32_t* high);
void cpu_set_msr(uint32_t msr, uint32_t low, uint32_t high);



#endif
