#ifndef __METHOD_AREA_H__
#define __METHOD_AREA_H__

#include "../include/Deleter.h"
#include <vector>

/**
 * @brief Representação da MethodArea
 * 
 */
class MethodArea{
    private:
        /**
         * @brief vetor node são armazenados os dados da method area
         * 
         */
        std::vector<DestructBase*> vet;
    public:
        /**
         * @brief Construtor de um new Method Area object
         * 
         */
        MethodArea() : vet(){

        }
        /**
         * @brief Desstrutor de um new Method Area object
         * 
         */
        ~MethodArea(){
            for(auto p: vet){
                delete p;
            }
        }
        /**
         * @brief Adiciona um novo obheto
         * 
         * @param pointer 
         */
        void push(DestructBase* pointer){
            vet.push_back(pointer);
        }
};

#endif