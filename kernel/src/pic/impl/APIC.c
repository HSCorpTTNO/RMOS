#include <pic/APIC.h>

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

    // Preform CPUID to check for APIC support.
    cpuid_subleaf(1, 0, &eax, &ebx, &ecx, &edx);

    // Check if bit 32 of ecx is set.
    // If not, APIC is not supported.
    if (!((ecx >> 21) & 0x1)) {
        return 0;
    }

    // Disable 8259 PIC.
    outportb(0x21, 0xFF);
    outportb(0xA1, 0xFF);

    // Init APIC.
    cpu_lapic_write_reg(LAPIC_TASK_PRIORITY_REG, 0);
    cpu_set_msr(IA32_APIC_BASE_MSR, 1 << 11, 0x0);
    outportl(0xF0, 0xFF);       // To enable APIC set SIV reg to 0xFF.
}
