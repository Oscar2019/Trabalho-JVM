#ifndef __CLASS_FILE_H__
#define __CLASS_FILE_H__

#include <cstdint>
#include "../include/ConstantPoolInfo.h"
#include "../include/FieldInfo.h"
#include "../include/MethodInfo.h"
#include "../include/AttributeInfo.h"
#include <stdexcept>


class ClassFormatError : public std::runtime_error{
    public:
        explicit ClassFormatError (const std::string& what_arg);
};
class UnsupportedClassVersionError : public std::runtime_error{
    public:
        explicit UnsupportedClassVersionError (const std::string& what_arg);
};

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
    /**
     * @brief 
     * 
     */
    ConstantPoolInfo **constantPool; 
    /**
     * @brief 
     * 
     */
    uint16_t accessFlags; 
    /**
     * @brief 
     * 
     */
    uint16_t thisClass;
    /**
     * @brief 
     * 
     */
    uint16_t superClass;
    /**
     * @brief 
     * 
     */
    uint16_t interfacesCount;
    /**
     * @brief 
     * 
     */
    uint16_t *interfaces;
    /**
     * @brief 
     * 
     */
    uint16_t fieldsCount;
    /**
     * @brief 
     * 
     */
    FieldInfo *fields;
    /**
     * @brief 
     * 
     */
    uint16_t methodsCount;
    /**
     * @brief 
     * 
     */
    MethodInfo *methods;
    /**
     * @brief 
     * 
     */
    uint16_t attributesCount;
    /**
     * @brief 
     * 
     */
    AttributeInfo **attributes;
    /**
     * @brief Construct a new Class File object
     * 
     */
    void addCPinfoInMethods();
    /**
     * @brief Construct a new Class File object
     * 
     */
    ClassFile();
    /**
     * @brief Destroy the Class File object
     * 
     */
    ~ClassFile();
};

/**
 * @brief Função que converte os atributos de um ClassFile para a estruturas mais elaboradas
 * 
 * 
 * @param cpi 
 * @param cf 
 */
void conveterAttributeInfoInClassFile(ConstantPoolInfo **cpi, ClassFile *cf);

#endif