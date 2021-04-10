#ifndef __CLASS_FIELD_INFO_H__
#define __CLASS_FIELD_INFO_H__

#include <cstdint>
#include "../include/AttributeInfo.h"

/**
 * @brief Estrutura que armazena os dados de um campo
 * 
 */
struct FieldInfo{
    uint16_t accessFlags;
    /**
     * @brief Índice que aponta para o vetor de ConstantPoolInfo* que aponta para um ponteiro de CPUtf8, onde fica armazenado o nome do campo
     * 
     */
    uint16_t nameIndex;
    /**
     * @brief  Índice que aponta para o vetor de ConstantPoolInfo* que aponta para um ponteiro de CPUtf8, onde fica armazenado a descrição de tipo e argumentos do campo
     * 
     */
    uint16_t descriptorIndex;
    /**
     * @brief Número de atribudos no campo
     * 
     */
    uint16_t attributesCount;
    /**
     * @brief Ponteiro para um vetor de ponteiro de atributos
     * 
     */
    AttributeInfo **attributes;
    /**
     * @brief Construct a new Field Info object
     * 
     */
    FieldInfo();
    /**
     * @brief destrói os dados armazenados pelo FieldInfo
     * 
     */
    ~FieldInfo();
};

/**
 * @brief Função que converte os atributos de um campo para a estruturas mais elaboradas
 * 
 * @param cf 
 * @param mi 
 */
void conveterAttributeInfoInFieldInfo(ConstantPoolInfo **cf, FieldInfo *fi);

#endif