#include "../include/FieldInfo.h"

void conveterAttributeInfoInFieldInfo(ConstantPoolInfo **cf, FieldInfo *fi){
    for(uint32_t i = 0; i < fi->attributesCount; i++){
        conveterAttributeInfoInAttributeInfo(cf, fi->attributes + i);
    }
}

FieldInfo::~FieldInfo(){
    for(uint32_t i = 0; i < attributesCount; i++){
        delete attributes[i];
    }
    if(attributesCount > 0){
        delete[] attributes;
    }
}