#include "../exceptions.h"

void crapout(int_frame_t* frame, uint16_t vector) {
    __asm__ __volatile__("cli");
    kwrite("\n\033[41;1;37mFATAL CPU EXCEPTION: ");
    kwrite((char*)hex2str(vector));
    kwrite("\n*** KERNEL PANIC ***\n\n");
    kwrite("<==== INTERRUPT FRAME DUMP ====>\n\n");
    kwrite("RIP: ");
    kwrite((char*)hex2str(frame->rip));
    kwrite("\nCS: ");
    kwrite((char*)hex2str(frame->cs));
    kwrite("\nRFLAGS: ");
    kwrite((char*)hex2str(frame->rflags));
    kwrite("\nRSP: ");
    kwrite((char*)hex2str(frame->rsp));
    kwrite("\nSS: ");
    kwrite((char*)hex2str(frame->ss));
    kwrite("\n\n*** SYSTEM HALTED ***\n");

    __asm__ __volatile__("hlt");
}


void write_red() {
    kwrite("\033[41;1;37m");
}
