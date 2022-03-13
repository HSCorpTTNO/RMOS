#ifndef ASCII_STACK_H
#define ASCII_STACK_H

#include "../drivers/video/Framebuffer.h"
#include "../util/string.h"
#include <stdint.h>

#define STACK_TOP   "------------\n"
#define STACK_C1    "|          |    [0x4]\n"
#define STACK_C1B   "|----------|\n"
#define STACK_C2    "|          |    [0x3]\n"
#define STACK_C2B   "|----------|           |     Stack grows down! Remember that!\n"
#define STACK_C3    "|          |    [0x2] \\/\n"
#define STACK_C3B   "|----------|\n"
#define STACK_C4    "|          |    [0x1]\n"
#define STACK_C4B   "|----------|\n"
#define STACK_C5    "|          |    [0x0]\n"
#define STACK_C5B   "|----------|\n"

void print_stack(uint8_t* stack);


#endif
