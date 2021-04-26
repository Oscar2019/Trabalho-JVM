#include "../include/ExecutionEngine.h"
#include <cstdint>
#include <string>
#include "../include/ClassLoader.h"
#include "../include/RuntimeDataArea.h"
#include "../include/MethodInfo.h"
#include "../include/tipos.h"
#include "../include/Pointer.h"
#include "../include/Exceptions.h"
#include <cmath>
#include <functional>
// #include <locale>
// #include <codecvt>
#include <string>
#include <iostream>
#include <queue>
#include <math.h>

static bool objectsAreCompatibles(ClassLoader* classLoader, uint32_t dimensionsSource,  uint32_t classNumSource, uint8_t primitiveTypeSource, uint32_t dimensionsTarget,  uint32_t classNumTarget,  uint8_t primitiveTypeTarget){
    if(dimensionsTarget == dimensionsSource){
        if(primitiveTypeSource == 'L' && primitiveTypeTarget == 'L'){
            return classLoader->parentOf(classNumTarget, classNumSource);
        } else if(primitiveTypeSource == primitiveTypeTarget){
            return true;
        }
    } else if(dimensionsTarget < dimensionsSource){
        std::string strAux = "java/lang/Object";
        static uint32_t classNum = classLoader->getClassNum(strAux);
        if(classNum == classNumTarget){
            return true;
        }
    }
    return false;
}

uint32_t sizeArguments(std::string &s){
    uint32_t ret = 0;
    uint32_t next = 1;
    
    while(next < s.size() && s[next] != ')'){
        if(s[next] == 'B'){
            ret += 1;
            next += 1;
        } else if(s[next] == 'C'){
            ret += 1;
            next += 1;
        } else if(s[next] == 'D'){
            ret += 2;
            next += 1;
        } else if(s[next] == 'F'){
            ret += 1;
            next += 1;
        } else if(s[next] == 'I'){
            ret += 1;
            next += 1;
        } else if(s[next] == 'J'){
            ret += 2;
            next += 1;
        } else if(s[next] == 'S'){
            ret += 1;
            next += 1;
        } else if(s[next] == 'Z'){
            ret += 1;
            next += 1;
        } else if(s[next] == 'L'){
            ret += 1;
            next += 1;
            while(s[next] != ';'){
                next += 1;
            }
            next += 1;
        } else if(s[next] == '['){
            ret += 1;
            while(s[next] == '['){
                next += 1;
            }
            if(s[next] == 'L'){
                while(s[next] != ';'){
                    next += 1;
                }
            }
            next += 1;
        }
    }
    return ret;
}



int32_t execOp_nop(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 1;
}

int32_t execOp_aconst_null(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t value = 0;
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_iconst_m1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t value = -1;
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_iconst_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t value = 0;
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_iconst_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t value = 1;
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_iconst_2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t value = 2;
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_iconst_3(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t value = 3;
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_iconst_4(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t value = 4;
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_iconst_5(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t value = 5;
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_lconst_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int64_t value = 0LL;
    frame->pushOperandStack((value >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(value & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_lconst_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int64_t value = 1LL;
    frame->pushOperandStack((value >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(value & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_fconst_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        float f;
    } value;
    value.f = 0.0f;
    frame->pushOperandStack(value.u);
    return pc + 1;
}

int32_t execOp_fconst_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        float f;
    } value;
    value.f = 1.0f;
    frame->pushOperandStack(value.u);
    return pc + 1;
}

int32_t execOp_fconst_2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        float f;
    } value;
    value.f = 2.0f;
    frame->pushOperandStack(value.u);
    return pc + 1;
}

int32_t execOp_dconst_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        double d;
    } value;
    value.d = 0.0;
    frame->pushOperandStack((value.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(value.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_dconst_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        double d;
    } value;
    value.d = 1.0;
    frame->pushOperandStack((value.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(value.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_bipush(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t byte = static_cast<int8_t>(read<uint8_t>(attrinbuteCode->code + pc + 1));
    frame->pushOperandStack(byte);
    return pc + 2;
}

int32_t execOp_sipush(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t byte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    frame->pushOperandStack(byte);
    return pc + 3;
}

int32_t execOp_ldc(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    index = read<uint8_t>(attrinbuteCode->code + pc + 1);
    ConstantPoolInfo *cp = frame->getConstantPool()[index];
    if(cp->tag == ConstantPoolInfoTag::INTEGER){
        CPInteger *cpInteger = dynamic_cast<CPInteger*>(cp);
        frame->pushOperandStack(cpInteger->bytes);
    } else if(cp->tag == ConstantPoolInfoTag::FLOAT){
        CPFloat *cpFloat = dynamic_cast<CPFloat*>(cp);
        frame->pushOperandStack(cpFloat->bytes);
    } else if(cp->tag == ConstantPoolInfoTag::STRING){
        CPString *cpString = dynamic_cast<CPString*>(cp);
        CPUtf8 *utf8 = dynamic_cast<CPUtf8*>(frame->getConstantPool()[cpString->stringIndex]);
        std::string str1 = std::string((char*)utf8->bytes, utf8->length);
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
        // std::wstring_convert<std::codecvt<char16_t,char,std::mbstate_t>,char16_t> convert;
        std::u16string str2 = convert.from_bytes(str1);
        
        ObjectReference *arrayPointer = new ObjectReference();
        ObjectReference *stringPointer = new ObjectReference();
        ArrayType<uint16_t> *arrayReference = nullptr;
        
        arrayPointer->createArrayReference('C', 1);
        arrayReference = dynamic_cast<ArrayType<uint16_t>*>(arrayPointer->arrayReference);
        arrayReference->createData(str2.size());
        for(uint32_t i = 0; i < str2.size(); i++){
            arrayReference->data[i] = str2[i];
        }
        
        std::string strAux;

        strAux = "java/lang/Object";
        static uint32_t arrayClassNum = classLoader->getClassNum(strAux);
        strAux = "<init>:()V";
        // static MethodInfo* arrayConstructor =  classLoader->getContructor(arrayClassNum, strAux);
        static uint32_t arrayInstanceSize = classLoader->getInstanceSize(arrayClassNum);
        // static std::map<uint32_t, uint32_t*>* arrayIterfaceMethodLocalization = classLoader->getIterfaceMethodLocalization(arrayClassNum);
        static MethodInfo** arrayMethodTable =  classLoader->getMethodTable(arrayClassNum);
        // static ClassFile* arrayClassFile =  classLoader->getClassFile(arrayClassNum);

        arrayPointer->createData(arrayInstanceSize);
        arrayPointer->methods = arrayMethodTable;
        runTimeData->pushHeap(arrayPointer);

        
        strAux = "java/lang/String";
        static uint32_t stringClassNum = classLoader->getClassNum(strAux);
        strAux = "<init>:([C)V";
        static MethodInfo* stringConstructor = classLoader->getContructor(stringClassNum, strAux);
        *nextMethod = stringConstructor;
        static uint32_t stringInstanceSize = classLoader->getInstanceSize(stringClassNum);
        // static std::map<uint32_t, uint32_t*>* stringIterfaceMethodLocalization = classLoader->getIterfaceMethodLocalization(stringClassNum);
        static MethodInfo** stringMethodTable = classLoader->getMethodTable(stringClassNum);
        static ClassFile* stringClassFile =  classLoader->getClassFile(stringClassNum);

        stringPointer->classFile = stringClassFile;
        stringPointer->classNum = stringClassNum;
        stringPointer->createData(stringInstanceSize);
        stringPointer->methods = stringMethodTable;
        // stringPointer->methods = stringMethodTable;
        Frame* newFrame = *nextFrame = Frame::CreateFrame(stringConstructor);

        newFrame->varAt(1) = runTimeData->heapSize();
        runTimeData->pushHeap(stringPointer);
        newFrame->varAt(0) = runTimeData->heapSize();

        isInvokeInstruction = true;
        
        frame->pushOperandStack(runTimeData->heapSize());
        frame->pushOperandStack(pc + 2);
    }
    return pc + 2;
}

int32_t execOp_ldc_w(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    ConstantPoolInfo *cp = frame->getConstantPool()[index];
    if(cp->tag == ConstantPoolInfoTag::INTEGER){
        CPInteger *cpInteger = dynamic_cast<CPInteger*>(cp);
        frame->pushOperandStack(cpInteger->bytes);
    } else if(cp->tag == ConstantPoolInfoTag::FLOAT){
        CPFloat *cpFloat = dynamic_cast<CPFloat*>(cp);
        frame->pushOperandStack(cpFloat->bytes);
    } else if(cp->tag == ConstantPoolInfoTag::STRING){
        CPString *cpString = dynamic_cast<CPString*>(cp);
        CPUtf8 *utf8 = dynamic_cast<CPUtf8*>(frame->getConstantPool()[cpString->stringIndex]);
        std::string str1 = std::string((char*)utf8->bytes, utf8->length);
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
        // std::wstring_convert<std::codecvt<char16_t,char,std::mbstate_t>,char16_t> convert;
        std::u16string str2 = convert.from_bytes(str1);
        
        ObjectReference *arrayPointer = new ObjectReference();
        ObjectReference *stringPointer = new ObjectReference();
        ArrayType<uint16_t> *arrayReference = nullptr;
        
        arrayPointer->createArrayReference('C', 1);
        arrayReference = dynamic_cast<ArrayType<uint16_t>*>(arrayPointer->arrayReference);
        arrayReference->createData(str2.size());
        for(uint32_t i = 0; i < str2.size(); i++){
            arrayReference->data[i] = str2[i];
        }
        
        std::string strAux;

        strAux = "java/lang/Object";
        static uint32_t arrayClassNum = classLoader->getClassNum(strAux);
        strAux = "<init>:()V";
        // static MethodInfo* arrayConstructor =  classLoader->getContructor(arrayClassNum, strAux);
        static uint32_t arrayInstanceSize = classLoader->getInstanceSize(arrayClassNum);
        // static std::map<uint32_t, uint32_t*>* arrayIterfaceMethodLocalization = classLoader->getIterfaceMethodLocalization(arrayClassNum);
        static MethodInfo** arrayMethodTable =  classLoader->getMethodTable(arrayClassNum);
        // static ClassFile* arrayClassFile =  classLoader->getClassFile(arrayClassNum);

        arrayPointer->createData(arrayInstanceSize);
        arrayPointer->methods = arrayMethodTable;
        runTimeData->pushHeap(arrayPointer);

        
        strAux = "java/lang/String";
        static uint32_t stringClassNum = classLoader->getClassNum(strAux);
        strAux = "<init>:([C)V";
        static MethodInfo* stringConstructor = *nextMethod = classLoader->getContructor(stringClassNum, strAux);
        static uint32_t stringInstanceSize = classLoader->getInstanceSize(stringClassNum);
        // static std::map<uint32_t, uint32_t*>* stringIterfaceMethodLocalization = classLoader->getIterfaceMethodLocalization(stringClassNum);
        static MethodInfo** stringMethodTable = classLoader->getMethodTable(stringClassNum);
        static ClassFile* stringClassFile =  classLoader->getClassFile(stringClassNum);

        stringPointer->classFile = stringClassFile;
        stringPointer->classNum = stringClassNum;
        stringPointer->createData(stringInstanceSize);
        stringPointer->methods = stringMethodTable;
        // stringPointer->methods = stringMethodTable;
        Frame* newFrame = *nextFrame = Frame::CreateFrame(stringConstructor);

        newFrame->varAt(1) = runTimeData->heapSize();
        runTimeData->pushHeap(stringPointer);
        newFrame->varAt(0) = runTimeData->heapSize();

        isInvokeInstruction = true;
        
        frame->pushOperandStack(runTimeData->heapSize());
        frame->pushOperandStack(pc + 2);
    }
    return pc + 3;
}

int32_t execOp_ldc2_w(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    ConstantPoolInfo *cp = frame->getConstantPool()[index];
    if(cp->tag == ConstantPoolInfoTag::LONG){
        CPLong *cpLong = dynamic_cast<CPLong*>(cp);
        frame->pushOperandStack(cpLong->highBytes);
        frame->pushOperandStack(cpLong->lowBytes);
    } else if(cp->tag == ConstantPoolInfoTag::DOUBLE){
        CPDouble *cpDouble = dynamic_cast<CPDouble*>(cp);
        frame->pushOperandStack(cpDouble->highBytes);
        frame->pushOperandStack(cpDouble->lowBytes);
    }
    return pc + 3;
}

int32_t execOp_iload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    int32_t ret = 0;
    if(isWide){
        index = read<uint16_t>(attrinbuteCode->code + pc + 1);
        ret = 3;
    } else{
        index = read<uint8_t>(attrinbuteCode->code + pc + 1);
        ret = 2;
    }
    frame->pushOperandStack(frame->varAt(index));
    return pc + ret;
}

int32_t execOp_lload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    int32_t ret = 0;
    if(isWide){
        index = read<uint16_t>(attrinbuteCode->code + pc + 1);
        ret = 3;
    } else{
        index = read<uint8_t>(attrinbuteCode->code + pc + 1);
        ret = 2;
    }
    frame->pushOperandStack(frame->varAt(index));
    frame->pushOperandStack(frame->varAt(index+1));
    return pc + ret;
}

int32_t execOp_fload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    int32_t ret = 0;
    if(isWide){
        index = read<uint16_t>(attrinbuteCode->code + pc + 1);
        ret = 3;
    } else{
        index = read<uint8_t>(attrinbuteCode->code + pc + 1);
        ret = 2;
    }
    frame->pushOperandStack(frame->varAt(index));
    return pc + ret;
}

int32_t execOp_dload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    int32_t ret = 0;
    if(isWide){
        index = read<uint16_t>(attrinbuteCode->code + pc + 1);
        ret = 3;
    } else{
        index = read<uint8_t>(attrinbuteCode->code + pc + 1);
        ret = 2;
    }
    frame->pushOperandStack(frame->varAt(index));
    frame->pushOperandStack(frame->varAt(index+1));
    return pc + ret;
}

int32_t execOp_aload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    int32_t ret = 0;
    if(isWide){
        index = read<uint16_t>(attrinbuteCode->code + pc + 1);
        ret = 3;
    } else{
        index = read<uint8_t>(attrinbuteCode->code + pc + 1);
        ret = 2;
    }
    frame->pushOperandStack(frame->varAt(index));
    return pc + ret;
}

int32_t execOp_iload_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(0));
    return pc + 1;
}

int32_t execOp_iload_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(1));
    return pc + 1;
}

int32_t execOp_iload_2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(2));
    return pc + 1;
}

int32_t execOp_iload_3(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(3));
    return pc + 1;
}

int32_t execOp_lload_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(0));
    frame->pushOperandStack(frame->varAt(1));
    return pc + 1;
}

int32_t execOp_lload_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(1));
    frame->pushOperandStack(frame->varAt(2));
    return pc + 1;
}

int32_t execOp_lload_2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(2));
    frame->pushOperandStack(frame->varAt(3));
    return pc + 1;
}

int32_t execOp_lload_3(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(3));
    frame->pushOperandStack(frame->varAt(4));
    return pc + 1;
}

int32_t execOp_fload_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(0));
    return pc + 1;
}

int32_t execOp_fload_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(1));
    return pc + 1;
}

int32_t execOp_fload_2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(2));
    return pc + 1;
}

int32_t execOp_fload_3(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(3));
    return pc + 1;
}

int32_t execOp_dload_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(0));
    frame->pushOperandStack(frame->varAt(1));
    return pc + 1;
}

int32_t execOp_dload_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(1));
    frame->pushOperandStack(frame->varAt(2));
    return pc + 1;
}

int32_t execOp_dload_2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(2));
    frame->pushOperandStack(frame->varAt(3));
    return pc + 1;
}

int32_t execOp_dload_3(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(3));
    frame->pushOperandStack(frame->varAt(4));
    return pc + 1;
}

int32_t execOp_aload_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(0));
    return pc + 1;
}

int32_t execOp_aload_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(1));
    return pc + 1;
}

int32_t execOp_aload_2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(2));
    return pc + 1;
}

int32_t execOp_aload_3(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->varAt(3));
    return pc + 1;
}

int32_t execOp_iaload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);

        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<int32_t>* array = dynamic_cast<ArrayType<int32_t>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    int32_t value = array->data[index];
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_laload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<int64_t>* array = dynamic_cast<ArrayType<int64_t>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    int64_t value = array->data[index];
    frame->pushOperandStack((value >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(value & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_faload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<float>* array = dynamic_cast<ArrayType<float>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    union{
        uint32_t u;
        float f;
    } value;
    value.f = array->data[index];
    frame->pushOperandStack(value.u);
    return pc + 1;
}

int32_t execOp_daload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<double>* array = dynamic_cast<ArrayType<double>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    union{
        uint64_t u;
        double d;
    } value;
    value.d = array->data[index];
    frame->pushOperandStack((value.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(value.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_aaload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<uint32_t>* array = dynamic_cast<ArrayType<uint32_t>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    int32_t value = array->data[index];
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_baload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<int8_t>* array = dynamic_cast<ArrayType<int8_t>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    int32_t value = array->data[index];
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_caload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<uint16_t>* array = dynamic_cast<ArrayType<uint16_t>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    int32_t value = static_cast<uint32_t>(array->data[index]);
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_saload(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<int16_t>* array = dynamic_cast<ArrayType<int16_t>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    int32_t value = array->data[index];
    frame->pushOperandStack(value);
    return pc + 1;
}

int32_t execOp_istore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    int32_t ret = 0;
    if(isWide){
        index = read<uint16_t>(attrinbuteCode->code + pc + 1);
        ret = 3;
    } else{
        index = read<uint8_t>(attrinbuteCode->code + pc + 1);
        ret = 2;
    }
    frame->varAt(index) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + ret;
}

int32_t execOp_lstore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    int32_t ret = 0;
    if(isWide){
        index = read<uint16_t>(attrinbuteCode->code + pc + 1);
        ret = 3;
    } else{
        index = read<uint8_t>(attrinbuteCode->code + pc + 1);
        ret = 2;
    }
    frame->varAt(index+1) = frame->topOperandStack();
    frame->popOperandStack();
    frame->varAt(index) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + ret;
}

int32_t execOp_fstore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    int32_t ret = 0;
    if(isWide){
        index = read<uint16_t>(attrinbuteCode->code + pc + 1);
        ret = 3;
    } else{
        index = read<uint8_t>(attrinbuteCode->code + pc + 1);
        ret = 2;
    }
    frame->varAt(index) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + ret;
}

int32_t execOp_dstore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    int32_t ret = 0;
    if(isWide){
        index = read<uint16_t>(attrinbuteCode->code + pc + 1);
        ret = 3;
    } else{
        index = read<uint8_t>(attrinbuteCode->code + pc + 1);
        ret = 2;
    }
    frame->varAt(index+1) = frame->topOperandStack();
    frame->popOperandStack();
    frame->varAt(index) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + ret;
}

int32_t execOp_astore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    int32_t ret = 0;
    if(isWide){
        index = read<uint16_t>(attrinbuteCode->code + pc + 1);
        ret = 3;
    } else{
        index = read<uint8_t>(attrinbuteCode->code + pc + 1);
        ret = 2;
    }
    frame->varAt(index) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + ret;
}

int32_t execOp_istore_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(0) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_istore_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(1) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_istore_2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(2) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_istore_3(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(3) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_lstore_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(1) = frame->topOperandStack();
    frame->popOperandStack();
    frame->varAt(0) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_lstore_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(2) = frame->topOperandStack();
    frame->popOperandStack();
    frame->varAt(1) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_lstore_2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(3) = frame->topOperandStack();
    frame->popOperandStack();
    frame->varAt(2) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_lstore_3(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(4) = frame->topOperandStack();
    frame->popOperandStack();
    frame->varAt(3) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_fstore_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(0) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_fstore_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(1) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_fstore_2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(2) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_fstore_3(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(3) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_dstore_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(1) = frame->topOperandStack();
    frame->popOperandStack();
    frame->varAt(0) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_dstore_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(2) = frame->topOperandStack();
    frame->popOperandStack();
    frame->varAt(1) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_dstore_2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(3) = frame->topOperandStack();
    frame->popOperandStack();
    frame->varAt(2) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_dstore_3(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(4) = frame->topOperandStack();
    frame->popOperandStack();
    frame->varAt(3) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_astore_0(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(0) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_astore_1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(1) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_astore_2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(2) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_astore_3(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->varAt(3) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_iastore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t value = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<int32_t>* array = dynamic_cast<ArrayType<int32_t>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    array->data[index] = value;
    return pc + 1;
}

int32_t execOp_lastore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int64_t value = frame->topOperandStack();
    frame->popOperandStack();
    value |= static_cast<int64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<int64_t>* array = dynamic_cast<ArrayType<int64_t>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    array->data[index] = value;
    return pc + 1;
}

int32_t execOp_fastore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        float f;
    } value;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<float>* array = dynamic_cast<ArrayType<float>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    array->data[index] = value.f;
    return pc + 1;
}

int32_t execOp_dastore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        double d;
    } value;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    value.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<double>* array = dynamic_cast<ArrayType<double>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    array->data[index] = value.d;
    return pc + 1;
}

int32_t execOp_aastore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t value = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<uint32_t>* array = dynamic_cast<ArrayType<uint32_t>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }

    ObjectReference* pointerSource =  runTimeData->objectAt(value);
    uint32_t dimensionsSource = pointerSource->arrayReference == nullptr ? 0 : pointerSource->arrayReference->dimensions;
    uint32_t classNumSource = pointerSource->classNum;
    uint8_t primitiveTypeSource = pointerSource->arrayReference == nullptr ? 'L' : pointerSource->arrayReference->tipo;
    uint32_t dimensionsTarget = pointer->arrayReference->dimensions - 1;
    uint32_t classNumTarget = pointer->classNum;
    uint8_t primitiveTypeTarget = pointer->arrayReference->tipo;
    if(!objectsAreCompatibles(classLoader, dimensionsSource, classNumSource, primitiveTypeSource, dimensionsTarget, classNumTarget, primitiveTypeTarget)){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayStoreException", wasException);

        return pc + 1;
    } 
    
    array->data[index] = value;
    
    return pc + 1;
}

int32_t execOp_bastore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t value = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<int8_t>* array = dynamic_cast<ArrayType<int8_t>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    array->data[index] = value;
    return pc + 1;
}

int32_t execOp_castore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t value = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<uint16_t>* array = dynamic_cast<ArrayType<uint16_t>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    array->data[index] = value;
    return pc + 1;
}

int32_t execOp_sastore(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int32_t value = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t index = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t arrayref = frame->topOperandStack();
    frame->popOperandStack();
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference* pointer =  runTimeData->objectAt(arrayref);
    ArrayType<int16_t>* array = dynamic_cast<ArrayType<int16_t>*>(pointer->arrayReference);
    if(index >= array->size){
        generateException(classLoader, runTimeData, execEngine, "java/lang/ArrayIndexOutOfBoundsException", wasException);

        return pc + 1;
    }
    array->data[index] = value;
    return pc + 1;
}

int32_t execOp_pop(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_pop2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->popOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_dup(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    frame->pushOperandStack(frame->topOperandStack());
    return pc + 1;
}

int32_t execOp_dup_x1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t value1 = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t value2 = frame->topOperandStack();
    frame->popOperandStack();
    frame->pushOperandStack(value1);
    frame->pushOperandStack(value2);
    frame->pushOperandStack(value1);
    return pc + 1;
}

int32_t execOp_dup_x2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t value1 = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t value2 = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t value3 = frame->topOperandStack();
    frame->popOperandStack();
    frame->pushOperandStack(value1);
    frame->pushOperandStack(value3);
    frame->pushOperandStack(value2);
    frame->pushOperandStack(value1);
    return pc + 1;
}

int32_t execOp_dup2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t value1 = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t value2 = frame->topOperandStack();
    frame->popOperandStack();
    frame->pushOperandStack(value2);
    frame->pushOperandStack(value1);
    frame->pushOperandStack(value2);
    frame->pushOperandStack(value1);
    return pc + 1;
}

int32_t execOp_dup2_x1(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t value1 = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t value2 = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t value3 = frame->topOperandStack();
    frame->popOperandStack();
    frame->pushOperandStack(value2);
    frame->pushOperandStack(value1);
    frame->pushOperandStack(value3);
    frame->pushOperandStack(value2);
    frame->pushOperandStack(value1);
    return pc + 1;
}

int32_t execOp_dup2_x2(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t value1 = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t value2 = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t value3 = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t value4 = frame->topOperandStack();
    frame->popOperandStack();
    frame->pushOperandStack(value2);
    frame->pushOperandStack(value1);
    frame->pushOperandStack(value4);
    frame->pushOperandStack(value3);
    frame->pushOperandStack(value2);
    frame->pushOperandStack(value1);
    return pc + 1;
}

int32_t execOp_swap(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t value1 = frame->topOperandStack();
    frame->popOperandStack();
    uint32_t value2 = frame->topOperandStack();
    frame->popOperandStack();
    frame->pushOperandStack(value1);
    frame->pushOperandStack(value2);
    return pc + 1;
}

int32_t execOp_iadd(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, value2, result; // tipos do resutado

    value1.u = frame->topOperandStack(); // grava os bit da primeira parcela da soma
    frame->popOperandStack(); // apaga da pilha de operandos
    
    value2.u = frame->topOperandStack(); // grava os bit da segunda parcela da soma
    frame->popOperandStack(); // apaga da pilha de operandos

    value1.u = frame->topOperandStack(); // grava os bit da primeira parcela da soma
    frame->popOperandStack(); // apaga da pilha de operandos

    result.i = value1.i + value2.i; // realiza a soma dos valores
    frame->pushOperandStack(result.u); // o armazena na pilha de operandos
    return pc + 1;
}

int32_t execOp_ladd(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        int64_t i;
    } value1, value2, result;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value2.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();

    result.i = value1.i + value2.i;
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_fadd(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union {
        uint32_t u;    
        float f;    
    } value1, value2, result;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();

    result.f = value1.f + value2.f; 
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_dadd(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
   union {
        uint64_t u;    
        double d;    
    } value1, value2, result; // tiops do resutado
    
    value2.u = frame->topOperandStack(); // grava os bit mais significativos da segunda parcela da soma
    frame->popOperandStack(); // apaga da pilha de operandos
    value2.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32; // grava os bit menos significativos da segunda parcela da soma
    frame->popOperandStack(); // apaga da pilha de operandos

    value1.u = frame->topOperandStack(); // grava os bit mais significativos da primeira parcela da soma
    frame->popOperandStack(); // apaga da pilha de operandos
    value1.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32; // grava os bit menos significativos da primeira parcela da soma
    frame->popOperandStack(); // apaga da pilha de operandos

    result.d = value1.d + value2.d; // realiza a soma dos valores
    
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF); // o armazena na pilha os bits mais significativos na prinha de operandos
    frame->pushOperandStack(result.u & 0xFFFFFFFF); // o armazena na pilha os bits menos significativos na prinha de operandos
    return pc + 1;
}

int32_t execOp_isub(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, value2, result; // tiops do resutado
    
    value2.u = frame->topOperandStack(); // grava os bit da segunda parcela da soma
    frame->popOperandStack(); // apaga da pilha de operandos

    value1.u = frame->topOperandStack(); // grava os bit da primeira parcela da soma
    frame->popOperandStack(); // apaga da pilha de operandos

    result.i = value1.i - value2.i; // realiza a soma dos valores
    frame->pushOperandStack(result.u); // o armazena a poilha de operandos
    return pc + 1;
}

int32_t execOp_lsub(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_fsub(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_dsub(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_imul(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, value2, result; // tiops do resutado
    
    value2.u = frame->topOperandStack(); // grava os bit da segunda parcela da soma
    frame->popOperandStack(); // apaga da pilha de operandos

    value1.u = frame->topOperandStack(); // grava os bit da primeira parcela da soma
    frame->popOperandStack(); // apaga da pilha de operandos

    result.i = value1.i * value2.i; // realiza a soma dos valores
    frame->pushOperandStack(result.u); // o armazena a poilha de operandos
    return pc + 1;
}

int32_t execOp_lmul(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        int64_t i;
    } value1, value2, result;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value2.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();

    result.i = value1.i * value2.i;
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_fmul(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_dmul(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_idiv(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_ldiv(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_fdiv(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_ddiv(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_irem(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_lrem(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_frem(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union {
        uint32_t u;    
        float f;    
    } value1, value2, result;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();

    result.f = std::fmod(value1.f, value2.f);
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_drem(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union {
        uint64_t u;    
        double d;    
    } value1, value2, result;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value2.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();

    result.d = std::fmod(value1.d, value2.d);
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_ineg(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value, result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    
    result.i = -value.i;
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_lneg(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        int64_t i;
    } value, result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    value.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    
    result.i = -value.i;
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_fneg(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union {
        uint32_t u;    
        float f;    
    } value, result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    
    result.f = -value.f;
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_dneg(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union {
        uint64_t u;    
        double d;    
    } value, result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    value.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    
    result.d = -value.d;
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_ishl(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, result;
    uint32_t value2;
    value2 = frame->topOperandStack();
    frame->popOperandStack();
    value2 &= 0x1f;
    value1.u = frame->topOperandStack();
    frame->popOperandStack();

    result.i = value1.i << value2;
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_lshl(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        int64_t i;
    } value1, result;
    uint32_t value2;
    value2 = frame->topOperandStack();
    frame->popOperandStack();
    value2 &= 0x3f;
    value1.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();

    result.i = value1.i << value2;
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_ishr(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, result;
    uint32_t value2;
    value2 = frame->topOperandStack();
    frame->popOperandStack();
    value2 &= 0x1f;
    value1.u = frame->topOperandStack();
    frame->popOperandStack();

    result.i = value1.i >> value2;
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_lshr(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        int64_t i;
    } value1, result;
    uint32_t value2;
    value2 = frame->topOperandStack();
    frame->popOperandStack();
    value2 &= 0x3f;
    value1.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();

    result.i = value1.i >> value2;
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_iushr(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t value1, value2, result;
    value2 = frame->topOperandStack();
    frame->popOperandStack();
    value2 &= 0x1f;
    value1 = frame->topOperandStack();
    frame->popOperandStack();

    result = value1 >> value2;
    frame->pushOperandStack(result);
    return pc + 1;
}

int32_t execOp_lushr(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint64_t value1, result;
    uint32_t value2;
    value2 = frame->topOperandStack();
    frame->popOperandStack();
    value2 &= 0x3f;
    value1 = frame->topOperandStack();
    frame->popOperandStack();
    value1 |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();

    result = value1 >> value2;
    frame->pushOperandStack((result >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_iand(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t value1, value2, result;
    value2 = frame->topOperandStack();
    frame->popOperandStack();
    value1 = frame->topOperandStack();
    frame->popOperandStack();

    result = value1 & value2;
    frame->pushOperandStack(result);
    return pc + 1;
}

int32_t execOp_land(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint64_t value1, value2, result;
    value2 = frame->topOperandStack();
    frame->popOperandStack();
    value2 |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    value1 = frame->topOperandStack();
    frame->popOperandStack();
    value1 |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();

    result = value1 & value2;
    frame->pushOperandStack((result >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_ior(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t value1, value2, result;
    value2 = frame->topOperandStack();
    frame->popOperandStack();
    value1 = frame->topOperandStack();
    frame->popOperandStack();

    result = value1 | value2;
    frame->pushOperandStack(result);
    return pc + 1;
}

int32_t execOp_lor(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint64_t value1, value2, result;
    value2 = frame->topOperandStack();
    frame->popOperandStack();
    value2 |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    value1 = frame->topOperandStack();
    frame->popOperandStack();
    value1 |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();

    result = value1 | value2;
    frame->pushOperandStack((result >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_ixor(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t value1, value2, result;
    value2 = frame->topOperandStack();
    frame->popOperandStack();
    value1 = frame->topOperandStack();
    frame->popOperandStack();

    result = value1 ^ value2;
    frame->pushOperandStack(result);
    return pc + 1;
}

int32_t execOp_lxor(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint64_t value1, value2, result;
    value2 = frame->topOperandStack();
    frame->popOperandStack();
    value2 |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    value1 = frame->topOperandStack();
    frame->popOperandStack();
    value1 |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();

    result = value1 ^ value2;
    frame->pushOperandStack((result >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_iinc(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    int32_t constp;
    uint32_t ret;
    if(isWide){
        index = read<uint16_t>(attrinbuteCode->code + pc + 1);
        constp = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 3));
        ret = 5;
    } else{
        index = read<uint8_t>(attrinbuteCode->code + pc + 1);
        constp = static_cast<int8_t>(read<uint8_t>(attrinbuteCode->code + pc + 2));
        ret = 3;
    }
    frame->varAt(index) += constp;
    return pc + ret;
}

int32_t execOp_i2l(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value;
    union{
        uint64_t u;
        int64_t i;
    } result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    
    result.i = value.i;
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_i2f(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value;
    union{
        uint32_t u;
        float f;
    } result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    
    result.f = value.i;
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_i2d(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value;
    union{
        uint64_t u;
        double d;
    } result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    
    result.d = value.i;
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_l2i(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        int64_t i;
    } value;
    union{
        uint32_t u;
        int32_t i;
    } result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    value.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    
    result.i = value.i;
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_l2f(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        int64_t i;
    } value;
    union{
        uint32_t u;
        float f;
    } result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    value.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    
    result.f = value.i;
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_l2d(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        int64_t i;
    } value;
    union{
        uint64_t u;
        double d;
    } result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    value.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    
    result.d = value.i;
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_f2i(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        float f;
    } value;
    union{
        uint32_t u;
        int32_t i;
    } result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    
    if(std::isnan(value.f)){
        result.i = 0;
    } else if(value.f > std::numeric_limits<int32_t>::max()){
        result.i = std::numeric_limits<int32_t>::max();
    } else if(value.f < std::numeric_limits<int32_t>::min()){
        result.i = std::numeric_limits<int32_t>::min();
    } else{
        result.i = value.f;
    }
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_f2l(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        float f;
    } value;
    union{
        uint64_t u;
        int64_t i;
    } result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    
    if(std::isnan(value.f)){
        result.i = 0;
    } else if(value.f > std::numeric_limits<int64_t>::max()){
        result.i = std::numeric_limits<int64_t>::max();
    } else if(value.f < std::numeric_limits<int64_t>::min()){
        result.i = std::numeric_limits<int64_t>::min();
    } else{
        result.i = value.f;
    }
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_f2d(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        float f;
    } value;
    union{
        uint64_t u;
        double d;
    } result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    
    result.d = value.f;
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_d2i(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        double d;
    } value;
    union{
        uint32_t u;
        int32_t i;
    } result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    value.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    
    if(std::isnan(value.d)){
        result.i = 0;
    } else if(value.d > std::numeric_limits<int32_t>::max()){
        result.i = std::numeric_limits<int32_t>::max();
    } else if(value.d < std::numeric_limits<int32_t>::min()){
        result.i = std::numeric_limits<int32_t>::min();
    } else{
        result.i = value.d;
    }
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_d2l(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        double d;
    } value;
    union{
        uint64_t u;
        int64_t i;
    } result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    value.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    
    if(std::isnan(value.d)){
        result.i = 0;
    } else if(value.d > std::numeric_limits<int64_t>::max()){
        result.i = std::numeric_limits<int64_t>::max();
    } else if(value.d < std::numeric_limits<int64_t>::min()){
        result.i = std::numeric_limits<int64_t>::min();
    } else{
        result.i = value.d;
    }
    frame->pushOperandStack((result.u >> 32) & 0xFFFFFFFF);
    frame->pushOperandStack(result.u & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_d2f(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint64_t u;
        double d;
    } value;
    union{
        uint32_t u;
        float f;
    } result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    value.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
    frame->popOperandStack();
    
    result.f = value.d;
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_i2b(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value, result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    
    int8_t aux = value.u & 0xFF;
    
    result.i = aux;
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_i2c(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value, result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    
    uint16_t aux = value.u & 0xFFFF;
    
    result.u = aux;
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_i2s(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value, result;
    value.u = frame->topOperandStack();
    frame->popOperandStack();
    
    int16_t aux = value.u & 0xFFFF;
    
    result.u = aux;
    frame->pushOperandStack(result.u);
    return pc + 1;
}

int32_t execOp_lcmp(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union {
        uint64_t u;    
        int64_t i;    
    } value1, value2, result; // tipos do resutado

    value2.u = frame->topOperandStack(); // grava os bit mais significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos
    value2.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32; // grava os bit menos significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos

    value1.u = frame->topOperandStack(); // grava os bit mais significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos
    value1.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32; // grava os bit menos significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos

    if (value1.i > value2.i) {
        result.i = 1;
    } else if (value1.i == value2.i) {
        result.i = 0;
    } else result.i = -1;

    frame->pushOperandStack(result.i & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_fcmpl(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union {
        float f;    
        int32_t i;    
    } value1, value2, result; // tipos do resutado

    value2.i = frame->topOperandStack(); // grava o primeiro float para comparação
    frame->popOperandStack(); // apaga da pilha de operandos

    value1.i = frame->topOperandStack(); // grava os bit mais significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos

    if (value1.f > value2.f) {
        result.i = 1;
    } else if (value1.f == value2.f) {
        result.i = 0;
    } else result.i = -1;

    if (std::isnan(value1.f) == 1 || std::isnan(value2.f) == 1) { // checa se qualquer um dos valores é NaN
        result.i = -1;
    }
    
    frame->pushOperandStack(result.i & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_fcmpg(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union {
        float f;    
        uint32_t i;    
    } value1, value2, result; // tipos do resutado

    value2.i = frame->topOperandStack(); // grava o primeiro float para comparação
    frame->popOperandStack(); // apaga da pilha de operandos

    value1.i = frame->topOperandStack(); // grava os bit mais significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos

    if (value1.f > value2.f) {
        result.i = 1;
    } else if (value1.f == value2.f) {
        result.i = 0;
    } else result.i = -1;

    if (std::isnan(value1.f) == 1 || std::isnan(value2.f) == 1) { // checa se qualquer um dos valores é NaN
        result.i = 1;
    }
    
    frame->pushOperandStack(result.i & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_dcmpl(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union {
        uint64_t u;
        double d;    
        int64_t i;    
    } value1, value2, result; // tipos do resutado

    value2.u = frame->topOperandStack(); // grava os bit mais significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos
    value2.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32; // grava os bit menos significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos

    value1.u = frame->topOperandStack(); // grava os bit mais significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos
    value1.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32; // grava os bit menos significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos

    if (value1.d > value2.d) {
        result.i = 1;
    } else if (value1.d == value2.d) {
        result.i = 0;
    } else result.i = -1;

    if (std::isnan(value1.d) == 1 || std::isnan(value2.d) == 1) { // checa se qualquer um dos valores é NaN
        result.i = -1;
    }

    frame->pushOperandStack(result.i & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_dcmpg(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union {
        uint64_t u;
        double d;    
        int64_t i;    
    } value1, value2, result; // tipos do resutado

    value2.u = frame->topOperandStack(); // grava os bit mais significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos
    value2.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32; // grava os bit menos significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos

    value1.u = frame->topOperandStack(); // grava os bit mais significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos
    value1.u |= static_cast<uint64_t>(frame->topOperandStack()) << 32; // grava os bit menos significativos da primeira parcela da comparação
    frame->popOperandStack(); // apaga da pilha de operandos

    if (value1.d > value2.d) {
        result.i = 1;
    } else if (value1.d == value2.d) {
        result.i = 0;
    } else result.i = -1;

    if (std::isnan(value1.d) == 1 || std::isnan(value2.d) == 1) { // checa se qualquer um dos valores é NaN
        result.i = 1;
    }

    frame->pushOperandStack(result.i & 0xFFFFFFFF);
    return pc + 1;
}

int32_t execOp_ifeq(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value;
    int16_t branchbyte = 3;
    value.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value.i == 0){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_ifne(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value;
    int16_t branchbyte = 3;
    value.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value.i != 0){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_iflt(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value;
    int16_t branchbyte = 3;
    value.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value.i < 0){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_ifge(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value;
    int16_t branchbyte = 3;
    value.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value.i >= 0){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_ifgt(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value;
    int16_t branchbyte = 3;
    value.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value.i > 0){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_ifle(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value;
    int16_t branchbyte = 3;
    value.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value.i <= 0){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_if_icmpeq(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, value2;
    int16_t branchbyte = 3;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value1.i == value2.i){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_if_icmpne(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, value2;
    int16_t branchbyte = 3;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value1.i != value2.i){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_if_icmplt(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, value2;
    int16_t branchbyte = 3;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value1.i < value2.i){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_if_icmpge(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, value2;
    int16_t branchbyte = 3;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value1.i >= value2.i){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_if_icmpgt(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, value2;
    int16_t branchbyte = 3;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value1.i > value2.i){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_if_icmple(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, value2;
    int16_t branchbyte = 3;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value1.i <= value2.i){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_if_acmpeq(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, value2;
    int16_t branchbyte = 3;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value1.i == value2.i){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_if_acmpne(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value1, value2;
    int16_t branchbyte = 3;
    value2.u = frame->topOperandStack();
    frame->popOperandStack();
    value1.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value1.i != value2.i){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_goto(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int16_t branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));

    return pc + branchbyte;
}

int32_t execOp_jsr(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    int16_t branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));

    frame->pushOperandStack(pc+3);

    return pc + branchbyte;
}

int32_t execOp_ret(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint8_t index = read<uint8_t>(attrinbuteCode->code + pc + 1);

    return frame->varAt(index);
}

int32_t execOp_tableswitch(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } index;
    index.u = frame->topOperandStack();
    frame->popOperandStack();

    uint32_t ret = 1 + (4 - (pc + 1)%4)%4;
    int32_t defaultS = static_cast<int32_t>(read<uint32_t>(attrinbuteCode->code + pc + ret)); ret += 4;
    int32_t lowS = static_cast<int32_t>(read<uint32_t>(attrinbuteCode->code + pc + ret)); ret += 4;
    int32_t highS = static_cast<int32_t>(read<uint32_t>(attrinbuteCode->code + pc + ret)); ret += 4;

    if(lowS <= index.i && index.i <= highS){
        int32_t branchbyte = static_cast<int32_t>(read<uint32_t>(attrinbuteCode->code + pc + ret + (index.i - lowS) * 4));
        // int32_t branchbyte = attrinbuteCode->code[index.i - lowS];
        return pc + branchbyte;
    } else{
        return pc + defaultS;
    }
}

int32_t execOp_lookupswitch(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } key;
    key.u = frame->topOperandStack();
    frame->popOperandStack();

    uint32_t ret = 1 + (4 - (pc + 1)%4)%4;
    int32_t defaultS = static_cast<int32_t>(read<uint32_t>(attrinbuteCode->code + pc + ret)); ret += 4;
    int32_t npairs = static_cast<int32_t>(read<uint32_t>(attrinbuteCode->code + pc + ret)); ret += 4;

    for(int32_t i = 0; i < npairs; i++){
        int32_t value = static_cast<int32_t>(read<uint32_t>(attrinbuteCode->code + pc + ret)); ret += 4;
        int32_t branchbyte = static_cast<int32_t>(read<uint32_t>(attrinbuteCode->code + pc + ret)); ret += 4;
        if(key.i == value){
            return pc + branchbyte;
        }
    }
    return pc + defaultS;
}

int32_t execOp_ireturn(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    returnStack.push(frame->topOperandStack());
    frame->popOperandStack();
    finished = true;
    return pc + 1;
}

int32_t execOp_lreturn(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    returnStack.push(frame->topOperandStack());
    frame->popOperandStack();
    returnStack.push(frame->topOperandStack());
    frame->popOperandStack();
    finished = true;
    return pc + 1;
}

int32_t execOp_freturn(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    returnStack.push(frame->topOperandStack());
    frame->popOperandStack();
    finished = true;
    return pc + 1;
}

int32_t execOp_dreturn(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    returnStack.push(frame->topOperandStack());
    frame->popOperandStack();
    returnStack.push(frame->topOperandStack());
    frame->popOperandStack();
    finished = true;
    return pc + 1;
}

int32_t execOp_areturn(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    returnStack.push(frame->topOperandStack());
    frame->popOperandStack();
    finished = true;
    return pc + 1;
}

int32_t execOp_return(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    finished = true;
    return pc + 1;
}

int32_t execOp_getstatic(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPFieldref* cpField = dynamic_cast<CPFieldref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpField->nameAndTypeIndex]);
    if(!cpField->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    std::string descriptor = getStringFromCPInfo(frame->getConstantPool(), cpNameAndType->descriptorIndex);
    if(descriptor[0] == 'B'){
        uint8_t value = *reinterpret_cast<uint8_t*>(cpField->classFieldValue);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'C'){
        uint16_t value = *reinterpret_cast<uint16_t*>(cpField->classFieldValue);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'D'){
        uint64_t value = *reinterpret_cast<uint64_t*>(cpField->classFieldValue);
        frame->pushOperandStack((value >> 32) & 0xFFFF);
        frame->pushOperandStack(value & 0xFFFF);
    } else if(descriptor[0] == 'F'){
        uint32_t value = *reinterpret_cast<uint32_t*>(cpField->classFieldValue);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'I'){
        uint32_t value = *reinterpret_cast<uint32_t*>(cpField->classFieldValue);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'J'){
        uint64_t value = *reinterpret_cast<uint64_t*>(cpField->classFieldValue);
        frame->pushOperandStack((value >> 32) & 0xFFFF);
        frame->pushOperandStack(value & 0xFFFF);
    } else if(descriptor[0] == 'S'){
        uint16_t value = *reinterpret_cast<uint16_t*>(cpField->classFieldValue);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'Z'){
        uint8_t value = *reinterpret_cast<uint8_t*>(cpField->classFieldValue);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'L'){
        uint32_t value = *reinterpret_cast<uint32_t*>(cpField->classFieldValue);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == '['){
        uint32_t value = *reinterpret_cast<uint32_t*>(cpField->classFieldValue);
        frame->pushOperandStack(value);
    }
    return pc + 3;
}

int32_t execOp_putstatic(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPFieldref* cpField = dynamic_cast<CPFieldref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpField->nameAndTypeIndex]);
    if(!cpField->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    std::string descriptor = getStringFromCPInfo(frame->getConstantPool(), cpNameAndType->descriptorIndex);
    if(descriptor[0] == 'B'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        *reinterpret_cast<uint8_t*>(cpField->classFieldValue) = value;
    } else if(descriptor[0] == 'C'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        *reinterpret_cast<uint16_t*>(cpField->classFieldValue) = value;
    } else if(descriptor[0] == 'D'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        *reinterpret_cast<uint32_t*>(cpField->classFieldValue) = static_cast<uint64_t>(value) << 32;
        value = frame->topOperandStack();
        frame->popOperandStack();
        *reinterpret_cast<uint32_t*>(cpField->classFieldValue) |= value;
    } else if(descriptor[0] == 'F'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        *reinterpret_cast<uint32_t*>(cpField->classFieldValue) = value;
    } else if(descriptor[0] == 'I'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        *reinterpret_cast<uint32_t*>(cpField->classFieldValue) = value;
    } else if(descriptor[0] == 'J'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        *reinterpret_cast<uint32_t*>(cpField->classFieldValue) = static_cast<uint64_t>(value) << 32;
        value = frame->topOperandStack();
        frame->popOperandStack();
        *reinterpret_cast<uint32_t*>(cpField->classFieldValue) |= value;
    } else if(descriptor[0] == 'S'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        *reinterpret_cast<uint16_t*>(cpField->classFieldValue) = value;
    } else if(descriptor[0] == 'Z'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        *reinterpret_cast<uint8_t*>(cpField->classFieldValue) = value;
    } else if(descriptor[0] == 'L'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        *reinterpret_cast<uint32_t*>(cpField->classFieldValue) = value;
    } else if(descriptor[0] == '['){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        *reinterpret_cast<uint32_t*>(cpField->classFieldValue) = value;
    }
    return pc + 3;
}

int32_t execOp_getfield(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    uint32_t objectref = frame->topOperandStack();
    frame->popOperandStack();
    if(objectref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 3;
    }
    CPFieldref* cpField = dynamic_cast<CPFieldref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpField->nameAndTypeIndex]);
    if(!cpField->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    ObjectReference* object = runTimeData->objectAt(objectref); 
    std::string descriptor = getStringFromCPInfo(frame->getConstantPool(), cpNameAndType->descriptorIndex);
    if(descriptor[0] == 'B'){
        uint8_t value = read<uint8_t>(object->data + cpField->instanceFieldDesloc);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'C'){
        uint16_t value = read<uint16_t>(object->data + cpField->instanceFieldDesloc);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'D'){
        uint32_t value = read<uint32_t>(object->data + cpField->instanceFieldDesloc);
        frame->pushOperandStack(value);
        value = read<uint32_t>(object->data + cpField->instanceFieldDesloc + 4);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'F'){
        uint32_t value = read<uint32_t>(object->data + cpField->instanceFieldDesloc);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'I'){
        uint32_t value = read<uint32_t>(object->data + cpField->instanceFieldDesloc);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'J'){
        uint32_t value = read<uint32_t>(object->data + cpField->instanceFieldDesloc);
        frame->pushOperandStack(value);
        value = read<uint32_t>(object->data + cpField->instanceFieldDesloc + 4);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'S'){
        uint16_t value = read<uint16_t>(object->data + cpField->instanceFieldDesloc);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'Z'){
        uint8_t value = read<uint8_t>(object->data + cpField->instanceFieldDesloc);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == 'L'){
        uint32_t value = read<uint32_t>(object->data + cpField->instanceFieldDesloc);
        frame->pushOperandStack(value);
    } else if(descriptor[0] == '['){
        uint32_t value = read<uint32_t>(object->data + cpField->instanceFieldDesloc);
        frame->pushOperandStack(value);
    }
    return pc + 3;
}

int32_t execOp_putfield(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPFieldref* cpField = dynamic_cast<CPFieldref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpField->nameAndTypeIndex]);
    if(!cpField->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    std::string descriptor = getStringFromCPInfo(frame->getConstantPool(), cpNameAndType->descriptorIndex);
    if(descriptor[0] == 'B'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        uint32_t objectref = frame->topOperandStack();
        frame->popOperandStack();
        if(objectref == 0){
            generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
            
            return pc + 3;
        }
        ObjectReference* object = runTimeData->objectAt(objectref); 
        uint8_t* vet = object->data + cpField->instanceFieldDesloc;
        vet[0] = value;
    } else if(descriptor[0] == 'C'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        uint32_t objectref = frame->topOperandStack();
        frame->popOperandStack();
        if(objectref == 0){
            generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
            
            return pc + 3;
        }
        ObjectReference* object = runTimeData->objectAt(objectref); 
        uint8_t* vet = object->data + cpField->instanceFieldDesloc;
        vet[0] = (value >> 8) & 0xff;
        vet[1] = (value >> 0) & 0xff;
    } else if(descriptor[0] == 'D'){
        uint32_t value1, value2;
        value1 = frame->topOperandStack();
        frame->popOperandStack();
        value2 = frame->topOperandStack();
        frame->popOperandStack();
        uint32_t objectref = frame->topOperandStack();
        frame->popOperandStack();
        if(objectref == 0){
            generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
            
            return pc + 3;
        }
        ObjectReference* object = runTimeData->objectAt(objectref); 
        uint8_t* vet = object->data + cpField->instanceFieldDesloc;
        vet[4] = (value1 >> 24) & 0xff;
        vet[5] = (value1 >> 16) & 0xff;
        vet[6] = (value1 >> 8) & 0xff;
        vet[7] = (value1 >> 0) & 0xff;
        vet[0] = (value2 >> 24) & 0xff;
        vet[1] = (value2 >> 16) & 0xff;
        vet[2] = (value2 >> 8) & 0xff;
        vet[3] = (value2 >> 0) & 0xff;
    } else if(descriptor[0] == 'F'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        uint32_t objectref = frame->topOperandStack();
        frame->popOperandStack();
        if(objectref == 0){
            generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
            
            return pc + 3;
        }
        ObjectReference* object = runTimeData->objectAt(objectref); 
        uint8_t* vet = object->data + cpField->instanceFieldDesloc;
        vet[0] = (value >> 24) & 0xff;
        vet[1] = (value >> 16) & 0xff;
        vet[2] = (value >> 8) & 0xff;
        vet[3] = (value >> 0) & 0xff;
    } else if(descriptor[0] == 'I'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        uint32_t objectref = frame->topOperandStack();
        frame->popOperandStack();
        if(objectref == 0){
            generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
            
            return pc + 3;
        }
        ObjectReference* object = runTimeData->objectAt(objectref); 
        uint8_t* vet = object->data + cpField->instanceFieldDesloc;
        vet[0] = (value >> 24) & 0xff;
        vet[1] = (value >> 16) & 0xff;
        vet[2] = (value >> 8) & 0xff;
        vet[3] = (value >> 0) & 0xff;
    } else if(descriptor[0] == 'J'){
        uint32_t value1, value2;
        value1 = frame->topOperandStack();
        frame->popOperandStack();
        value2 = frame->topOperandStack();
        frame->popOperandStack();
        uint32_t objectref = frame->topOperandStack();
        frame->popOperandStack();
        if(objectref == 0){
            generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
            
            return pc + 3;
        }
        ObjectReference* object = runTimeData->objectAt(objectref); 
        uint8_t* vet = object->data + cpField->instanceFieldDesloc;
        vet[4] = (value1 >> 24) & 0xff;
        vet[5] = (value1 >> 16) & 0xff;
        vet[6] = (value1 >> 8) & 0xff;
        vet[7] = (value1 >> 0) & 0xff;
        vet[0] = (value2 >> 24) & 0xff;
        vet[1] = (value2 >> 16) & 0xff;
        vet[2] = (value2 >> 8) & 0xff;
        vet[3] = (value2 >> 0) & 0xff;
    } else if(descriptor[0] == 'S'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        uint32_t objectref = frame->topOperandStack();
        frame->popOperandStack();
        if(objectref == 0){
            generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
            
            return pc + 3;
        }
        ObjectReference* object = runTimeData->objectAt(objectref); 
        uint8_t* vet = object->data + cpField->instanceFieldDesloc;
        vet[0] = (value >> 8) & 0xff;
        vet[1] = (value >> 0) & 0xff;
    } else if(descriptor[0] == 'Z'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        uint32_t objectref = frame->topOperandStack();
        frame->popOperandStack();
        if(objectref == 0){
            generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
            
            return pc + 3;
        }
        ObjectReference* object = runTimeData->objectAt(objectref); 
        uint8_t* vet = object->data + cpField->instanceFieldDesloc;
        vet[0] = value;
    } else if(descriptor[0] == 'L'){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        uint32_t objectref = frame->topOperandStack();
        frame->popOperandStack();
        if(objectref == 0){
            generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
            
            return pc + 3;
        }
        ObjectReference* object = runTimeData->objectAt(objectref); 
        uint8_t* vet = object->data + cpField->instanceFieldDesloc;
        vet[0] = (value >> 24) & 0xff;
        vet[1] = (value >> 16) & 0xff;
        vet[2] = (value >> 8) & 0xff;
        vet[3] = (value >> 0) & 0xff;
    } else if(descriptor[0] == '['){
        uint32_t value = frame->topOperandStack();
        frame->popOperandStack();
        uint32_t objectref = frame->topOperandStack();
        frame->popOperandStack();
        if(objectref == 0){
            generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
            
            return pc + 3;
        }
        ObjectReference* object = runTimeData->objectAt(objectref); 
        uint8_t* vet = object->data + cpField->instanceFieldDesloc;
        vet[0] = (value >> 24) & 0xff;
        vet[1] = (value >> 16) & 0xff;
        vet[2] = (value >> 8) & 0xff;
        vet[3] = (value >> 0) & 0xff;
    }
    return pc + 3;
}

int32_t execOp_invokevirtual(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPMethodref* cpMeth = dynamic_cast<CPMethodref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpMeth->nameAndTypeIndex]);
    // std::cout << getStringFromCPInfo(frame->getConstantPool(), index) << "\n";
    if(!cpMeth->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    std::string descriptor = getStringFromCPInfo(frame->getConstantPool(), cpNameAndType->descriptorIndex);
    uint32_t qtdOperandStack = 1 + sizeArguments(descriptor);

    uint32_t* vetAux = nullptr;
    if(qtdOperandStack > 0){
        vetAux = new uint32_t[qtdOperandStack];
    }
    for(uint32_t i = 0; i < qtdOperandStack; i++){
        vetAux[i] = frame->topOperandStack();
        frame->popOperandStack();
    }

    for(uint32_t i = 0; i < qtdOperandStack/2; i++){
        std::swap(vetAux[i], vetAux[qtdOperandStack - i - 1]);
    }
    
    if(vetAux[0] == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 3;
    }

    auto auxMeMata = runTimeData->objectAt(vetAux[0]);
    MethodInfo* newMethod = auxMeMata->methods[cpMeth->instanceMethodDesloc];
    Frame* newFrame = Frame::CreateFrame(newMethod);
    *nextFrame = newFrame;
    *nextMethod = newMethod;
    for(uint32_t i = 0; i < qtdOperandStack; i++){
        newFrame->varAt(i) = vetAux[i];
    }
    if(qtdOperandStack > 0){
        delete[] vetAux;
    }
    isInvokeInstruction = true;
    frame->pushOperandStack(pc + 3);
    
    return pc + 3;
}

int32_t execOp_invokespecial(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPMethodref* cpMeth = dynamic_cast<CPMethodref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpMeth->nameAndTypeIndex]);
    // std::cout << getStringFromCPInfo(frame->getConstantPool(), index) << "\n";
    if(!cpMeth->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    std::string descriptor = getStringFromCPInfo(frame->getConstantPool(), cpNameAndType->descriptorIndex);
    uint32_t qtdOperandStack = 1 + sizeArguments(descriptor);

    MethodInfo* newMethod = cpMeth->directMethod;
    Frame* newFrame = Frame::CreateFrame(newMethod);
    *nextFrame = newFrame;
    *nextMethod = newMethod;
    for(uint32_t i = 0; i < qtdOperandStack; i++){
        newFrame->varAt(i) = frame->topOperandStack();
        frame->popOperandStack();
    }
    for(uint32_t i = 0; i < qtdOperandStack/2; i++){
        std::swap(newFrame->varAt(i), newFrame->varAt(qtdOperandStack - i - 1));
    }
    
    if(newFrame->varAt(0) == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 3;
    }
    isInvokeInstruction = true;
    frame->pushOperandStack(pc + 3);
    
    return pc + 3;
}

int32_t execOp_invokestatic(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPMethodref* cpMeth = dynamic_cast<CPMethodref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpMeth->nameAndTypeIndex]);
    // std::cout << getStringFromCPInfo(frame->getConstantPool(), index) << "\n";
    if(!cpMeth->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    std::string descriptor = getStringFromCPInfo(frame->getConstantPool(), cpNameAndType->descriptorIndex);
    uint32_t qtdOperandStack = sizeArguments(descriptor);

    MethodInfo* newMethod = cpMeth->directMethod;
    Frame* newFrame = Frame::CreateFrame(newMethod);
    if(newFrame != nullptr){
        *nextFrame = newFrame;
        *nextMethod = newMethod;
        for(uint32_t i = 0; i < qtdOperandStack; i++){
            newFrame->varAt(i) = frame->topOperandStack();
            frame->popOperandStack();
        }
        for(uint32_t i = 0; i < qtdOperandStack/2; i++){
            std::swap(newFrame->varAt(i), newFrame->varAt(qtdOperandStack - i - 1));
        }
        isInvokeInstruction = true;
        frame->pushOperandStack(pc + 3);
    } else{
        std::string nameClass = getStringFromCPInfo(frame->getConstantPool(), cpMeth->classIndex);
        std::string nameMethod = getStringFromCPInfo(frame->getConstantPool(), cpNameAndType->nameIndex) + ":" + descriptor;
        if(nameClass == "java/io/PrintStream"){
            if(nameMethod == "print_int:(I)V"){
                int32_t value = frame->topOperandStack();
                frame->popOperandStack();
                std::cout << value;
            } else if(nameMethod == "print_char:(C)V"){
                char16_t value = frame->topOperandStack();
                frame->popOperandStack();
                std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> myconv;
                // std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> myconv;
                std::string bs = myconv.to_bytes(value);
                std::cout << bs;
            } else if(nameMethod == "print_byte:(B)V"){
                int32_t value = frame->topOperandStack();
                frame->popOperandStack();
                std::cout << value;
            } else if(nameMethod == "print_short:(S)V"){
                int32_t value = frame->topOperandStack();
                frame->popOperandStack();
                std::cout << value;
            } else if(nameMethod == "print_bool:(Z)V"){
                bool value = frame->topOperandStack();
                frame->popOperandStack();
                std::cout << (value ? "true" : "false");
            } else if(nameMethod == "print_long:(J)V"){
                uint64_t value = frame->topOperandStack();
                frame->popOperandStack();
                value |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
                frame->popOperandStack();
                std::cout << static_cast<int64_t>(value);
            } else if(nameMethod == "print_float:(F)V"){
                union{
                    uint32_t i;
                    float d;
                } value;
                value.i = frame->topOperandStack();
                frame->popOperandStack();
                std::cout << value.d;
            } else if(nameMethod == "print_double:(D)V"){
                union{
                    uint64_t i;
                    double d;
                } value;
                value.i = frame->topOperandStack();
                frame->popOperandStack();
                value.i |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
                frame->popOperandStack();
                std::cout << value.d;
            } else if(nameMethod == "print_string:(Ljava/lang/String;)V"){
                uint32_t value = frame->topOperandStack();
                frame->popOperandStack();

                static std::string fieldName = "value:[C";
                static uint32_t delta = classLoader->getDatafromObject(value, fieldName);
                ObjectReference* objReference = runTimeData->objectAt(value);
                ObjectReference* charArrayReference = runTimeData->objectAt(read<uint32_t>(objReference->data + delta));
                ArrayType<uint16_t>* charArray = dynamic_cast<ArrayType<uint16_t>*>(charArrayReference->arrayReference);
                std::u16string str1((char16_t*)charArray->data, charArray->size);
                
                static std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
                std::string str2 = convert.to_bytes(str1);
                std::cout << str2; 
            }
        }
    }
    
    return pc + 3;
}

int32_t execOp_invokeinterface(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPInterfaceMethodref* cpInterfaceMethodref = dynamic_cast<CPInterfaceMethodref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpInterfaceMethodref->nameAndTypeIndex]);
    // std::cout << getStringFromCPInfo(frame->getConstantPool(), index) << "\n";
    if(!cpInterfaceMethodref->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    std::string descriptor = getStringFromCPInfo(frame->getConstantPool(), cpNameAndType->descriptorIndex);
    uint32_t qtdOperandStack = 1 + sizeArguments(descriptor);

    uint32_t* vetAux = nullptr;
    if(qtdOperandStack > 0){
        vetAux = new uint32_t[qtdOperandStack];
    }
    for(uint32_t i = 0; i < qtdOperandStack; i++){
        vetAux[i] = frame->topOperandStack();
        frame->popOperandStack();
    }

    for(uint32_t i = 0; i < qtdOperandStack/2; i++){
        std::swap(vetAux[i], vetAux[qtdOperandStack - i - 1]);
    }
    
    if(vetAux[0] == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        delete[] vetAux;
        return pc + 4;
    }
    
    ObjectReference* object = runTimeData ->objectAt(vetAux[0]);
    // uint32_t classNum = cpInterfaceMethodref->classNum;
    std::map<uint32_t, uint32_t *> aux = *classLoader->getIterfaceMethodLocalization(object->classNum);
    uint32_t desloc = classLoader->getIterfaceMethodLocalization(object->classNum)->at(cpInterfaceMethodref->classNum)[cpInterfaceMethodref->instanceMethodDesloc];
    MethodInfo* newMethod = runTimeData->objectAt(vetAux[0])->methods[desloc];
    Frame* newFrame = Frame::CreateFrame(newMethod);
    *nextFrame = newFrame;
    *nextMethod = newMethod;
    for(uint32_t i = 0; i < qtdOperandStack; i++){
        newFrame->varAt(i) = vetAux[i];
    }
    if(qtdOperandStack > 0){
        delete[] vetAux;
    }
    isInvokeInstruction = true;
    frame->pushOperandStack(pc + 4);
    
    return pc + 4;
}

int32_t execOp_invokedynamic(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_new(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPClass *cp = dynamic_cast<CPClass*>(frame->getConstantPool()[index]);
    if(!cp->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    ObjectReference *pointer = new ObjectReference();
    pointer->classFile = cp->classFile;
    pointer->classNum = cp->classNum;
    pointer->createData(cp->instanceFieldSize);
    pointer->metSize = cp->instanceMethodSize;
    pointer->classFile = cp->classFile;
    pointer->methods = classLoader->getMethodTable(pointer->classNum);
    runTimeData->pushHeap(pointer);
    frame->pushOperandStack(runTimeData->heapSize());
    return pc + 3;
}

int32_t execOp_newarray(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t atype, arrayref = 0;
    int32_t count;
    atype = read<uint8_t>(attrinbuteCode->code + pc + 1);
    count = frame->topOperandStack();
    frame->popOperandStack();

    if(count < 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NegativeArraySizeException", wasException);
        
        return pc + 3;
    }
    
    ObjectReference *pointer = new ObjectReference();
    ArrayReference *arrayReference = nullptr;
    if(atype == 4){
        pointer->createArrayReference('Z', 1);
    } else if(atype == 5){
        pointer->createArrayReference('C', 1);
    } else if(atype == 6){
        pointer->createArrayReference('F', 1);
    } else if(atype == 7){
        pointer->createArrayReference('D', 1);
    } else if(atype == 8){
        pointer->createArrayReference('B', 1);
    } else if(atype == 9){
        pointer->createArrayReference('S', 1);
    } else if(atype == 10){
        pointer->createArrayReference('I', 1);
    } else if(atype == 11){
        pointer->createArrayReference('J', 1);
    }
    arrayReference = pointer->arrayReference;
    arrayReference->createData(count);
    pointer->classFile = nullptr;

    std::pair<MethodInfo**, uint32_t> objectInfo = classLoader->getObejectInfo();
    pointer->methods = objectInfo.first;
    pointer->createData(objectInfo.second);
    runTimeData->pushHeap(pointer);
    arrayref = runTimeData->heapSize();
    frame->pushOperandStack(arrayref);

    return pc + 2;
}

int32_t execOp_anewarray(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    uint32_t arrayref = 0;
    
    CPClass *cp = dynamic_cast<CPClass*>(frame->getConstantPool()[index]);
    if(!cp->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    
    std::string nameClass = getStringFromCPInfo(frame->getConstantPool(), cp->nameIndex);
    uint32_t realDimensions = 1 + std::count(nameClass.begin(),nameClass.end(),'[');
    uint32_t count = frame->topOperandStack();
    frame->popOperandStack();
    if(count < 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NegativeArraySizeException", wasException);
        
        return pc + 3;
    }
    
    ObjectReference *pointer = new ObjectReference();
    // ArrayReference *arrayReference = nullptr;
    // arrayReference = pointer->arrayReference;
    // arrayReference->createData(count);
    pointer->classFile = nullptr;

    std::pair<MethodInfo**, uint32_t> objectInfo = classLoader->getObejectInfo();
    pointer->methods = objectInfo.first;
    pointer->createData(objectInfo.second);
    runTimeData->pushHeap(pointer);
    arrayref = runTimeData->heapSize();
    frame->pushOperandStack(arrayref);

    pointer->classFile = cp->classFile;
    pointer->classNum = cp->classNum;
    pointer->createArrayReference('L', realDimensions);
    ArrayReference *arrayReference = pointer->arrayReference;
    arrayReference->createData(count);
    

    return pc + 3;
}

int32_t execOp_arraylength(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t arrayref, length = 0;
    arrayref = frame->topOperandStack();
    frame->popOperandStack();
    
    if(arrayref == 0){
        generateException(classLoader, runTimeData, execEngine, "java/lang/NullPointerException", wasException);
        
        return pc + 1;
    }
    ObjectReference *pointer = runTimeData->objectAt(arrayref);
    length = pointer->arrayReference->size;
    frame->pushOperandStack(length);

    return pc + 1;
}

int32_t execOp_athrow(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    wasException = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_checkcast(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    uint32_t objectref  = frame->topOperandStack();
    frame->popOperandStack();
    
    CPClass *cp = dynamic_cast<CPClass*>(frame->getConstantPool()[index]);
    if(!cp->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    
    if(objectref != 0){
        ObjectReference* pointerSource =  runTimeData->objectAt(objectref);
        uint32_t dimensionsSource = pointerSource->arrayReference == nullptr ? 0 : pointerSource->arrayReference->dimensions;
        uint32_t classNumSource = pointerSource->classNum;
        uint8_t primitiveTypeSource = pointerSource->arrayReference == nullptr ? 'L' : pointerSource->arrayReference->tipo;
        uint32_t dimensionsTarget = cp->dimensions;
        uint32_t classNumTarget = cp->classNum;
        uint8_t primitiveTypeTarget = cp->primitiveType;
        if(!objectsAreCompatibles(classLoader, dimensionsSource, classNumSource, primitiveTypeSource, dimensionsTarget, classNumTarget, primitiveTypeTarget)){
            generateException(classLoader, runTimeData, execEngine, "java/lang/ClassCastException", wasException);

            return pc + 3;
        } 
    }

    frame->pushOperandStack(objectref);

    return pc + 3;
}

int32_t execOp_instanceof(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    uint32_t objectref  = frame->topOperandStack();
    frame->popOperandStack();
    
    CPClass *cp = dynamic_cast<CPClass*>(frame->getConstantPool()[index]);
    if(!cp->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    
    if(objectref != 0){
        ObjectReference* pointerSource =  runTimeData->objectAt(objectref);
        uint32_t dimensionsSource = pointerSource->arrayReference == nullptr ? 0 : pointerSource->arrayReference->dimensions;
        uint32_t classNumSource = pointerSource->classNum;
        uint8_t primitiveTypeSource = pointerSource->arrayReference == nullptr ? 'L' : pointerSource->arrayReference->tipo;
        uint32_t dimensionsTarget = cp->dimensions;
        uint32_t classNumTarget = cp->classNum;
        uint8_t primitiveTypeTarget = cp->primitiveType;
        if(objectsAreCompatibles(classLoader, dimensionsSource, classNumSource, primitiveTypeSource, dimensionsTarget, classNumTarget, primitiveTypeTarget)){     
            frame->pushOperandStack(1);
        } else{
            frame->pushOperandStack(0);
        }
    } else{
        frame->pushOperandStack(0);
    }
        
    return pc + 3;
}

int32_t execOp_monitorenter(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_monitorexit(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_wide(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return ExecutionEngine::execIntruction[attrinbuteCode->code[pc+1]](classLoader, runTimeData, execEngine, pc+1, frame, method, attrinbuteCode, returnStack, nextMethod, nextFrame, finished, isInvokeInstruction, true, wasException);
}

int32_t execOp_multianewarray(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    uint32_t index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    uint32_t dimensions = read<uint8_t>(attrinbuteCode->code + pc + 3);
    uint32_t arrayref = 0;
    
    CPClass *cp = dynamic_cast<CPClass*>(frame->getConstantPool()[index]);
    if(!cp->wasLoaded){
        classLoader->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    
    std::string nameClass = getStringFromCPInfo(frame->getConstantPool(), cp->nameIndex);
    uint32_t realDimensions = std::count(nameClass.begin(),nameClass.end(),'[');
    int32_t* counts = new int32_t[dimensions];
    for(int32_t i = dimensions-1; i >= 0; i--){
        counts[i] = frame->topOperandStack();
        frame->popOperandStack();
        if(counts[i] < 0){
            generateException(classLoader, runTimeData, execEngine, "java/lang/NegativeArraySizeException", wasException);
            
            return pc + 4;
        }
    }
    
    ObjectReference *pointer = new ObjectReference();
    // ArrayReference *arrayReference = nullptr;
    // arrayReference = pointer->arrayReference;
    // arrayReference->createData(count);
    pointer->classFile = nullptr;

    std::pair<MethodInfo**, uint32_t> objectInfo = classLoader->getObejectInfo();
    pointer->methods = objectInfo.first;
    pointer->createData(objectInfo.second);
    runTimeData->pushHeap(pointer);
    arrayref = runTimeData->heapSize();
    frame->pushOperandStack(arrayref);
    std::queue<std::pair<uint32_t, ObjectReference*>> queue;
    queue.push({0, pointer});
    while(!queue.empty()){
        uint32_t level = queue.front().first;
        ObjectReference* curPointer = queue.front().second;
        queue.pop();

        curPointer->classFile = cp->classFile;
        curPointer->classNum = cp->classNum;
        curPointer->createArrayReference(nameClass[realDimensions], realDimensions-level);
        ArrayReference *arrayReference = dynamic_cast<ArrayReference*>(curPointer->arrayReference);
        arrayReference->createData(counts[level]);
        if(level + 1 < dimensions){
            ArrayType<uint32_t> *array = dynamic_cast<ArrayType<uint32_t>*>(arrayReference);

            for(int32_t i = 0; i < counts[level]; i++){
                ObjectReference *nextPointer = new ObjectReference(); 
                nextPointer->classFile = cp->classFile;
                nextPointer->classNum = cp->classNum;
                nextPointer->methods = objectInfo.first;
                nextPointer->createData(objectInfo.second);
                runTimeData->pushHeap(nextPointer);
                array->data[i] = runTimeData->heapSize();
                queue.push({level + 1, nextPointer});
            }
        }
    }

    delete[] counts;
    
    return pc + 4;
}

int32_t execOp_ifnull(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value;
    int16_t branchbyte = 3;
    value.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value.i == 0){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_ifnonull(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    union{
        uint32_t u;
        int32_t i;
    } value;
    int16_t branchbyte = 3;
    value.u = frame->topOperandStack();
    frame->popOperandStack();

    if(value.i != 0){
        branchbyte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    }    

    return pc + branchbyte;
}

int32_t execOp_goto_w(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

int32_t execOp_jsr_w(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide, uint32_t& wasException){
    return pc + 0;
}

const std::array<std::function<int32_t(ClassLoader*, RuntimeDataArea*, ExecutionEngine*, uint32_t, Frame*, MethodInfo*, AttributeInfoCode*, LinearStack<uint32_t>&, MethodInfo**, Frame**, bool&, bool&, bool, uint32_t&)>, 0xC9 + 1> ExecutionEngine::execIntruction{{
    
    execOp_nop, // 0x00
    execOp_aconst_null, // 0x01
    execOp_iconst_m1, // 0x02
    execOp_iconst_0, // 0x03
    execOp_iconst_1, // 0x04
    execOp_iconst_2, // 0x05  
    execOp_iconst_3, // 0x06
    execOp_iconst_4, // 0x07
    execOp_iconst_5, // 0x08
    execOp_lconst_0, // 0x09
    execOp_lconst_1, // 0x0A
    execOp_fconst_0, // 0x0B
    execOp_fconst_1, // 0x0C
    execOp_fconst_2, // 0x0D
    execOp_dconst_0, // 0x0E
    execOp_dconst_1, // 0x0F
    execOp_bipush, // 0x10 
    execOp_sipush, // 0x11
    execOp_ldc, // 0x12
    execOp_ldc_w, // 0x13
    execOp_ldc2_w, // 0x14
    execOp_iload, // 0x15
    execOp_lload, // 0x16
    execOp_fload, // 0x17
    execOp_dload, // 0x18
    execOp_aload, // 0x19
    execOp_iload_0, // 0x1A
    execOp_iload_1, // 0x1B 
    execOp_iload_2, // 0x1C
    execOp_iload_3, // 0x1D
    execOp_lload_0, // 0x1E
    execOp_lload_1, // 0x1F
    execOp_lload_2, // 0x20
    execOp_lload_3, // 0x21
    execOp_fload_0, // 0x22
    execOp_fload_1, // 0x23
    execOp_fload_2, // 0x24
    execOp_fload_3, // 0x25
    execOp_dload_0, // 0x26
    execOp_dload_1, // 0x27
    execOp_dload_2, // 0x28
    execOp_dload_3, // 0x29
    execOp_aload_0, // 0x2A 
    execOp_aload_1, // 0x2B
    execOp_aload_2, // 0x2C
    execOp_aload_3, // 0x2D
    execOp_iaload, // 0x2E
    execOp_laload, // 0x2F
    execOp_faload, // 0x30
    execOp_daload, // 0x31
    execOp_aaload, // 0x32
    execOp_baload, // 0x33
    execOp_caload, // 0x34
    execOp_saload, // 0x35
    execOp_istore, // 0x36
    execOp_lstore, // 0x37
    execOp_fstore, // 0x38
    execOp_dstore, // 0x39
    execOp_astore, // 0x3A
    execOp_istore_0, // 0x3B
    execOp_istore_1, // 0x3C 
    execOp_istore_2, // 0x3D
    execOp_istore_3, // 0x3E
    execOp_lstore_0, // 0x3F
    execOp_lstore_1, // 0x40
    execOp_lstore_2, // 0x41
    execOp_lstore_3, // 0x42
    execOp_fstore_0, // 0x43
    execOp_fstore_1, // 0x44
    execOp_fstore_2, // 0x45
    execOp_fstore_3, // 0x46
    execOp_dstore_0, // 0x47
    execOp_dstore_1, // 0x48
    execOp_dstore_2, // 0x49
    execOp_dstore_3, // 0x4A
    execOp_astore_0, // 0x4B
    execOp_astore_1, // 0x4C
    execOp_astore_2, // 0x4D
    execOp_astore_3, // 0x4E
    execOp_iastore, // 0x4F
    execOp_lastore, // 0x50
    execOp_fastore, // 0x51
    execOp_dastore, // 0x52
    execOp_aastore, // 0x53
    execOp_bastore, // 0x54
    execOp_castore, // 0x55
    execOp_sastore, // 0x56
    execOp_pop, // 0x57
    execOp_pop2, // 0x58
    execOp_dup, // 0x59
    execOp_dup_x1, // 0x5A
    execOp_dup_x2, // 0x5B
    execOp_dup2, // 0x5C
    execOp_dup2_x1, // 0x5D
    execOp_dup2_x2, // 0x5E
    execOp_swap, // 0x5F
    execOp_iadd, // 0x60
    execOp_ladd, // 0x61
    execOp_fadd, // 0x62
    execOp_dadd, // 0x63
    execOp_isub, // 0x64
    execOp_lsub, // 0x65
    execOp_fsub, // 0x66
    execOp_dsub, // 0x67
    execOp_imul, // 0x68
    execOp_lmul, // 0x69
    execOp_fmul, // 0x6A
    execOp_dmul, // 0x6B
    execOp_idiv, // 0x6C
    execOp_ldiv, // 0x6D
    execOp_fdiv, // 0x6E
    execOp_ddiv, // 0x6F
    execOp_irem, // 0x70
    execOp_lrem, // 0x71
    execOp_frem, // 0x72
    execOp_drem, // 0x73
    execOp_ineg, // 0x74
    execOp_lneg, // 0x75
    execOp_fneg, // 0x76
    execOp_dneg, // 0x77
    execOp_ishl, // 0x78
    execOp_lshl, // 0x79
    execOp_ishr, // 0x7A
    execOp_lshr, // 0x7B
    execOp_iushr, // 0x7C
    execOp_lushr, // 0x7D
    execOp_iand, // 0x7E
    execOp_land, // 0x7F
    execOp_ior, // 0x80
    execOp_lor, // 0x81
    execOp_ixor, // 0x82
    execOp_lxor, // 0x83
    execOp_iinc, // 0x84
    execOp_i2l, // 0x85
    execOp_i2f, // 0x86
    execOp_i2d, // 0x87
    execOp_l2i, // 0x88
    execOp_l2f, // 0x89
    execOp_l2d, // 0x8A
    execOp_f2i, // 0x8B
    execOp_f2l, // 0x8C
    execOp_f2d, // 0x8D
    execOp_d2i, // 0x8E
    execOp_d2l, // 0x8F
    execOp_d2f, // 0x90
    execOp_i2b, // 0x91
    execOp_i2c, // 0x92
    execOp_i2s, // 0x93
    execOp_lcmp, // 0x94
    execOp_fcmpl, // 0x95
    execOp_fcmpg, // 0x96
    execOp_dcmpl, // 0x97
    execOp_dcmpg, // 0x98
    execOp_ifeq, // 0x99
    execOp_ifne, // 0x9A
    execOp_iflt, // 0x9B
    execOp_ifge, // 0x9C
    execOp_ifgt, // 0x9D
    execOp_ifle, // 0x9E
    execOp_if_icmpeq, // 0x9F
    execOp_if_icmpne, // 0xA0
    execOp_if_icmplt, // 0xA1
    execOp_if_icmpge, // 0xA2
    execOp_if_icmpgt, // 0xA3
    execOp_if_icmple, // 0xA4
    execOp_if_acmpeq, // 0xA5
    execOp_if_acmpne, // 0xA6
    execOp_goto, // 0xA7
    execOp_jsr, // 0xA8
    execOp_ret, // 0xA9
    execOp_tableswitch, // 0xAA 
    execOp_lookupswitch, // 0xAB 
    execOp_ireturn, // 0xAC
    execOp_lreturn, // 0xAD
    execOp_freturn, // 0xAE
    execOp_dreturn, // 0xAF
    execOp_areturn, // 0xB0
    execOp_return, // 0xB1 
    execOp_getstatic, // 0xB2 
    execOp_putstatic, // 0xB3
    execOp_getfield, // 0xB4
    execOp_putfield, // 0xB5
    execOp_invokevirtual, // 0xB6
    execOp_invokespecial, // 0xB7
    execOp_invokestatic, // 0xB8
    execOp_invokeinterface, // 0xB9 
    execOp_invokedynamic, // 0xBA
    execOp_new, // 0xBB
    execOp_newarray, // 0xBC
    execOp_anewarray, // 0xBD
    execOp_arraylength, // 0xBE
    execOp_athrow, // 0xBF
    execOp_checkcast, // 0xC0
    execOp_instanceof, // 0xC1
    execOp_monitorenter, // 0xC2
    execOp_monitorexit, // 0xC3
    execOp_wide, // 0xC4 wide
    execOp_multianewarray, // 0xC5
    execOp_ifnull, // 0xC6
    execOp_ifnonull, // 0xC7
    execOp_goto_w, // 0xC8
    execOp_jsr_w // 0xC9
}};

void ExecutionEngine::execFrame(Frame *frame, MethodInfo* methodInfo, uint32_t& pc, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, uint32_t& wasException){
    
    bool isInvokeInstruction = false;
    AttributeInfoCode* attributeCode = dynamic_cast<AttributeInfoCode*>(methodInfo->getAttribute("Code"));
    while(!isInvokeInstruction && !finished){
        if(wasException == 0){
            pc = ExecutionEngine::execIntruction[attributeCode->code[pc]](classLoader, runtimeDataArea, this, pc, frame, methodInfo, attributeCode, returnStack, nextMethod, nextFrame, finished, isInvokeInstruction, false, wasException);
        } else{
            bool wasCatched = false;
            uint32_t exceptionClassNum = runtimeDataArea->objectAt(wasException)->classNum;
            for(uint32_t i = 0; i < attributeCode->exceptionTableLength && !wasCatched; i++){
                if(attributeCode->exceptionTable[i].startPc <= pc && pc <= attributeCode->exceptionTable[i].endPc){
                    if(attributeCode->exceptionTable[i].catchType != 0){
                        CPClass *cp = dynamic_cast<CPClass*>(frame->getConstantPool()[attributeCode->exceptionTable[i].catchType]);
                        if(!cp->wasLoaded){
                            classLoader->resolveConstantPoolAt(frame->getConstantPool(), attributeCode->exceptionTable[i].catchType);
                        }
                        uint32_t catchClassNum = cp->classNum;

                        if(classLoader->parentOf(catchClassNum, exceptionClassNum)){
                            wasCatched = true;
                            frame->pushOperandStack(wasException);
                            wasException = 0;
                            pc = attributeCode->exceptionTable[i].handlerPc;
                        }
                    } else{
                        wasCatched = true;
                        pc = attributeCode->exceptionTable[i].handlerPc;
                    }
                }
            }
            if(!wasCatched){
                finished = true;
            }
        }
    }
}
void ExecutionEngine::exec(MethodInfo* nextMethod, Frame* nextFrame){
    Thread& thread = runtimeDataArea->getThread();
    LinearStack<uint32_t> returnStack(2);
    DynamicStack<MethodInfo*> methodStack;
    // Frame* nextFrame = Frame::CreateFrame(nextMethod);
    uint32_t wasException = 0;
    methodStack.push(nextMethod);
    thread.pushFrameStack(nextFrame);
    nextMethod = nullptr;
    nextFrame = nullptr;
    bool finished = false;
    while(methodStack.size() > 0){
        finished = false;
        if(nextMethod != nullptr && nextFrame != nullptr){
            methodStack.push(nextMethod);
            thread.pushFrameStack(nextFrame);
            nextMethod = nullptr;
            nextFrame = nullptr;
        } else if(nextMethod != nullptr){
            // TODO Erro
            nextMethod = nullptr;
            continue;
        }
        Frame* topFrame = thread.topFrameStack();
        uint32_t &pc =  thread.getPC();
        pc = topFrame->topOperandStack();
        topFrame->popOperandStack();
        while(returnStack.size() > 0){
            topFrame->pushOperandStack(returnStack.top());
            returnStack.pop();
        }
        execFrame(topFrame, methodStack.top(), pc, returnStack, &nextMethod, &nextFrame, finished, wasException);
        if(finished){
            methodStack.pop();
            delete topFrame;
            thread.popFrameStack();
        }
    }
}
void ExecutionEngine::setRuntimeDataArea(RuntimeDataArea* new_runtimeDataArea){
    runtimeDataArea = new_runtimeDataArea;
}

void ExecutionEngine::setClassLoader(ClassLoader* new_classLoader){
    classLoader = new_classLoader;
}
