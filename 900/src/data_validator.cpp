#include <cstdint>
#include "data_validator.h"
#include "data_handler.h"

// Definizione delle funzioni esterne
extern "C" {
    int (*MEMORY[0x45168])(unsigned __int64, __int64);
    int sub_C8(__int64, __int64);
    int checkMemory(__int64, __int64, uint64_t *);
    int processData(__int64, __int64, __int64, int, uint64_t *);
}

// Function to validate data
bool validateData(int64_t param) {
    uint8_t *dataPtr = reinterpret_cast<uint8_t *>(MEMORY[0x45168](param, 4i64));
    bool result = false;
    if (dataPtr) {
        int temp = sub_C8(0x43418, reinterpret_cast<int64_t>(dataPtr));
        if (checkMemory(0, reinterpret_cast<int64_t>(dataPtr), nullptr) || MEMORY[0x45168](0, 0) == 0 || processData(0, 0, reinterpret_cast<int64_t>(dataPtr), temp, nullptr)) {
            MEMORY[0x45030](0, 0);
            result = true;
        } else {
            result = MEMORY[0x45078](0, 0) != 0;
        }
    }
    return result;
}