#ifndef __METHOD_AREA_H__
#define __METHOD_AREA_H__

#include "../include/Deleter.h"
#include <vector>

class MethodArea{
    private:
        std::vector<DestructBase*> vet;
    public:
        MethodArea() : vet(){

        }
        ~MethodArea(){
            for(auto p: vet){
                delete p;
            }
        }
        void push(DestructBase* pointer){
            vet.push_back(pointer);
        }
};

#endif