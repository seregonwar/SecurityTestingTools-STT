#include <cstdint>

int64_t sub_35A(int *a1, int a2, uint8_t **a3, uint64_t a4) {
    int v4 = *a1;
    uint8_t *v5 = *a3;
    a1[1] -= a2;
    int64_t result = v4 & ((1 << a2) - 1);
    int v7 = v4 >> a2;
    bool v8 = a1[1] < 0;
    int v9 = 0;
    *a1 = v7;
    if (!v8) {
        v9 = a1[1];
    }
    while (true) {
        a1[1] = v9;
        int v10 = a1[1];
        if (reinterpret_cast<uint64_t>(v5) >= a4 || v10 > 0xF) {
            break;
        }
        int v11 = *v5++;
        int v12 = v11 << v10;
        v9 = v10 + 8;
        *a1 |= v12;
    }
    *a3 = v5;
    return result;
}