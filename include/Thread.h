#ifndef __THREAD_H__
#define __THREAD_H__

#include "../include/Frame.h"
#include "../include/Stack.h"

/**
 * @brief Descreve um thread.
 * 
 */
class Thread{
    private:
        /**
         * @brief Pilha de frames;
         * 
         */
        DynamicStack<Frame*> frameStack;
        /**
         * @brief Contador do programa
         * 
         */
        uint32_t pc;
    public:
        /**
         * @brief Reporna uma referência pro contador de programa.
         * 
         * @return uint32_t& 
         */
        uint32_t& getPC(){
            return pc;
        }
        /**
         * @brief Adiciona um Frame na pilha de frames.
         * 
         * @param frame 
         */
        void pushFrameStack(Frame* frame){
            frameStack.push(frame);
        }
        /**
         * @brief Retorna o frame que está no topo da pilha de frames
         * 
         * @return Frame* 
         */
        Frame* topFrameStack(){
            return frameStack.top();
        };
        /**
         * @brief Remove o frame que está no topo da pilha de frames
         * 
         */
        void popFrameStack(){
            frameStack.pop();
        }
        /**
         * @brief Determina o tamanho da pilha de frames
         * 
         * @return uint32_t 
         */
        uint32_t sizeFrameStack(){
            return frameStack.size();
        }
};

#endif