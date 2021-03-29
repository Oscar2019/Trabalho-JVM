#include "../include/MethodInfo.h"

void conveterAttributeInfoInMethodInfo(ConstantPoolInfo **cf, MethodInfo *mi){
    for(uint32_t i = 0; i < mi->attributesCount; i++){
        conveterAttributeInfoInAttributeInfo(cf, mi->attributes + i); // converte cada atribudo do método
    }
}

MethodInfo::MethodInfo(){
    accessFlags = 0;
    nameIndex = 0;
    descriptorIndex = 0;
    attributesCount = 0;
    attributes = nullptr;
}

MethodInfo::~MethodInfo(){
    for(uint32_t i = 0; i < attributesCount; i++){
        delete attributes[i]; // deleta os atributos
    }
    if(attributesCount > 0){
        delete[] attributes; // deleta o vetor de atributos
    }
}