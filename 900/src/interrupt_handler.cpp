#include "interrupt_handler.h"

void handleInterrupt() {
    __asm { iret }
}