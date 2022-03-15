#include <cpu/cpuid.h>


inline void cpuid_subleaf(uint32_t leaf, uint32_t subleaf, uint32_t* eax, uint32_t* ebx, uint32_t* ecx, uint32_t* edx) {
    __asm__ __volatile__("cpuid":"=a"(*eax), "=b"(*ebx),
            "=c"(*ecx), "=d"(*edx)
            : "a" (leaf), "c" (subleaf)
            : "memory");
}
