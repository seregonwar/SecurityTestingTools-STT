#include <cstdint>

int64_t sub_3A8(int *a1, int64_t a2, uint8_t **a3, uint64_t a4, char a5) {
    int v6 = *reinterpret_cast<int32_t *>(a2 + 4 * (*a1 & ((1 << a5) - 1)));
    if ((v6 & 0x10) != 0) {
        sub_35A(a1, a5, a3, a4);
        v6 = *reinterpret_cast<int32_t *>(a2 + 4 * ((*a1 & ((v6 << (*a1 & 0xF)) - 1)) + (v6 >> 16)));
    }
    sub_35A(a1, v6 & 0xF, a3, a4);
    return (v6 >> 16) & 0xFFF;
}