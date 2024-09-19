#include <cstdint>
#include <intrin.h>

int64_t sub_F2B() {
    uint64_t v0 = __readcr0(); // Definisci __readcr0
    __writecr0(v0 & 0xFFFFFFFFFFFEFFFFui64); // Definisci __writecr0
    uint64_t v1 = sub_10C4(); // Definisci sub_10C4
    *reinterpret_cast<uint8_t *>(v1 + 0x2714BD) = 0xEB;
    uint8_t *v2 = reinterpret_cast<uint8_t *>(0x45140); // Fix MEMORY undefined error
    *reinterpret_cast<uint16_t *>(v1 + 0xB7B17) = 0x3BEB;
    *v2 = 0;
    *reinterpret_cast<uint8_t *>(v1 + 0x37BF3C) = 7;
    *reinterpret_cast<uint8_t *>(v1 + 0x37BF44) = 7;
    uint64_t v3 = __readcr0();
    int64_t result = v3 | 0x10000;
    __writecr0(result);
    return result;
}