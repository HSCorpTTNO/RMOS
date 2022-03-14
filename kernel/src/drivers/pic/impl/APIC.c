#include <drivers/pic/APIC.h>

uint16_t apic_supported() {
    uint32_t eax, ebx, ecx, edx;

    // Null out vars.
    eax = 0;
    ebx = 0;
    ecx = 0;
    edx = 0;

    // Grab CPUID EDX bit 9.
    cpuid_subleaf(1, 0, &eax, &ebx, &ecx, &edx);
    return (uint16_t)((edx >> 9) & 0x1);
}

void apic_init() {
    // Disable legacy PICs.
    outportb(0x21, 0xFF);
    outportb(0xA1, 0xFF);
}
