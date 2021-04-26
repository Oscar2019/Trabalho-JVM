#ifndef __RUNTIME_DATA_AREA_H__
#define __RUNTIME_DATA_AREA_H__

#include "../include/MethodArea.h"
#include "../include/Heap.h"
#include "../include/Thread.h"
#include "../include/Deleter.h"

/**
 * @brief Class que representa o RuntimeDataArea
 * 
 */
class RuntimeDataArea{
    private: 
        /**
         * @brief Thead do runtime data área
         * 
         */
        Thread tread;
        /**
         * @brief MethodArea do runtime data área
         * 
         */
        MethodArea methodArea;
        /**
         * @brief Heap do runtime data área
         * 
         */
        Heap heap;
    public:
        /**
         * @brief Adiciona um elemento na heap do RuntimeDataArea
         * 
         * @param pointer 
         */
        void pushHeap(ObjectReference* pointer){
            heap.push(pointer);
        }
        /**
         * @brief Adiciona um elemento na methodArea do RuntimeDataArea
         * 
         * @param pointer 
         */
        void pushMethodArea(DestructBase* pointer){
            methodArea.push(pointer);
        }
        /**
         * @brief Retorna o i-ésimo valor no var locals no elemento no topo da heap.
         * 
         * @param i 
         * @return ObjectReference* 
         */
        ObjectReference* objectAt(uint32_t i){
            return heap.at(i);
        }
        /**
         * @brief retorna o númeor de elementos na heap
         * 
         * @return uint32_t 
         */
        uint32_t heapSize(){
            return heap.size();
        }
        /**
         * @brief Obtém a thread do RuntimeDataArea.
         * 
         * @return Thread& 
         */
        Thread& getThread(){
            return tread;
        }
};

#endif