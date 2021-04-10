#ifndef __THREAD_H__
#define __THREAD_H__

#include "../include/Frame.h"
#include "../include/Stack.h"

class Thread{
    private:
        DynamicStack<Frame*> frameStack;
        uint32_t pc;
    public:
        uint32_t& getPC(){
            return pc;
        }
        void pushFrameStack(Frame* frame){
            frameStack.push(frame);
        }
        Frame* topFrameStack(){
            return frameStack.top();
        };
        void popFrameStack(){
            frameStack.pop();
        }
        uint32_t sizeFrameStack(){
            return frameStack.size();
        }
};

#endif