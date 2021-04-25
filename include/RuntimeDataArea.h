#ifndef __RUNTIME_DATA_AREA_H__
#define __RUNTIME_DATA_AREA_H__

#include "../include/MethodArea.h"
#include "../include/Heap.h"
#include "../include/Thread.h"
#include "../include/Deleter.h"

class RuntimeDataArea{
    private: 
        Thread tread;
        MethodArea methodArea;
        Heap heap;
    public:
        void pushHeap(ObjectReference* pointer){
            heap.push(pointer);
        }
        void pushMethodArea(DestructBase* pointer){
            methodArea.push(pointer);
        }
        ObjectReference* objectAt(uint32_t i){
            return heap.at(i);
        }
        uint32_t heapSize(){
            return heap.size();
        }
        Thread& getThread(){
            return tread;
        }
};

#endif