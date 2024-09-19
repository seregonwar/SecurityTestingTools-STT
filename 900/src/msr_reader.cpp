#include <cstdint>
#include <intrin.h>
#include "msr_reader.h"

// Function to read MSR
uint64_t readMSR() {
    return __readmsr(0xC0000082) - 0x1C0;
}