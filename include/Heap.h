#ifndef __HEAP_H__
#define __HEAP_H__

#include "../include/Pointer.h"
#include <vector>

class Heap{
    private:
        std::vector<ObjectReference*> vet;
    public:
        Heap() : vet(){

        }
        ~Heap(){
            for(auto p: vet){
                delete p;
            }
        }
        void push(ObjectReference* pointer){
            vet.push_back(pointer);
        }
        ObjectReference* at(uint32_t i){
            return vet[i-1];
        }
        uint32_t size(){
            return vet.size();
        }
};

#endif