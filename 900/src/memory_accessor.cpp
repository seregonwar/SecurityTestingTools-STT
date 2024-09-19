#include "memory_accessor.h"

__int64 accessMemory() {
    extern __int64 (*MEMORY[0x45028])();
    return MEMORY[0x45028]();
}