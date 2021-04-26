#include "../include/ClassFile.h"
#include "../include/FieldInfo.h"
#include "../include/MethodInfo.h"

ClassFormatError::ClassFormatError(const std::string& what_arg) : runtime_error(what_arg){

}

UnsupportedClassVersionError::UnsupportedClassVersionError(const std::string& what_arg) : runtime_error(what_arg){

}

void conveterAttributeInfoInClassFile(ConstantPoolInfo **cpi, ClassFile *cf){
    for(uint32_t i = 0; i < cf->fieldsCount; i++){
        conveterAttributeInfoInFieldInfo(cpi, cf->fields + i); // Converte os atribudos do campo
    }
    for(uint32_t i = 0; i < cf->methodsCount; i++){
        conveterAttributeInfoInMethodInfo(cpi, cf->methods + i); // Converte os atribudos dos métodos
    }
    for(uint32_t i = 0; i < cf->attributesCount; i++){
        conveterAttributeInfoInAttributeInfo(cpi, cf->attributes + i); // Converte os atribudos do classFile
    }
}

ClassFile::ClassFile(){
    magic = 0;
    minorVersion = 0;
    majorVersion = 0;
    constantPoolCount = 0;
    constantPool = nullptr;
    accessFlags = 0;
    thisClass = 0;
    superClass = 0;
    interfacesCount = 0;
    interfaces = nullptr;
    fieldsCount = 0;
    fields = nullptr;
    methodsCount = 0;
    methods = nullptr;
    attributesCount = 0;
    attributes = nullptr;
}

ClassFile::~ClassFile(){
    for(uint32_t i = 1; i < constantPoolCount; i++){
        if(constantPool[i] != nullptr){
            delete constantPool[i];
        }
    }
    if(constantPoolCount > 0){
        delete[] constantPool;
    }
    if(interfacesCount > 0){
        delete[] interfaces;
    }
    if(fieldsCount > 0){
        delete[] fields;
    }
    if(methodsCount > 0){
        delete[] methods;
    }
    for(uint32_t i = 0; i < attributesCount; i++){
        delete attributes[i];
    }
    if(attributesCount > 0){
        delete[] attributes;
    }
}


void ClassFile::addCPinfoInMethods(){
    for(uint32_t i = 0; i < methodsCount; i++){
        methods[i].cp = constantPool;
    }
}