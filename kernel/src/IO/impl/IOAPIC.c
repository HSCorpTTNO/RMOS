#include <IO/IOAPIC.h>

static void* apic_base_addr = NULL;


void ioapic_set_addr(void* addr) {
    if (apic_base_addr) return;
    apic_base_addr = addr;
}



uint32_t ioapic_read_reg(const uint8_t OFFSET) {
    if (!(apic_base_addr)) __asm__ __volatile__("int $0xD");

    // Tell IOREGSEL where we wanna read.
    *(volatile uint32_t*)apic_base_addr = OFFSET;
    return *(volatile uint32_t*)(apic_base_addr + 0x10);
}


void ioapic_write_reg(const uint8_t OFFSET, const uint32_t VALUE) {
    *(volatile uint32_t*)apic_base_addr = OFFSET;
    *(volatile uint32_t*)(apic_base_addr + 0x10) = VALUE;
}
