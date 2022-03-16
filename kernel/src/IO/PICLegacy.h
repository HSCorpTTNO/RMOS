#ifndef PIC_LEGACY_H
#define PIC_LEGACY_H

#include <IO/IO.h>

// This will be used if the hardware doesn't have APIC.
void legacy_pic_init();

#endif
