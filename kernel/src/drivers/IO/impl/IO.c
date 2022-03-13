#include "../IO.h"


void outportb(uint16_t port, uint8_t byte) {
    // Write one byte from a specific address on IO bus.
    __asm__ __volatile__("out %%al, %%dx" : : "a" (byte), "d" (port));
}


uint8_t inportb(uint16_t port) {
    // Read one byte from a specific address on IO bus.
    uint8_t byte;
    __asm__ __volatile__("in %%dx, %%al" : "=a" (byte) : "d" (port));
    return byte;
}


uint32_t inportl(uint16_t port) {
    uint32_t dword;
    __asm__ __volatile__("in %%dx, %%al" : "=a" (dword) : "d" (port));
    return dword;
}

uint32_t outportl(uint16_t port, uint32_t dword) {
    __asm__ __volatile__("out %%al, %%dx" : : "a" (dword), "d" (port));
}


void io_wait() {
    // Waste one IO cycle.
    __asm__ __volatile__("outb %%al, $0x80" : : "a" (0));
}
