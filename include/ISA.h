#ifndef __ISA_H__
#define __ISA_H__

#include <functional>
#include <vector>
#include <cstdint>
#include <string>
#include "../include/ConstantPoolInfo.h"

/**
 * @brief Vetor constant de funçõs do tipo "uint32_t(const uint8_t*, uint32_t, uint32_t)" que retorna o número de bytes usado pela instrução.
 * 
 */
extern const std::vector<std::function<uint32_t(const uint8_t*, uint32_t, uint32_t)>> qtdAttributes;

/**
 * @brief Vetor constant de funçõs do tipo "std::string(ConstantPoolInfo**, const uint8_t*, uint32_t, uint32_t)" que retorna p mnemonoco da função.
 * 
 */
extern const std::vector<std::function<std::string(ConstantPoolInfo**, const uint8_t*, uint32_t, uint32_t)>> printMnemonic;

#endif