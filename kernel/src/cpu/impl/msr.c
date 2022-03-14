#include <cpu/msr.h>


uint8_t msr_supported() {
    uint32_t eax, ebx, ecx, edx;
    cpuid_subleaf(1, 0, &eax, &ebx, &ecx, &edx);
    return edx & CPUID_FLAG_MSR;
}


void cpu_get_msr(uint32_t msr, uint32_t* low, uint32_t* high) {
    __asm__ __volatile__("rdmsr" : "=a" (*low), "=d" (*high) : "c" (msr));
}


void cpu_set_msr(uint32_t msr, uint32_t low, uint32_t high) {
    __asm__ __volatile__("wrmsr" : : "a" (low), "d" (high), "c" (msr));
}
