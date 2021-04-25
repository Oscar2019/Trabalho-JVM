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


struct ArrayReference{
    uint32_t size;
    uint32_t dimensions;
    uint8_t tipo;
    ArrayReference(uint8_t new_tipo, uint8_t new_dimensions){
        size = 0;
        tipo = new_tipo;
    }
    virtual void createData(uint32_t size) = 0;
    virtual ~ArrayReference(){

    }
};

template<typename T>
struct ArrayType : virtual public ArrayReference{
    T *data;
    ArrayType(uint8_t new_tipo, uint8_t new_dimensions) : ArrayReference(new_tipo, new_dimensions){
        data = nullptr;
        dimensions = new_dimensions;
    }
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
    ~ArrayType(){
        if(data != nullptr){
            delete[] data;
        }
    }
};

struct ObjectReference{
    uint8_t *data;
    ClassFile *classFile;
    uint32_t metSize;
    MethodInfo **methods;
    ArrayReference* arrayReference;
    std::map<uint32_t, uint32_t*>* iterfaceMethodLocalization;
    uint32_t classNum;
    ObjectReference(){
        data = nullptr;
        classFile = nullptr;
        metSize = 0;
        methods = nullptr;
        arrayReference = nullptr;
        iterfaceMethodLocalization = nullptr;
        classNum = 0;
    }
    void createData(uint32_t new_size){
        if(data != nullptr){
            delete[] data;
        }
        if(new_size > 0){
            data = new uint8_t[new_size];
        }
        std::fill(data, data + new_size, 0);
    }
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