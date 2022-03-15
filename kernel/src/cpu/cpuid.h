#ifndef CPUID_H
#define CPUID_H

#define CPUID_FLAG_MSR (1 << 5)

#include <stdint.h>

void cpuid_subleaf(uint32_t leaf, uint32_t subleaf, uint32_t* eax, uint32_t* ebx, uint32_t* ecx, uint32_t* edx);

#endif
