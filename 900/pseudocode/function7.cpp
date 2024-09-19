#include <cstdint>
bool sub_F79(int64_t a1) {
    uint8_t *v1 = reinterpret_cast<uint8_t *>(sub_14F1(a1));
    bool result = false;
    if (v1) {
        int v3 = sub_CEA(0x43418, v1, reinterpret_cast<int64_t>(sub_1520));
        if (sub_5(0, reinterpret_cast<int64_t>(v1), nullptr) || sub_14CF() == 0 || sub_26E(0, 0, reinterpret_cast<int64_t>(v1), v3, nullptr)) {
            MEMORY[0x45030](0);
            result = true;
        } else {
            result = v8[0]() != 0;
        }
    }
    return result;
}