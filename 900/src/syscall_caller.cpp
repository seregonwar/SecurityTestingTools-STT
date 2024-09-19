#include "syscall_caller.h"
#include "syscall_handler.h"

__int64 callSyscall(__int64 param1, __int64 param2) {
    return handleSyscall();
}