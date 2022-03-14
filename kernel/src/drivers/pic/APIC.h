#ifndef APIC_H
#define APIC_H

#define IA32_APIC_BASE_MSR 0x1B

#include <cpu/cpuid.h>
#include <drivers/IO/IO.h>

uint16_t apic_supported();
void apic_init();

#endif
