#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <vector>
#include <utility>
#include <cstdint>
#include <map>
#include <stdexcept>


template<typename T>
class Array{
    private:
        uint32_t maxSize;
        uint32_t curSize;
        T* data;
    public:
        T& at(uint32_t ind){
            return data[ind];
        }
        T& operator[](uint32_t ind){
            return data[ind];
        }
        uint32_t size(){
            return curSize;
        }
        void reserve(uint32_t new_maxSize){
            delete[] data;
            maxSize = new_maxSize;
            data = new T[maxSize];
        }
        Array(){
            curSize = 0;
            maxSize = 1;
            data = new T[maxSize];
        }
        Array(uint32_t new_maxSize){
            curSize = 0;
            maxSize = new_maxSize;
            data = new T[maxSize];
        }
        ~Array(){
            delete[] data;
        }
};

#endif