#include <drivers/acpi/ACPI.h>

static uint8_t using_xsdt = 0; 
static acpi_rsdp_desc_t* rsdp = NULL;
static acpi_xsdt_desc_t* xsdt = NULL;

void init_setup_acpi(struct stivale2_struct* stivale2_struct, uint64_t id) {
    struct stivale2_struct_tag_rsdp* rsdp_tag = get_tag(stivale2_struct, STIVALE2_STRUCT_TAG_RSDP_ID);
    acpi_xsdt_desc_t* root = (acpi_xsdt_desc_t*)rsdp_tag->rsdp;

    // We can use XSDT since this hardware is not legacy!
    if (root->rev > 0) {
        using_xsdt = 1;
        xsdt = (acpi_xsdt_desc_t*)root->xsdt;
    } else {
        // This hardware is legacy and requires rsdp.
        rsdp = (acpi_rsdp_desc_t*)root->rsdt;
    }
}


