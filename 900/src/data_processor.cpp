#include <stdexcept>
#include "data_processor.h"
#include <cstdint>

__int64 processData(__int64 param1, __int64 param2) {
    int var1 = *(uint16_t *)(param1 + 0x3C);
    int var2 = 0;
    if (!*(uint16_t *)(param1 + 0x3C)) {
        return 0i64;
    }
    __int64 var3 = *(uint64_t *)(param1 + 0x28);
    if (!var3 || (param1 + var3) == 0) {
        throw std::runtime_error("BUG: Invalid memory access");
    }
    while (true) {
        __int64 var4 = var3 + var2 * *(uint16_t *)(param1 + 0x3A);
        if (*(uint32_t *)(var4 + 4) == 9) {
            __int64 var5 = 0i64;
            __int64 var6 = *(uint64_t *)(var4 + 0x20) / *(uint64_t *)(var4 + 0x38);
            while (var6 != var5) {
                __int64 var7 = 0x18 * var5 + param1 + *(uint64_t *)(var4 + 0x18);
                if (*(uint32_t *)(var7 + 8) == 8) {
                    *(uint64_t *)(param2 + *(uint64_t *)var7) = param2 + *(uint64_t *)(var7 + 0x10);
                }
                ++var5;
            }
        }
        if (var1 <= ++var2) {
            break;
        }
        __int64 var8 = *(uint64_t *)(param1 + 0x28);
        if (var8) {
            var3 = param1 + var8;
            if (param1 + var8) {
                continue;
            }
        } else {
            throw std::runtime_error("BUG: Invalid memory access");
        }
    }
    return 0i64;
}