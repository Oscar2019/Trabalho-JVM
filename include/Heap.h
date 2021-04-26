#ifndef __HEAP_H__
#define __HEAP_H__

#include "../include/Pointer.h"
#include <vector>

/**
 * @brief Representação de uma heap
 * 
 */
class Heap{
    private:
        /**
         * @brief vetor onde os objetos são armazenados
         * 
         */
        std::vector<ObjectReference*> vet;
    public:
        /**
         * @brief Construtor de um novo Heap object
         * 
         */
        Heap() : vet(){

        }
        /**
         * @brief Destrutor de um novo Heap object
         * 
         */
        ~Heap(){
            for(auto p: vet){
                delete p;
            }
        }
        /**
         * @brief Insere um novo Java objeto para a heap
         * 
         * @param pointer 
         */
        void push(ObjectReference* pointer){
            vet.push_back(pointer);
        }
        /**
         * @brief Retorna um objeto no indice i-1.
         * 
         * @param i 
         * @return ObjectReference* 
         */
        ObjectReference* at(uint32_t i){
            return vet[i-1];
        }
        /**
         * @brief Retorna o tamanho da pilha
         * 
         * 
         * @return uint32_t 
         */
        uint32_t size(){
            return vet.size();
        }
};

#endif