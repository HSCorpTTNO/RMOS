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
    uint32_t eax, ebx, ecx, edx;
    cpuid_subleaf(1, 0, &eax, &ebx, &ecx, &edx);

    // TODO: Make this switch to legacy PIC instead of APIC if this condition is true.
    if (!(edx >> 9) & 0x1) {
        return 0;
    }

    // Mask all bits of 8259 PIC.
    outportb(0x21, 0xFF);
    outportb(0xA1, 0xFF);

    // LAPIC setup
    cpu_lapic_write_reg(LAPIC_TASK_PRIORITY_REG, 0);
    uint32_t msr_low;
    uint32_t msr_high;
    cpu_get_msr(IA32_APIC_BASE_MSR, &msr_low, &msr_high);       // Fetch current values of APIC MSR.
    cpu_set_msr(IA32_APIC_BASE_MSR, msr_low | IA32_APIC_BASE_MSR_ENABLE, msr_high);         // OR the current low values by IA32_APIC_BASE_MSR_ENABLE.
    outportb(0xF0, 0xFF);
    return 1;
}
