#include <cstdint>

int64_t sub_5(int64_t a1, int64_t a2, uint64_t *a3) {
    int64_t result = MEMORY[0x45168](a1, 4);
    if (result) {
        return 1;
    }

    int64_t v6 = *reinterpret_cast<int64_t *>(a2 + 0x20);
    if (v6 && (a2 + v6) != 0) {
        uint16_t v8 = *reinterpret_cast<uint16_t *>(a2 + 0x38);
        uint64_t v10 = 0;
        for (int v9 = 0; v9 < v8; ++v9) {
            int64_t v11 = v9 * *reinterpret_cast<uint16_t *>(a2 + 0x36);
            if (v10 < *reinterpret_cast<int64_t *>(a2 + v6 + v11 + 0x28) + *reinterpret_cast<int64_t *>(a2 + v6 + v11 + 0x18)) {
                v10 = *reinterpret_cast<int64_t *>(a2 + v6 + v11 + 0x28) + *reinterpret_cast<int64_t *>(a2 + v6 + v11 + 0x18);
            }
        }
    } else {
        uint16_t v12 = *reinterpret_cast<uint16_t *>(a2 + 0x3C);
        uint64_t v10 = 0;
        for (int v13 = 0; v13 < v12; ++v13) {
            int64_t v14 = *reinterpret_cast<int64_t *>(a2 + 0x28);
            if (!v14 || (a2 + v14) == 0) {
                // BUG() is undefined, replacing with appropriate error handling
                throw std::runtime_error("BUG: Invalid memory access");
            }
            int64_t v16 = v13 * *reinterpret_cast<uint16_t *>(a2 + 0x3A);
            if (v10 < *reinterpret_cast<int64_t *>(a2 + v14 + v16 + 0x20) + *reinterpret_cast<int64_t *>(a2 + v14 + v16 + 0x10)) {
                v10 = *reinterpret_cast<int64_t *>(a2 + v14 + v16 + 0x20) + *reinterpret_cast<int64_t *>(a2 + v14 + v16 + 0x10);
            }
        }
    }

    if (a3) {
        *a3 = v10;
    }
    return result;}
