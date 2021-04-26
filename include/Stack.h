#ifndef __STACK_H__
#define __STACK_H__

#include <vector>
#include <utility>
#include <cstdint>
#include <map>
#include <stdexcept>


template<typename T>
class Stack{
    public:
        virtual void push(T&) = 0;
        virtual void push(T&&) = 0;
        virtual T& top() = 0;
        virtual void pop() = 0;
        virtual uint32_t size() = 0;
};

template<typename T>
class LinearStack : public Stack<T>{
    private:
        uint32_t maxSize;
        uint32_t curSize;
        T* data;
    public:
    void push(T& value){
        data[curSize] = value;
        curSize++;
    }
    void push(T&& value){
        data[curSize] = value;
        curSize++;
    }
    T& top(){
        return data[curSize - 1];
    }
    void pop(){
        curSize--;
    }
    uint32_t size(){
        return curSize;
    }
    void reserve(uint32_t new_maxSize){
        delete[] data;
        maxSize = new_maxSize;
        data = new T[maxSize];
    }
    LinearStack(){
        curSize = 0;
        maxSize = 1;
        data = new T[maxSize];
    }
    LinearStack(uint32_t new_maxSize){
        curSize = 0;
        maxSize = new_maxSize;
        data = new T[maxSize];
    }
    ~LinearStack(){
        delete[] data;
    }
};


template<typename T>
class DynamicStack : public Stack<T>{
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