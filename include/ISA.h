#ifndef __ISA_H__
#define __ISA_H__

#include <functional>
#include <vector>
#include <cstdint>
#include <string>
#include "../include/ConstantPoolInfo.h"

extern const std::vector<std::function<uint32_t(const uint8_t*, uint32_t, uint32_t)>> qtdAttributes;
extern const std::vector<std::function<std::string(ConstantPoolInfo**, const uint8_t*, uint32_t, uint32_t)>> printMnemonic;

#endif