#ifndef ACPI_H
#define ACPI_H

#include <acpi/tables.h>
#include <util/stivaleutil.h>


typedef enum {
    TABLE_XSDT,
    TABLE_RSDT
} table_type_t;


void init_acpi();
acpi_fadt_t* find_fadt();
uint8_t checksum_valid(void* table, table_type_t type);
#endif
