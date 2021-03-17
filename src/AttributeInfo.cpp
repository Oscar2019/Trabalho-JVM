#include "../include/AttributeInfo.h"
#include "../include/ConstantPoolInfo.h"
#include "../include/Tipos.h"

void conveterAttributeInfoInAttributeInfo(ConstantPoolInfo **cp, AttributeInfo **ai){
    std::string str = getCPUtf8(cp, (*ai)->attributeNameIndex);
    AttributeInfoBasic *aib = (AttributeInfoBasic*)*ai;
    if(str == "ConstantValue"){
        AttributeInfoConstantValue *nAi = new AttributeInfoConstantValue;
        nAi->attributeNameIndex = aib->attributeNameIndex;
        nAi->attributeLength = aib->attributeLength;
        nAi->constantvalueIndex = read<uint16_t>(aib->info);
        delete aib;
        *ai = dynamic_cast<AttributeInfo*>(nAi);
    } else if(str == "Code"){
        AttributeInfoCode *nAi = new AttributeInfoCode;
        uint32_t offset = 0;
        nAi->attributeNameIndex = aib->attributeNameIndex;
        nAi->attributeLength = aib->attributeLength;
        nAi->maxStack = read<uint16_t>(aib->info + offset); offset+=2;
        nAi->maxLocals = read<uint16_t>(aib->info + offset); offset+=2;
        nAi->codeLength = read<uint32_t>(aib->info + offset); offset+=4;
        if(nAi->codeLength > 0){
            nAi->code = new uint8_t[nAi->codeLength];
            for(uint32_t i = 0; i < nAi->codeLength; i++){
                nAi->code[i] = read<uint8_t>(aib->info + offset); offset+=1;
            }
        }
        nAi->exceptionTableLength = read<uint16_t>(aib->info + offset); offset+=2;
        if(nAi->exceptionTableLength > 0){
            nAi->exceptionTable = new AttributeInfoCode::ExceptionTable[nAi->exceptionTableLength];
            for(uint32_t i = 0; i < nAi->exceptionTableLength; i++){
                nAi->exceptionTable[i].startPc = read<uint16_t>(aib->info + offset); offset+=2;
                nAi->exceptionTable[i].endPc = read<uint16_t>(aib->info + offset); offset+=2;
                nAi->exceptionTable[i].handlerPc = read<uint16_t>(aib->info + offset); offset+=2;
                nAi->exceptionTable[i].catchType = read<uint16_t>(aib->info + offset); offset+=2;
            }
        }
        nAi->attributesCount = read<uint16_t>(aib->info + offset); offset+=2;
        if(nAi->attributesCount > 0){
            nAi->attributes = new AttributeInfo*[nAi->attributesCount];
            for(uint32_t i = 0; i < nAi->attributesCount; i++){
                nAi->attributes[i] = new AttributeInfoBasic;
                AttributeInfoBasic *iAi = dynamic_cast<AttributeInfoBasic*>(nAi->attributes[i]);
                iAi->attributeNameIndex = read<uint16_t>(aib->info + offset); offset+=2;
                iAi->attributeLength = read<uint32_t>(aib->info + offset); offset+=4;
                if(iAi->attributeLength > 0){
                    iAi->info = new uint8_t[iAi->attributeLength];
                    for(uint32_t j = 0; j < iAi->attributeLength; j++){
                        iAi->info[j] = read<uint8_t>(aib->info + offset); offset+=1;
                    }
                }
                conveterAttributeInfoInAttributeInfo(cp, nAi->attributes + i);
            }
        }
        delete aib;
        *ai = dynamic_cast<AttributeInfo*>(nAi);
    } else if(str == "Exceptions"){
        AttributeInfoExceptions *nAi = new AttributeInfoExceptions;
        uint32_t offset = 0;
        nAi->attributeNameIndex = aib->attributeNameIndex;
        nAi->attributeLength = aib->attributeLength;
        nAi->numberOfExceptions = read<uint16_t>(aib->info + offset); offset += 2;
        if(nAi->numberOfExceptions > 0){
            nAi->exceptionIndexTable = new uint16_t[nAi->numberOfExceptions];
            for(int32_t i = 0; i < nAi->numberOfExceptions; i++){
                nAi->exceptionIndexTable[i] = read<uint16_t>(aib->info + offset); offset += 2;
            }
        }
        delete aib;
        *ai = dynamic_cast<AttributeInfo*>(nAi);
    } else if(str == "InnerClasses"){
        AttributeInfoInnerClasses *nAi = new AttributeInfoInnerClasses;
        uint32_t offset = 0;
        nAi->attributeNameIndex = aib->attributeNameIndex;
        nAi->attributeLength = aib->attributeLength;
        nAi->numberOfClasses = read<uint16_t>(aib->info + offset); offset += 2;
        if(nAi->numberOfClasses > 0){
            nAi->classes = new AttributeInfoInnerClasses::Class[nAi->numberOfClasses];
            for(int32_t i = 0; i < nAi->numberOfClasses; i++){
                nAi->classes[i].innerClassInfoIndex = read<uint16_t>(aib->info + offset); offset += 2;
                nAi->classes[i].outerClassInfoIndex = read<uint16_t>(aib->info + offset); offset += 2;
                nAi->classes[i].innerNameIndex = read<uint16_t>(aib->info + offset); offset += 2;
                nAi->classes[i].innerClassAccessFlags = read<uint16_t>(aib->info + offset); offset += 2;
            }
        }
        delete aib;
        *ai = dynamic_cast<AttributeInfo*>(nAi);
    } else if(str == "Synthetic"){
        AttributeInfoSynthetic *nAi = new AttributeInfoSynthetic;
        nAi->attributeNameIndex = aib->attributeNameIndex;
        nAi->attributeLength = aib->attributeLength;
        delete aib;
        *ai = dynamic_cast<AttributeInfo*>(nAi);
    } else if(str == "SourceFile"){
        AttributeInfoSourceFile *nAi = new AttributeInfoSourceFile;
        uint32_t offset = 0;
        nAi->attributeNameIndex = aib->attributeNameIndex;
        nAi->attributeLength = aib->attributeLength;
        nAi->sourcefileIndex = read<uint16_t>(aib->info + offset);
        delete aib;
        *ai = dynamic_cast<AttributeInfo*>(nAi);
    } else if(str == "LineNumberTable"){
        AttributeInfoLineNumberTable *nAi = new AttributeInfoLineNumberTable;
        uint32_t offset = 0;
        nAi->attributeNameIndex = aib->attributeNameIndex;
        nAi->attributeLength = aib->attributeLength;
        nAi->lineNumberTableLength = read<uint16_t>(aib->info + offset); offset += 2;
        if(nAi->lineNumberTableLength > 0){
            nAi->lineNumberTable = new AttributeInfoLineNumberTable::LineNumberTable[nAi->lineNumberTableLength];
            for(int32_t i = 0; i < nAi->lineNumberTableLength; i++){
                nAi->lineNumberTable[i].startPc = read<uint16_t>(aib->info + offset); offset += 2;
                nAi->lineNumberTable[i].lineNumber = read<uint16_t>(aib->info + offset); offset += 2;
            }
        }
        delete aib;
        *ai = dynamic_cast<AttributeInfo*>(nAi);
    } else if(str == "LocalVariableTable"){
        AttributeInfoLocalVariableTable *nAi = new AttributeInfoLocalVariableTable;
        uint32_t offset = 0;
        nAi->attributeNameIndex = aib->attributeNameIndex;
        nAi->attributeLength = aib->attributeLength;
        nAi->localVariableTableLength = read<uint16_t>(aib->info + offset); offset += 2;
        if(nAi->localVariableTableLength > 0){
            nAi->localVariableTable = new AttributeInfoLocalVariableTable::LocalVariableTable[nAi->localVariableTableLength];
            for(int32_t i = 0; i < nAi->localVariableTableLength; i++){
                nAi->localVariableTable[i].startPc = read<uint16_t>(aib->info + offset); offset += 2;
                nAi->localVariableTable[i].length = read<uint16_t>(aib->info + offset); offset += 2;
                nAi->localVariableTable[i].nameIndex = read<uint16_t>(aib->info + offset); offset += 2;
                nAi->localVariableTable[i].descriptorIndex = read<uint16_t>(aib->info + offset); offset += 2;
                nAi->localVariableTable[i].index = read<uint16_t>(aib->info + offset); offset += 2;
            }
        }
        delete aib;
        *ai = dynamic_cast<AttributeInfo*>(nAi);
    } else if(str == "Deprecated"){
        AttributeInfoSynthetic *nAi = new AttributeInfoSynthetic;
        nAi->attributeNameIndex = aib->attributeNameIndex;
        nAi->attributeLength = aib->attributeLength;
        delete aib;
        *ai = dynamic_cast<AttributeInfo*>(nAi);
    } 
    // else if(str == "StackMapTable"){
    // } 
    // else if(str == "EnclosingMethod"){
    // } 
    // else if(str == "Signature"){
    // } 
    // else if(str == "SourceDebugExtension"){
    // } 
    // else if(str == "LocalVariableTypeTable"){
    // } 
    // else if(str == "RuntimeVisibleAnnotations"){
    // } 
    // else if(str == "RuntimeInvisibleAnnotations"){
    // } 
    // else if(str == "RuntimeVisibleParameterAnnotations"){
    // } 
    // else if(str == "RuntimeInvisibleParameterAnnotations"){
    // } 
    // else if(str == "RuntimeVisibleTypeAnnotations"){
    // } 
    // else if(str == "RuntimeInvisibleTypeAnnotations"){
    // } 
    // else if(str == "AnnotationDefault"){
    // } 
    // else if(str == "BootstrapMethods"){
    // } 
    // else if(str == "MethodParameters"){
    // } 
}

AttributeInfo::~AttributeInfo(){
}

AttributeInfoBasic::~AttributeInfoBasic(){
    if(attributeLength > 0){
        delete[] info;
    }
}

AttributeInfoCode::~AttributeInfoCode(){
    if(codeLength > 0){
        delete[] code;
    }
    if(exceptionTableLength > 0){
        delete[] exceptionTable;
    }
    for(uint32_t i = 0; i < attributesCount; i++){
        delete attributes[i];
    }
    if(attributesCount > 0){
        delete[] attributes;
    }
}

AttributeInfoExceptions::~AttributeInfoExceptions(){
    if(numberOfExceptions > 0){
        delete[] exceptionIndexTable;
    }
}

AttributeInfoInnerClasses::~AttributeInfoInnerClasses(){
    if(numberOfClasses > 0){
        delete[] classes;
    }
}

AttributeInfoLineNumberTable::~AttributeInfoLineNumberTable(){
    if(lineNumberTableLength){
        delete[] lineNumberTable;
    }
}

AttributeInfoLocalVariableTable::~AttributeInfoLocalVariableTable(){
    if(localVariableTableLength > 0){
        delete[] localVariableTable;
    }
}