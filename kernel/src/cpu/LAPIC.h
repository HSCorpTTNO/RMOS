#ifndef APIC_H
#define APIC_H

#define LAPIC_ID_REG 0x20
#define LAPIC_VERSION_REG 0x30
#define LAPIC_TASK_PRIORITY_REG 0x80
#define LAPIC_APR_REG 0x90
#define LAPIC_PROCESSOR_PRIORITY_REG 0xA0
#define LAPIC_EOI_REG 0xB0
#define LAPIC_RR_REG 0xC0
#define LAPIC_LOGICAL_DEST_REG 0xD0
#define LAPIC_DEST_FORMAT_REG 0xE0
#define LAPIC_SIV_REG 0xF0
#define LAPIC_ERROR_STATUS 0x280
#define LAPIC_LVT_TIMER_REG 0x320
#define LAPIC_LVT_THERMAL_SENSOR_REG 0x330
#define LAPIC_LVT_PMC_REG 0x340
#define LAPIC_LVT_LINT0_REG 0x350
#define LAPIC_LVT_LINT1_REG 0x360
#define LAPIC_LVT_ERROR_REG 0x370

#include <stddef.h>
#include <stdint.h>
#include <cpu/msr.h>
#include <cpu/cpuid.h>
#include <IO/IO.h>

// Sets static global variable defiend in APIC.c
void lapic_set_addr(void* addr);

// Allows you to read LAPIC MMIO register.
uint32_t cpu_lapic_read_reg(uint32_t reg);

// Allows you to write to a LAPIC MMIO register.
void cpu_lapic_write_reg(uint32_t reg, uint32_t dword);

uint8_t cpu_lapic_init();

#endif
