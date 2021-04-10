#ifndef __FRAME_H__
#define __FRAME_H__

#include "../include/Array.h"
#include "../include/Stack.h"
#include "../include/ConstantPoolInfo.h"
#include "../include/MethodInfo.h"

class Frame{
    private:
        Array<uint32_t> varLocalTable;
        LinearStack<uint32_t> operandStack;
        ConstantPoolInfo** constantPool;
    public:
        Frame(uint32_t varTableSize, uint32_t operandStackSize, ConstantPoolInfo** currentConstantPool) : varLocalTable(varTableSize), operandStack(operandStackSize + 1), constantPool(currentConstantPool){
            operandStack.push(0);
        }
        ConstantPoolInfo** getConstantPool(){
            return constantPool;
        }
        uint32_t& varAt(uint32_t ind){
            return varLocalTable[ind];
        }
        void pushOperandStack(uint32_t value){
            operandStack.push(value);
        }
        uint32_t topOperandStack(){
            return operandStack.top();
        }
        void popOperandStack(){
            operandStack.pop();
        }
};

#endif