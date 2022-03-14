#ifndef CPUID_H
#define CPUID_H

#define CPUID_FLAG_MSR (1 << 5)

#include <stdint.h>


void cpuid(int code, uint32_t* a, uint32_t* d); 


#endif
