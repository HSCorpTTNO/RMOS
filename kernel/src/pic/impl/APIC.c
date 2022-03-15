#include <pic/APIC.h>


static void* lapic_addr = NULL;


void lapic_set_addr(void* addr) {
    if (lapic_set_addr) return;
    lapic_addr = addr;
}
