#include "data_handler.h"
#include <stdexcept>
#include <cstdint>

typedef uint64_t QWORD;
typedef uint16_t WORD;
extern "C" {
    int (*MEMORY[0x45168])(unsigned __int64, __int64);
    int checkMemory(__int64, __int64, QWORD *);
    int sub_C8(__int64, __int64);
    int processData(__int64, __int64);
}

__int64 handleData(__int64 param1, unsigned __int64 param2, __int64 param3, __int64 param4, QWORD *param5) {
    if (!param3) {
        return 1i64;
    }
    if (!param1 || !param4 || !param2 || (unsigned int)MEMORY[0x45168](param2, 4i64) || (*reinterpret_cast<WORD *>(param3 + 0x10) & 0xFFFD) != 1) {
        return 1i64;
    }
    int var1 = checkMemory(param1, param3, param5);
    if (var1 || *param5 <= param2) {
        int var2 = sub_C8(param1, param3);
        if (var2) {
            return 3i64;
        }
        int result = processData(param3, param1);
        if (result) {
            return 4i64;
        }
        if (param5) {
            *param5 = *reinterpret_cast<QWORD *>(param3 + 0x18) + param1;
        }
        return result;
    }
    return 2i64;
}