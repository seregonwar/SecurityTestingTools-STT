#include <cstdint>
#include <stdexcept>

// Funzione per controllare la memoria
bool checkMemory(int64_t param1, int64_t param2) {
    if (param1 == 0 || param2 == 0) {
        throw std::invalid_argument("Invalid parameters");
    }

    extern uint64_t MEMORY[0x45240];
    uint64_t memoryValue = MEMORY[param1];

    if (memoryValue == 0) {
        return false;
    }

    return (memoryValue & param2) != 0;
}