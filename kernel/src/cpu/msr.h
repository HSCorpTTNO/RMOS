#ifndef MSR_H
#define MSR_H

#include <cpu/cpuid.h>
#include <stdint.h>

#define IA32_APIC_BASE_MSR 0x1B
#define IA32_APIC_BASE_MSR_BSP 0x100    
#define IA32_APIC_BASE_MSR_ENABLE 0x800


uint8_t msr_supported();
void cpu_get_msr(uint32_t msr, uint32_t* low, uint32_t* high);
void cpu_set_msr(uint32_t msr, uint32_t low, uint32_t high);



#endif
