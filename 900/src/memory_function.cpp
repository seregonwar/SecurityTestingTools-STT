#include "memory_function.h"

__int64 callMemoryFunction(__int64 param) {
    extern __int64 (*MEMORY[0x45090])(__int64, __int64);
    return MEMORY[0x45090](param, 2);
}