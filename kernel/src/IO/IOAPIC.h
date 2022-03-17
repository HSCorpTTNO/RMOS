#ifndef IO_APIC_H
#define IO_APIC_H

#define IOAPICID  0x00
#define IOAPICVER 0x01
#define IOAPICARB 0x02

#include <stddef.h>
#include <stdint.h>

void ioapic_set_addr(void* addr);
uint32_t ioapic_read_reg(const uint8_t OFFSET);
void ioapic_write_reg(const uint8_t OFFSET, const uint32_t VALUE);

#endif
