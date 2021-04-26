#ifndef __FRAME_H__
#define __FRAME_H__

#include "../include/Array.h"
#include "../include/Stack.h"
#include "../include/ConstantPoolInfo.h"
#include "../include/MethodInfo.h"

/**
 * @brief Representaçõ de um frame
 * 
 */
class Frame{
    private:
        /**
         * @brief Table de variáveis locais
         * 
         */
        Array<uint32_t> varLocalTable;
        /**
         * @brief Pilha de operandos
         * 
         */
        LinearStack<uint32_t> operandStack;
        /**
         * @brief Ponteiro para o constantPool
         * 
         */
        ConstantPoolInfo** constantPool;
    public:
        /**
         * @brief Cria um novo Frame
         * 
         * @param methodInfo 
         * @return Frame* 
         */
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
        /**
         * @brief Obtém o ConstantPool
         * 
         * @return ConstantPoolInfo** 
         */
        ConstantPoolInfo** getConstantPool(){
            return constantPool;
        }
        /**
         * @brief Constrói o Frame
         * 
         * @param varTableSize 
         * @param operandStackSize 
         * @param currentConstantPool 
         */
        Frame(uint32_t varTableSize, uint32_t operandStackSize, ConstantPoolInfo** currentConstantPool) : varLocalTable(varTableSize), operandStack(operandStackSize + 1), constantPool(currentConstantPool){
            operandStack.push(0);
        }
        /**
         * @brief Obtém uma referência para um elemnto da varLocalTable
         * 
         * @param ind 
         * @return uint32_t& 
         */
        uint32_t& varAt(uint32_t ind){
            return varLocalTable[ind];
        }
        /**
         * @brief Insere um elemento na pilha de operando.
         * 
         * @param value 
         */
        void pushOperandStack(uint32_t value){
            operandStack.push(value);
        }
        /**
         * @brief Obtém o elemento que está no topo da pilha
         * 
         * @return uint32_t 
         */
        uint32_t topOperandStack(){
            return operandStack.top();
        }
        /**
         * @brief Remove o elemento que está no topo da pilha
         * 
         * @return uint32_t 
         */
        void popOperandStack(){
            operandStack.pop();
        }
};

#endif