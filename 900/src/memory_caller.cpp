#include <cstdint>
#include "memory_caller.h"

// Function to call memory functions
void callMemoryFunctions(int64_t param) {
    extern uint64_t MEMORY[0x45240];

    // Initialize the function at address 0x45030
    void (*memoryFunction)(int64_t) = reinterpret_cast<void(*)(int64_t)>(MEMORY[0x45030]);

    for (int i = 0; i < 18; ++i) {
        memoryFunction(param);
    }
}