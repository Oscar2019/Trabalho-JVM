#ifndef __HEAP_H__
#define __HEAP_H__

#include "../include/Pointer.h"
#include <vector>

class Heap{
    private:
        std::vector<Pointer*> vet;
    public:
        Heap() : vet(){

        }
        ~Heap(){
            for(auto p: vet){
                delete p;
            }
        }
        void push(Pointer* pointer){
            vet.push_back(pointer);
        }
        Pointer* at(uint32_t i){
            return vet[i-1];
        }
        uint32_t size(){
            return vet.size();
        }
};

#endif