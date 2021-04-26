#ifndef __STACK_H__
#define __STACK_H__

#include <vector>
#include <utility>
#include <cstdint>
#include <map>
#include <stdexcept>

/**
 * @brief Pilha alocada em forma de um vetor.
 * 
 * @tparam T 
 */
template<typename T>
class LinearStack{
    private:
        /**
         * @brief Número máximo de elementos na pilha
         * 
         */
        uint32_t maxSize;
        /**
         * @brief Número de elementos que atualmente está contido na pilha
         * 
         */
        uint32_t curSize;
        /**
         * @brief Vetor onde os elementos são armazenados
         * 
         */
        T* data;
    public:
        /**
         * @brief Insre um novo elemento para a pilha
         * 
         * @param value 
         */
        void push(T& value){
            data[curSize] = value;
            curSize++;
        }
        /**
         * @brief Insre um novo elemento para a pilha
         * 
         * @param value 
         */
        void push(T&& value){
            data[curSize] = value;
            curSize++;
        }
        /**
         * @brief Retorna uma referencia para o elemento que está no topo da pilha
         * 
         * @return T& 
         */
        T& top(){
            return data[curSize - 1];
        }
        /**
         * @brief Remove o elemento que está no topo da pilha.
         * 
         */
        void pop(){
            curSize--;
        }
        /**
         * @brief Retorna o número de elementos na pilha
         * 
         * @return uint32_t 
         */
        uint32_t size(){
            return curSize;
        }
        /**
         * @brief Muda a capacidade máxima da string
         * 
         * @param new_maxSize 
         */
        void reserve(uint32_t new_maxSize){
            delete[] data;
            maxSize = new_maxSize;
            data = new T[maxSize];
        }
        /**
         * @brief Construtor do objeto de LinearStack
         * 
         */
        LinearStack(){
            curSize = 0;
            maxSize = 1;
            data = new T[maxSize];
        }
        /**
         * @brief Construtor do objeto de LinearStack
         * 
         * @param new_maxSize 
         */
        LinearStack(uint32_t new_maxSize){
            curSize = 0;
            maxSize = new_maxSize;
            data = new T[maxSize];
        }
        /**
         * @brief Destrutor do objeto de LinearStack
         * 
         */
        ~LinearStack(){
            delete[] data;
        }
};


template<typename T>
class DynamicStack{
    private:
        struct Node{
            Node *nextNode;
            T value;
            Node(T& new_value, Node *new_nextNode = nullptr){
                value = new_value;
                nextNode = new_nextNode;
            }
        };
        uint32_t curSize;
        Node* node;
    public:
    void push(T& value){
        node = new Node(value, node);
        curSize++;
    }
    void push(T&& value){
        node = new Node(value, node);
        curSize++;
    }
    T& top(){
        return node->value;
    }
    void pop(){
        auto aux = node;
        node = node->nextNode;
        delete aux;
        curSize--;
    }
    uint32_t size(){
        return curSize;
    }
    DynamicStack(){
        curSize = 0;
        node = nullptr;
    }
    ~DynamicStack(){
        while(curSize != 0){
            pop();
        }
    }
};



#endif