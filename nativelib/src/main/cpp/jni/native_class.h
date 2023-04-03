//
// Created by lidawen on 2023/4/2.
//

#ifndef ANDROIDJNIDEMO_NATIVE_CLASS_H
#define ANDROIDJNIDEMO_NATIVE_CLASS_H

#include <vector>

class NativeClass {
public:
    int foo(const std::vector<uint8_t>& inData, std::vector<uint8_t>& outData);
};
#endif //ANDROIDJNIDEMO_NATIVE_CLASS_H
