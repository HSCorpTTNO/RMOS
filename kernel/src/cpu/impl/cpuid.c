#include <cpu/cpuid.h>


inline void cpuid_subleaf(uint32_t leaf, uint32_t subleaf, uint32_t* rax, uint32_t* rbx, uint32_t* rcx, uint32_t* rdx) {
    __asm__ __volatile__("cpuid":"=a"(*rax), "=b"(*rbx),
            "=c"(*rcx), "=d"(*rdx)
            : "a" (leaf), "c" (subleaf)
            : "memory");
}
