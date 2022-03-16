#ifndef ACPI_H
#define ACPI_H

#include <acpi/tables.h>
#include <util/stivaleutil.h>
#include <util/string.h>
#include <drivers/video/Framebuffer.h>
#include <cpu/LAPIC.h>


void init_acpi(struct stivale2_struct* ss);
uint8_t checksum_valid(acpi_xsdt_t* table);
#endif
