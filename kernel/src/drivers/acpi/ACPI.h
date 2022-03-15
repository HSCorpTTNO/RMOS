#ifndef ACPI_H
#define ACPI_H

#include <stdint.h>

typedef struct {
    char signature[8];
    uint8_t checksum;
    char OEMID[6];
    uint8_t rev;
    uint32_t rsdtaddr;
} __attribute__((packed)) acpi_rsdp_desc_t;


typedef struct {
    char signature[8];
    uint8_t checksum;
    char oem[6];
    uint8_t rev;
    uint32_t rsdt;
    uint32_t length;
    uint64_t xsdt;
    uint8_t extended_checksum;
} __attribute__((packed)) acpi_xsdp_t;


void init_setup_acpi();


#endif
