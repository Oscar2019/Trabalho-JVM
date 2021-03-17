#ifndef __CLASS_METHOD_H__
#define __CLASS_METHOD_H__

#include <cstdint>
#include "../include/AttributeInfo.h"

struct MethodInfo{
    uint16_t accessFlags;
    uint16_t nameIndex;
    uint16_t descriptorIndex;
    uint16_t attributesCount;
    AttributeInfo **attributes;
    ~MethodInfo();
};

void conveterAttributeInfoInMethodInfo(ConstantPoolInfo **cf, MethodInfo *mi);

#endif