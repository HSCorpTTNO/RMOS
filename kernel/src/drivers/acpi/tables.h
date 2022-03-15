#ifndef TABLES_H
#define TABLES_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    char signature[8];
    uint8_t checksum;
    char OEMID[6];
    uint8_t rev;
    uint32_t rsdtaddr;
} __attribute__((packed)) acpi_rsdp;


typedef struct {
    char signature[8];
    uint8_t checksum;
    char oem[6];
    uint8_t rev;
    uint32_t rsdt;
    uint32_t length;
    uint64_t xsdt;
    uint8_t extended_checksum;
} __attribute__((packed)) acpi_xsdp;


typedef struct acpi_header_t {
    char signature[4];
    uint32_t length;
    uint8_t revision;
    uint8_t checksum;
    char oem[6];
    char oem_table[8];
    uint32_t oem_revision;
    uint32_t creator_id;
    uint32_t creator_revision;
} __attribute__((packed)) acpi_header_t;


typedef struct acpi_rsdt_t {
    acpi_header_t header;
    uint32_t tables[];
} __attribute__((packed)) acpi_rsdt_t;


typedef struct acpi_xsdt_t {
    acpi_header_t header;
    uint64_t tables[];
} __attribute__((packed)) acpi_xsdt_t;

#endif
