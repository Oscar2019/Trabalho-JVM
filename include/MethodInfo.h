#ifndef __CLASS_METHOD_H__
#define __CLASS_METHOD_H__

#include <cstdint>
#include "../include/AttributeInfo.h"
#include "../include/ConstantPoolInfo.h"

/**
 * @brief Estrutura que armazena os dados de um método
 * 
 */
struct MethodInfo{
    ConstantPoolInfo **cp;
    /**
     * @brief Flag de acesso de método
     * 
     */
    uint16_t accessFlags;
    /**
     * @brief Índice que aponta para o vetor de ConstantPoolInfo* que aponta para um ponteiro de CPUtf8, onde fica armazenado o nome do método
     * 
     */
    uint16_t nameIndex;
    /**
     * @brief  Índice que aponta para o vetor de ConstantPoolInfo* que aponta para um ponteiro de CPUtf8, onde fica armazenado a descrição de tipo e argumentos do método
     * 
     */
    uint16_t descriptorIndex;
    /**
     * @brief Número de atribudos no método
     * 
     */
    uint16_t attributesCount;
    /**
     * @brief Ponteiro para um vetor de ponteiro de atributos
     * 
     */
    AttributeInfo **attributes;
    /**
     * @brief Construct a new Method Info object
     * 
     */
    MethodInfo();
    /**
     * @brief destrói os dados armazenados pelo MethodInfo
     * 
     */
    ~MethodInfo();

    AttributeInfo* getAttribute(std::string &attributeName);
    AttributeInfo* getAttribute(std::string &&attributeName);
};

/**
 * @brief Função que converte os atributos de um métodos para a estruturas mais elaboradas
 * 
 * @param cf 
 * @param mi 
 */
void conveterAttributeInfoInMethodInfo(ConstantPoolInfo **cf, MethodInfo *mi);

#endif