; Hard work all by Ian Marco Moffett.
; "Sometimes you don't notice the hard work people do." 
; - Ian.

global div0_handler
global debug_excp_handler
global breakpoint_handler
global overflow_handler
global bre_handler          ; Bound range exceeded
global invld_opcode_handler
global device_not_avail_handler
global double_fault_handler
global cso_handler                  ; Copressesor overrun.
global invalid_tss_handler
global snp_handler                  ; Segment not present.
global ssf_handler
global gpf_handler
global gpf_handler
global page_fault_handler
global fpe_handler              ; Floating point exception handler

extern kwrite
extern write_red
extern hex2str

%macro write_reg 1
    mov rdi, %1
    call kwrite

    pop rdi
    call hex2str
    mov rdi, rax
    call kwrite

    mov rdi, newline
    call kwrite
%endmacro

%macro panic 1
    call write_red
    mov rdi, exception_start
    call kwrite

    mov rdi, %1
    call hex2str
    mov rdi, rax
    call kwrite

    mov rdi, kernel_panic
    call kwrite

    mov rdi, int_dump_msg
    call kwrite

    write_reg __rip
    write_reg __cs
    write_reg __rflags
    write_reg __rsp
    write_reg __ss

    mov rdi, sys_halted
    call kwrite

    cli
    hlt
%endmacro

div0_handler:
    panic 0x0

debug_excp_handler:
    panic 0x1

breakpoint_handler:
    panic 0x3

overflow_handler:
    panic 0x4

bre_handler:
    panic 0x5

invld_opcode_handler:
    panic 0x6

device_not_avail_handler:
    panic 0x7

double_fault_handler:
    panic 0x7

cso_handler:
    panic 0x9

invalid_tss_handler:
    panic 0xA

snp_handler:
    panic 0xB

ssf_handler:
    panic 0xC

gpf_handler:
    panic 0xD

page_fault_handler:
    panic 0xE

fpe_handler:
    panic 0xF

exception_start: db 0x0D, 0x0A, "FATAL CPU EXCEPTION: ", 0
int_dump_msg: db 0xD, 0xA, "<==== Interrupt Frame Dump ====>", 0xD, 0xA, 0xD, 0xA, 0
newline: db 0x0D, 0x0A, 0
kernel_panic: db 0xD, 0xA, "*** KERNEL PANIC ***", 0xD, 0xA, 0xD, 0xA, 0
sys_halted: db 0xD, 0xA, "*** SYSTEM HALTED ***", 0xD, 0xA, 0xD, 0xA, 0

; STRING REP OF REGS
__rip: db "RIP: ", 0
__cs: db "CS: ", 0
__rflags: db "RFLAGS: ", 0
__rsp: db "RSP: ", 0
__ss: db "SS: ", 0
