#include <cstdint>
#include <intrin.h>

uint64_t sub_10C4() {
    return __readmsr(0xC0000082) - 0x1C0;
}