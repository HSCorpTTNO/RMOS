#include <IO/PICLegacy.h>

#define PIC1_COMMAND 0x20
#define PIC1_DATA 0x21
#define PIC2_COMMAND 0xA0
#define PIC2_DATA 0xA1

#define ICW1_INIT 0x10
#define ICW1_ICW4 0x01
#define ICW4_8086 0x01
#define PIC_EOI 0x20


void legacy_pic_init() { 
    // Init master PIC.
    outportb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
    io_wait();

    // Init slave PIC.
    outportb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
    io_wait();

    // Remap master PIC.
    outportb(PIC1_DATA, 0x20);
    io_wait();

    // Remap slave PIC.
    outportb(PIC2_DATA, 0x28);
    io_wait();

    outportb(PIC1_DATA, 4);
    io_wait();
    outportb(PIC2_DATA, 2);
    io_wait();

    outportb(PIC1_DATA, ICW4_8086);
    io_wait();
    outportb(PIC2_DATA, ICW4_8086);

    outportb(PIC1_DATA, 0xFF);
    io_wait();
    outportb(PIC2_DATA, 0xFF);

    // Unmask bitmasks we need.
}
