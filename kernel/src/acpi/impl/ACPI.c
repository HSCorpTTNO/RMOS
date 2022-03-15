#include <acpi/ACPI.h>

static acpi_xsdt_t* xsdt = NULL;
static acpi_rsdt_t* rsdt = NULL;
static uint16_t using_xsdt = 0;


void init_acpi(struct stivale2_struct* ss) {    
}


acpi_fadt_t* find_fadt() {
}
