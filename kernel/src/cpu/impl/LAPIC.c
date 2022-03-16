#include <cpu/LAPIC.h>

#define IA32_APIC_BASE_MSR_ENABLE 0x800
#define IA32_APIC_BASE_MSR 0x1B
#define IA32_APIC_BASE_MSR_BSP 0x100


static void* lapic_addr = NULL;


void lapic_set_addr(void* addr) {
    if (lapic_set_addr) return;
    lapic_addr = addr;
}



uint32_t cpu_lapic_read_reg(uint32_t reg) {
    volatile uint32_t* reg_addr = ((volatile uint32_t*)((uint64_t)lapic_addr) + reg);
    return *reg_addr;
}


void cpu_lapic_write_reg(uint32_t reg, uint32_t dword) {
    volatile uint32_t* reg_addr = ((volatile uint32_t*)((uint64_t)lapic_addr) + reg);
    *reg_addr = dword;
}


uint8_t cpu_lapic_init() { 
}
