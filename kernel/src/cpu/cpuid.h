#ifndef CPUID_H
#define CPUID_H

#define CPUID_FLAG_MSR (1 << 5)

#include <stdint.h>

void cpuid_subleaf(uint32_t leaf, uint32_t subleaf, uint32_t* rax, uint32_t* rbx, uint32_t* rcx, uint32_t* rdx);

#endif
