#ifndef __CLASS_FILE_H__
#define __CLASS_FILE_H__

#include <cstdint>
#include "../include/ConstantPoolInfo.h"
#include "../include/FieldInfo.h"
#include "../include/MethodInfo.h"
#include "../include/AttributeInfo.h"

/**
 * @brief Strutura pra representar o .class.
 * 
 */
struct ClassFile{
    /**
     * @brief Número magico que define que o arquivo é um .class
     * 
     */
    uint32_t magic;
    /**
     * @brief 
     * 
     */
    uint16_t minorVersion; 
    /**
     * @brief 
     * 
     */
    uint16_t majorVersion; 
    /**
     * @brief Número de elementos no constant pool do .class
     * 
     */
    uint16_t constantPoolCount; 
    ConstantPoolInfo **constantPool; 
    uint16_t accessFlags; 
    uint16_t thisClass;
    uint16_t superClass;
    uint16_t interfacesCount;
    uint16_t *interfaces;
    uint16_t fieldsCount;
    FieldInfo *fields;
    uint16_t methodsCount;
    MethodInfo *methods;
    uint16_t attributesCount;
    AttributeInfo **attributes; 
    ~ClassFile();
};

void conveterAttributeInfoInClassFile(ConstantPoolInfo **cpi, ClassFile *cf);

#endif