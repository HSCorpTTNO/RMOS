#include <drivers/cpu/cpuid.h>


inline void cpuid(int code, uint32_t* a, uint32_t* d) {
  __asm__ __volatile__("cpuid":"=a"(*a),"=d"(*d):"a"(code):"ecx","ebx");
}
