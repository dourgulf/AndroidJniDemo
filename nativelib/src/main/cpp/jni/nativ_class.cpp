//
// Created by lidawen on 2023/4/2.
//

#include "native_class.h"
#include <algorithm>
int NativeClass::foo(const std::vector<uint8_t>& inData, std::vector<uint8_t>& outData) {
    std::copy(inData.begin(), inData.end(), std::back_inserter(outData));
    return outData.size();
}

