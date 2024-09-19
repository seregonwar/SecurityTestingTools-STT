#include <cstdint>

int64_t sub_CEA(int a1, uint8_t *a2, int64_t a3) {
    uint32_t v5 = 0;
    uint32_t v6 = 1;
    uint32_t v7 = sub_6C5(a1, reinterpret_cast<uint8_t *>(a3 + 2));
    uint32_t v8 = v7;
    uint32_t v9 = static_cast<int>(v7) % 0x15B0;

    if (a1 <= 5) {
        return 0xFFFFFFFFi64;
    }

    int64_t _RBP = a3 + a1 - 4;

    while (v8) {
        uint8_t *v10 = a2;
        while (v9 > 7 - reinterpret_cast<int>(a2) + reinterpret_cast<int>(v10)) {
            int v11 = *v10;
            v10 += 8;
            int v12 = v6 + v11;
            int v13 = v12 + v10[-7];
            int v14 = v12 + v13;
            int v15 = v13 + v10[-6];
            int v16 = v15 + v10[-5];
            int v17 = v16 + v15 + v5 + v14;
            int v18 = v16 + v10[-4];
            int v19 = v18 + v10[-3];
            int v20 = v19 + v18 + v17;
            int v21 = v19 + v10[-2];
            v6 = v21 + v10[-1];
            v5 = v21 + v20 + v6;
        }
        uint32_t v22 = v9 & 0xFFFFFFF8;
        uint8_t *v23 = &a2[8 * (v9 >> 3)];
        for (int64_t i = 0; v9 > v22 + static_cast<uint32_t>(i); ++i) {
            int v25 = v23[i];
            v6 += v25;
            v5 += v6;
        }
        int64_t v26 = v9 - v22;
        if (v22 > v9) {
            v26 = 0;
        }
        v8 -= v9;
        a2 = &v23[v26];
        v9 = 0x15B0;
        v6 %= 0xFFF1u;
        v5 %= 0xFFF1u;
    }

    uint32_t _EDX;
    __asm { movbe edx, [rbp+0] }
    if (_EDX != (v5 << 0x10) + v6) {
        v7 = 0xFFFFFFFF;
    }
    return v7;
}