#ifndef __POINTER_H__
#define __POINTER_H__

#include <vector>
#include <utility>
#include <cstdint>
#include <map>
#include <stdexcept>
#include "../include/ClassFile.h"
#include "../include/Deleter.h"
#include "../include/MethodInfo.h"


/**
 * @brief Reprasentação de um Java array
 * 
 */
struct ArrayReference{
    /**
     * @brief Número de elementos máximos em um Java array
     * 
     */
    uint32_t size;
    /**
     * @brief Número de dimensões de um Java array
     * 
     */
    uint32_t dimensions;
    /**
     * @brief Tipo básico do Java array
     * 
     */
    uint8_t tipo;
    /**
     * @brief Construtor de um objeto ArrayReference
     * 
     * @param new_tipo 
     * @param new_dimensions 
     */
    ArrayReference(uint8_t new_tipo, uint8_t new_dimensions){
        size = 0;
        tipo = new_tipo;
    }
    /**
     * @brief Create um vetor de dados
     * 
     * @param size 
     */
    virtual void createData(uint32_t size) = 0;
    /**
     * @brief Destrutor de um objeto ArrayReference
     * 
     * @param new_tipo 
     * @param new_dimensions 
     */
    virtual ~ArrayReference(){

    }
};

/**
 * @brief Especialização de ArrayReference para algum tipo especifico de array
 * 
 * @tparam T 
 */
template<typename T>
struct ArrayType : virtual public ArrayReference{
    /**
     * @brief Vetor onde os dados do Java array são armazenados
     * 
     */
    T *data;
    /**
     * @brief Construtor de um objeto ArrayType
     * 
     * @param new_tipo 
     * @param new_dimensions 
     */
    ArrayType(uint8_t new_tipo, uint8_t new_dimensions) : ArrayReference(new_tipo, new_dimensions){
        data = nullptr;
        dimensions = new_dimensions;
    }
    /**
     * @brief Cria o vetor onde os dados do Java array são armazenados.
     * 
     * @param new_size 
     */
    void createData(uint32_t new_size){
        if(data != nullptr){
            delete[] data;
        }
        if(new_size > 0){
            data = new T[new_size];
        }
        size = new_size;
        std::fill(data, data + new_size, 0);
    }
    /**
     * @brief Destrutor de um objeto ArrayType
     * 
     */
    ~ArrayType(){
        if(data != nullptr){
            delete[] data;
        }
    }
};
/**
 * @brief representação de um Java objeto .
 * 
 */
struct ObjectReference{
    /**
     * @brief Dados dos fields do objeto.
     * 
     */
    uint8_t *data;
    /**
     * @brief ClassFile do objeto.
     * 
     */
    ClassFile *classFile;
    uint32_t metSize;
    /**
     * @brief Vector para permitir o acesso rápido dos métodos
     * 
     */
    MethodInfo **methods;
    /**
     * @brief Caso seja um vetor, apontará para um
     * 
     */
    ArrayReference* arrayReference;
    /**
     * @brief localizador de methodos na interface
     * 
     */
    std::map<uint32_t, uint32_t*>* iterfaceMethodLocalization;
    /**
     * @brief npymero da classe
     * 
     */
    uint32_t classNum;
    /**
     * @brief Construtor de um objeto ArrayType
     * 
     */
    ObjectReference(){
        data = nullptr;
        classFile = nullptr;
        metSize = 0;
        methods = nullptr;
        arrayReference = nullptr;
        iterfaceMethodLocalization = nullptr;
        classNum = 0;
    }
    /**
     * @brief Create p campo do fields do usuário
     * 
     * @param new_size 
     */
    void createData(uint32_t new_size){
        if(data != nullptr){
            delete[] data;
        }
        if(new_size > 0){
            data = new uint8_t[new_size];
        }
        std::fill(data, data + new_size, 0);
    }
    /**
     * @brief Create a Array Reference object
     * 
     * @param tipo 
     * @param dimensions 
     */
    void createArrayReference(uint8_t tipo, uint32_t dimensions){
        if(arrayReference != nullptr){
            delete[] arrayReference;
        }
        if(dimensions == 1){

            if(tipo == 'B'){
                arrayReference = new ArrayType<int8_t>(tipo, dimensions);
            } else if(tipo == 'C'){
                arrayReference = new ArrayType<uint16_t>(tipo, dimensions);
            } else if(tipo == 'D'){
                arrayReference = new ArrayType<double>(tipo, dimensions);
            } else if(tipo == 'F'){
                arrayReference = new ArrayType<float>(tipo, dimensions);
            } else if(tipo == 'I'){
                arrayReference = new ArrayType<int32_t>(tipo, dimensions);
            } else if(tipo == 'J'){
                arrayReference = new ArrayType<int64_t>(tipo, dimensions);
            } else if(tipo == 'S'){
                arrayReference = new ArrayType<int16_t>(tipo, dimensions);
            } else if(tipo == 'Z'){
                arrayReference = new ArrayType<int8_t>(tipo, dimensions);
            } else if(tipo == 'L'){
                arrayReference = new ArrayType<uint32_t>(tipo, dimensions);
            } else if(tipo == '['){
                arrayReference = new ArrayType<uint32_t>(tipo, dimensions);
            } 
        } else{
            arrayReference = new ArrayType<uint32_t>(tipo, dimensions);
        }
    }
    /**
     * @brief Destrutor de um objeto ObjectReference
     * 
     */
    ~ObjectReference(){
        if(data != nullptr){
            delete[] data;
        }
        if(arrayReference != nullptr){
            delete arrayReference;
        }
    }
};

#endif