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
        static Frame* CreateFrame(MethodInfo* methodInfo){
            ConstantPoolInfo** cp = methodInfo->cp;
            for(uint32_t i = 0; i < methodInfo->attributesCount; i++){
                AttributeInfo* attributeInfo = methodInfo->attributes[i];
                std::string str = getStringFromCPInfo(cp, attributeInfo->attributeNameIndex);
                if(str == "Code"){
                    AttributeInfoCode *code = dynamic_cast<AttributeInfoCode*>(attributeInfo);
                    return new Frame(code->maxLocals, code->maxStack, cp);
                }
            }
            return nullptr;
        }
        ConstantPoolInfo** getConstantPool(){
            return constantPool;
        }
        Frame(uint32_t varTableSize, uint32_t operandStackSize, ConstantPoolInfo** currentConstantPool) : varLocalTable(varTableSize), operandStack(operandStackSize + 1), constantPool(currentConstantPool){
            operandStack.push(0);
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