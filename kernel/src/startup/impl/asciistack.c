#include <startup/asciistack.h>


void print_stack(uint8_t* stack) {
    kwrite("(Addresses aren't accuarte but the data is actually coming from the stack.)\n");
    kwrite("ASCII ART BY IAN MARCO MOFFETT!\n\n");

    kwrite("<==== Stack ====>\n"); 
    kwrite(STACK_TOP);

    kwrite(STACK_C1);
    kwrite("    ");
    kwrite(hex2str(stack[0]));
    kwrite("\n");
    kwrite(STACK_C1B);

    kwrite(STACK_C2);
    kwrite("    ");
    kwrite(hex2str(stack[1]));
    kwrite("\n");
    kwrite(STACK_C2B);

    kwrite(STACK_C3);
    kwrite("    ");
    kwrite(hex2str(stack[2]));
    kwrite("\n");
    kwrite(STACK_C3B);

    kwrite(STACK_C4);
    kwrite("    ");
    kwrite(hex2str(stack[3]));
    kwrite("\n");
    kwrite(STACK_C4B);

    kwrite(STACK_C5);
    kwrite("    ");
    kwrite(hex2str(stack[4]));
    kwrite("\n");
    kwrite(STACK_C5B);
}
