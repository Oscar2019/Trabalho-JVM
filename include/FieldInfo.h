#ifndef __CLASS_FIELD_INFO_H__
#define __CLASS_FIELD_INFO_H__

#include <cstdint>
#include "../include/AttributeInfo.h"

struct FieldInfo{
    uint16_t accessFlags;
    uint16_t nameIndex;
    uint16_t descriptorIndex;
    uint16_t attributesCount;
    AttributeInfo **attributes;
    ~FieldInfo();
};

void conveterAttributeInfoInFieldInfo(ConstantPoolInfo **cf, FieldInfo *fi);

#endif