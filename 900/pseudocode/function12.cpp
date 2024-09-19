#include <cstdint>

int64_t sub_402(int a1, int a2, int64_t a3, int64_t a4, int a5) {
    int v51[16] = {0};
    int v52[174] = {0};

    for (int64_t k = 0; k < a5; ++k) {
        int v13 = *reinterpret_cast<uint8_t *>(a4 + k);
        ++v51[v13];
    }

    int v14 = 0;
    v52[1] = v51[0];
    for (int64_t v15 = 1; a2 > v15; ++v15) {
        int v16 = v51[v15];
        v14 = v16 + 2 * v14;
        v52[v15 + 1] = v16 + v52[v15];
    }

    int v17 = v51[a2] + 2 * v14;
    for (int64_t l = 0; l < a5; ++l) {
        int v19 = *reinterpret_cast<uint8_t *>(a4 + l);
        int v20 = v52[v19];
        reinterpret_cast<uint16_t *>(&v52[16])[v20] = l;
        v52[v19] = v20 + 1;
    }

    if ((1 << a2) <= v17) {
        int64_t v22 = 1;
        do {
            int v23 = v22++;
            int64_t result = v51[v22 - 1];
        } while (!result);

        int v24 = 1 << v23;
        int v25 = 0;
        uint16_t *v26 = reinterpret_cast<uint16_t *>(&v52[16]) + v52[0];
        while (a1 >= v23) {
            int v27 = v24 - 1;
            do {
                int v28 = *v26++;
                int64_t v29 = v25;
                *reinterpret_cast<int32_t *>(a3 + 4 * v25) = v23 | (v28 << 16);
                if (v27 == v25) {
                    while (a1 > v23) {
                        int64_t v30 = 4 * v24;
                        v24 *= 2;
                        ++v23;
                        MEMORY[0x45078](v29, v30, v26);
                    }
                    return result;
                }
                uint32_t v31 = 0x80000000 >> __lzcnt(v25 ^ v27);
                v25 = v31 | (v31 - 1) & v25;
                result = static_cast<uint32_t>(result - 1);
            } while (result);

            int64_t v32 = v23 + 1;
            do {
                v23 = v32;
                if (a1 >= v32) {
                    MEMORY[0x45078]();
                    v32 = v50;
                    v24 *= 2;
                    v26 = v48;
                }
                result = static_cast<uint32_t>(v51[v32++]);
            } while (!result);
        }

        int v33 = 1 << a1;
        uint16_t *v34 = v26;
        int v35 = 0xFFFFFFFF;
        int v49 = (1 << a1) - 1;
        int v36 = 0;
        while (true) {
            int v37 = v23 - a1;
            if ((v25 & v49) != v35) {
                int v38 = v37;
                for (int m = result; ; m = v51[a1 + v38] + 2 * m) {
                    char v40 = v38;
                    int v41 = 1 << v38++;
                    if (m >= v41) {
                        break;
                    }
                }
                *reinterpret_cast<int32_t *>(a3 + 4 * (v25 & v49)) = (v33 << 16) | (v40 & 0xF) | 0x10;
                v36 = v33;
                v35 = v25 & v49;
                v33 += v41;
            }
            int v42 = (v37 & 0xF) | (*v34 << 16);
            int64_t v43 = 1 << v37;
            int64_t v44 = v36 + (v25 >> a1);
            do {
                *reinterpret_cast<int32_t *>(a3 + 4 * v44) = v42;
                v44 += v43;
            } while (v33 > v44);

            int v45 = (1 << v23) - 1;
            if (v25 == v45) {
                break;
            }
            result = static_cast<uint32_t>(result - 1);
            uint32_t v46 = 0x80000000 >> __lzcnt(v25 ^ v45);
            int64_t v47 = v23;
            v25 = v46 | (v46 - 1) & v25;
            while (true) {
                v23 = v47++;
                if (result) {
                    break;
                }
                result = static_cast<uint32_t>(v51[v47]);
            }
            ++v34;
        }
    } else {
        int64_t result = 0;
        do {
            *reinterpret_cast<int32_t *>(a3 + 4 * result++) = 1;
        } while ((1 << a1) > result);
    }
    return result;
}