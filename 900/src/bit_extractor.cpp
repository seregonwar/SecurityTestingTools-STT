#include <cstdint>
#include "bit_extractor.h"

// Function to extract bits
int64_t extractBits(int *param1, int param2, uint8_t **param3, uint64_t param4) {
    int var1 = *param1;
    uint8_t *var2 = *param3;
    param1[1] -= param2;
    int64_t result = var1 & ((1 << param2) - 1);
    int var3 = var1 >> param2;
    bool var4 = param1[1] < 0;
    int var5 = 0;
    *param1 = var3;
    if (!var4) {
        var5 = param1[1];
    }
    while (true) {
        param1[1] = var5;
        int var6 = param1[1];
        if (reinterpret_cast<uint64_t>(var2) >= param4 || var6 > 0xF) {
            break;
        }
        int var7 = *var2++;
        int var8 = var7 << var6;
        var5 = var6 + 8;
        *param1 |= var8;
    }
    *param3 = var2;
    return result;
}