#include <acpi/ACPI.h>

static acpi_xsdt_t* xsdt = NULL;

uint8_t checksum_valid(acpi_xsdt_t* table) {
    unsigned char checkum = 0;

    for (int i = 0; i < table->header.length; ++i) {
        checkum += ((char*)&table->header)[i];
    }

    return checkum == 0;
}


void init_acpi(struct stivale2_struct* ss) {    
    struct stivale2_struct_tag_rsdp* rsdp_tag = get_tag(ss, STIVALE2_STRUCT_TAG_RSDP_ID);
    acpi_xsdp_t* xsdp = (acpi_xsdp_t*)rsdp_tag->rsdp;

    if (xsdp->rev > 0) {
        xsdt = (acpi_xsdt_t*)xsdp->xsdt;
    } else {
        // TODO: Support legacy hardware.
        kwrite("\033[41;1;37mASCPI XSDP REVISION < 1. RASING ISR AT VECTOR 0x1\n\n");
        __asm__ __volatile__("int $0x0");
    }
}
