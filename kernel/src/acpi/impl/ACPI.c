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


void init_acpi(struct stivale2_struct* ss) {
    struct stivale2_struct_tag_rsdp* rsdp_tag = get_tag(ss, STIVALE2_STRUCT_TAG_RSDP_ID);

    acpi_rsdp_t* rsdp = (acpi_rsdp_t*)rsdp_tag->rsdp;

    if (rsdp->rev != 0) {
        kwrite("\033[41;1;37mLEGACY HARDWARE IS NOT SUPPORTED YET. RASING ISR IN VECTOR 0x01.\n\n");
        __asm__ __volatile__("int $0x1");
    }

    acpi_rsdt_t* rsdt = (acpi_rsdt_t*)(uint64_t)rsdp->rsdtaddr;

    volatile unsigned short tableidx = 0;
    uint8_t apicFound = 0;

    while (tableidx < 10) {   
        acpi_madt_t* m = (acpi_madt_t*)(uint64_t)rsdt->tables[tableidx];
    
        if (strncmp(m->header.signature, "APIC", 4)) {
            apicFound = 1;
            madt = m;
            break;
        }

        ++tableidx;
    }
}
