#include "syscall_handler.h"

__int64 handleSyscall() {
    __int64 result = 0;
    __asm { syscall; Low latency system call }
    return result;
}