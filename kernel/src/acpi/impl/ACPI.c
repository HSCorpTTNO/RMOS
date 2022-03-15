#include <acpi/ACPI.h>

static acpi_xsdt_t* xsdt = NULL;
static acpi_madt_t* madt = NULL;

uint8_t checksum_valid(acpi_xsdt_t* table) {
    unsigned char checkum = 0;

    for (int i = 0; i < table->header.length; ++i) {
        checkum += ((char*)&table->header)[i];
    }

    return checkum == 0;
}
