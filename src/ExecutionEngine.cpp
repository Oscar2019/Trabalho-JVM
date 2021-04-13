#include "../include/ExecutionEngine.h"
#include <cstdint>
#include <string>
#include "../include/ClassLoader.h"
#include "../include/RuntimeDataArea.h"
#include "../include/MethodInfo.h"
#include "../include/tipos.h"
#include "../include/Pointer.h"
#include <cmath>
#include <functional>

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



int32_t execOp_nop(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 1;
}

int32_t execOp_aconst_null(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iconst_m1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iconst_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iconst_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iconst_2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iconst_3(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iconst_4(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iconst_5(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lconst_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lconst_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fconst_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fconst_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fconst_2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dconst_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dconst_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_bipush(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    int32_t byte = static_cast<int8_t>(read<uint8_t>(attrinbuteCode->code + pc + 1));
    frame->pushOperandStack(byte);
    return pc + 2;
}

int32_t execOp_sipush(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    int32_t byte = static_cast<int16_t>(read<uint16_t>(attrinbuteCode->code + pc + 1));
    frame->pushOperandStack(byte);
    return pc + 3;
}

int32_t execOp_ldc(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    uint32_t index;
    index = read<uint8_t>(attrinbuteCode->code + pc + 1);
    ConstantPoolInfo *cp = frame->getConstantPool()[index];
    if(cp->tag == ConstantPoolInfoTag::INTEGER){
        CPInteger *cpInteger = dynamic_cast<CPInteger*>(cp);
        frame->pushOperandStack(cpInteger->bytes);
    } else if(cp->tag == ConstantPoolInfoTag::FLOAT){
        CPFloat *cpFloat = dynamic_cast<CPFloat*>(cp);
        frame->pushOperandStack(cpFloat->bytes);
    }
    return pc + 2;
}

int32_t execOp_ldc_w(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    ConstantPoolInfo *cp = frame->getConstantPool()[index];
    if(cp->tag == ConstantPoolInfoTag::INTEGER){
        CPInteger *cpInteger = dynamic_cast<CPInteger*>(cp);
        frame->pushOperandStack(cpInteger->bytes);
    } else if(cp->tag == ConstantPoolInfoTag::FLOAT){
        CPFloat *cpFloat = dynamic_cast<CPFloat*>(cp);
        frame->pushOperandStack(cpFloat->bytes);
    }
    return pc + 3;
}

int32_t execOp_ldc2_w(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
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

int32_t execOp_iload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_aload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iload_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    frame->pushOperandStack(frame->varAt(0));
    return pc + 1;
}

int32_t execOp_iload_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    frame->pushOperandStack(frame->varAt(1));
    return pc + 1;
}

int32_t execOp_iload_2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iload_3(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lload_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lload_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    frame->pushOperandStack(frame->varAt(1));
    frame->pushOperandStack(frame->varAt(2));
    return pc + 1;
}

int32_t execOp_lload_2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lload_3(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fload_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fload_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    frame->pushOperandStack(frame->varAt(1));
    return pc + 1;
}

int32_t execOp_fload_2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fload_3(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dload_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dload_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    frame->pushOperandStack(frame->varAt(1));
    frame->pushOperandStack(frame->varAt(2));
    return pc + 1;
}

int32_t execOp_dload_2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dload_3(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_aload_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    frame->pushOperandStack(frame->varAt(0));
    return pc + 1;
}

int32_t execOp_aload_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_aload_2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_aload_3(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iaload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_laload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_faload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_daload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_aaload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_baload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_caload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_saload(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_istore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lstore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fstore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dstore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_astore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_istore_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_istore_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    frame->varAt(1) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_istore_2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_istore_3(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lstore_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lstore_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    frame->varAt(2) = frame->topOperandStack();
    frame->popOperandStack();
    frame->varAt(1) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_lstore_2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lstore_3(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fstore_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fstore_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    frame->varAt(1) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_fstore_2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fstore_3(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dstore_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dstore_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    frame->varAt(2) = frame->topOperandStack();
    frame->popOperandStack();
    frame->varAt(1) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_dstore_2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dstore_3(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_astore_0(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_astore_1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    frame->varAt(1) = frame->topOperandStack();
    frame->popOperandStack();
    return pc + 1;
}

int32_t execOp_astore_2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_astore_3(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iastore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lastore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fastore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dastore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_aastore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_bastore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_castore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_sastore(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_pop(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_pop2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dup(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    frame->pushOperandStack(frame->topOperandStack());
    return pc + 1;
}

int32_t execOp_dup_x1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dup_x2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dup2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dup2_x1(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dup2_x2(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_swap(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iadd(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ladd(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fadd(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dadd(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
   return pc + 0;
}

int32_t execOp_isub(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lsub(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fsub(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dsub(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_imul(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lmul(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fmul(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dmul(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_idiv(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ldiv(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fdiv(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ddiv(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_irem(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lrem(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_frem(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_drem(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ineg(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lneg(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fneg(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dneg(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ishl(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lshl(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ishr(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lshr(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iushr(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lushr(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iand(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_land(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ior(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lor(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ixor(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lxor(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iinc(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
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

int32_t execOp_i2l(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_i2f(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_i2d(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_l2i(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_l2f(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_l2d(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_f2i(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_f2l(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_f2d(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_d2i(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_d2l(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_d2f(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_i2b(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_i2c(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_i2s(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lcmp(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fcmpl(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_fcmpg(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dcmpl(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dcmpg(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ifeq(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ifne(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_iflt(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ifge(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ifgt(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ifle(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_if_icmpeq(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_if_icmpne(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_if_icmplt(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_if_icmpge(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_if_icmpgt(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_if_icmple(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_if_acmpeq(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_if_acmpne(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_goto(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_jsr(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ret(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_tableswitch(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lookupswitch(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ireturn(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_lreturn(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_freturn(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_dreturn(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_areturn(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_return(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    finished = true;
    return pc + 1;
}

int32_t execOp_getstatic(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPFieldref* cpField = dynamic_cast<CPFieldref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpField->nameAndTypeIndex]);
    if(cpField->classFieldValue == nullptr){
        classLaoder->resolveConstantPoolAt(frame->getConstantPool(), index);
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

int32_t execOp_putstatic(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPFieldref* cpField = dynamic_cast<CPFieldref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpField->nameAndTypeIndex]);
    if(cpField->classFieldValue == nullptr){
        classLaoder->resolveConstantPoolAt(frame->getConstantPool(), index);
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

int32_t execOp_getfield(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_putfield(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_invokevirtual(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPMethodref* cpMeth = dynamic_cast<CPMethodref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpMeth->nameAndTypeIndex]);
    if(cpMeth->instanceMethodDesloc == -1){
        classLaoder->resolveConstantPoolAt(frame->getConstantPool(), index);
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

    MethodInfo* newMethod = runTimeData->objectAt(vetAux[0])->methods[cpMeth->instanceMethodDesloc];
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

int32_t execOp_invokespecial(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPMethodref* cpMeth = dynamic_cast<CPMethodref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpMeth->nameAndTypeIndex]);
    if(cpMeth->directMethod == nullptr){
        classLaoder->resolveConstantPoolAt(frame->getConstantPool(), index);
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
    isInvokeInstruction = true;
    frame->pushOperandStack(pc + 3);
    
    return pc + 3;
}

int32_t execOp_invokestatic(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPMethodref* cpMeth = dynamic_cast<CPMethodref*>(frame->getConstantPool()[index]);
    CPNameAndType* cpNameAndType = dynamic_cast<CPNameAndType*>(frame->getConstantPool()[cpMeth->nameAndTypeIndex]);
    if(cpMeth->directMethod == nullptr){
        classLaoder->resolveConstantPoolAt(frame->getConstantPool(), index);
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
                uint8_t value = frame->topOperandStack();
                frame->popOperandStack();
                std::cout << value; // ATENÇÃO
            } else if(nameMethod == "print_byte:(B)V"){
                uint32_t value = frame->topOperandStack();
                frame->popOperandStack();
                std::cout << value;
            } else if(nameMethod == "print_short:(S)V"){
                uint32_t value = frame->topOperandStack();
                frame->popOperandStack();
                std::cout << value;
            } else if(nameMethod == "print_bool:(Z)V"){
                bool value = frame->topOperandStack();
                frame->popOperandStack();
                std::cout << value;
            } else if(nameMethod == "print_long:(J)V"){
                uint64_t value = frame->topOperandStack();
                frame->popOperandStack();
                value |= static_cast<uint64_t>(frame->topOperandStack()) << 32;
                frame->popOperandStack();
                std::cout << value;
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
            }
        }
    }
    
    return pc + 3;
}

int32_t execOp_invokeinterface(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_invokedynamic(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_new(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    uint32_t index;
    index = read<uint16_t>(attrinbuteCode->code + pc + 1);
    CPClass *cp = dynamic_cast<CPClass*>(frame->getConstantPool()[index]);
    if(!cp->wasLoaded){
        classLaoder->resolveConstantPoolAt(frame->getConstantPool(), index);
    }
    Pointer *pointer = new Pointer();
    if(cp->instanceFieldSize > 0){
        pointer->data = new uint8_t[cp->instanceFieldSize];
    }
    pointer->metSize = cp->instanceMethodSize;
    pointer->methods = cp->instanceMethodPointer;
    runTimeData->pushHeap(pointer);
    frame->pushOperandStack(runTimeData->heapSize());
    return pc + 3;
}

int32_t execOp_newarray(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_anewarray(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_arraylength(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_athrow(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_checkcast(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_instanceof(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_monitorenter(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_monitorexit(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_wide(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return ExecutionEngine::execIntruction[attrinbuteCode->code[pc+1]](classLaoder, runTimeData, pc+1, frame, method, attrinbuteCode, returnStack, nextMethod, nextFrame, finished, isInvokeInstruction, true);
}

int32_t execOp_multianewarray(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ifnull(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_ifnonull(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_goto_w(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

int32_t execOp_jsr_w(CassLoader* classLaoder, RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, bool& isInvokeInstruction, bool isWide){
    return pc + 0;
}

const std::array<std::function<int32_t(CassLoader*, RuntimeDataArea*, uint32_t, Frame*, MethodInfo*, AttributeInfoCode*, LinearStack<uint32_t>&, MethodInfo**, Frame**, bool&, bool&, bool)>, 0xC9 + 1> ExecutionEngine::execIntruction{{
    
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

void ExecutionEngine::execFrame(Frame *frame, MethodInfo* methodInfo, uint32_t& pc, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished){
    
    bool isInvokeInstruction = false;
    AttributeInfoCode* attributeCode = dynamic_cast<AttributeInfoCode*>(methodInfo->getAttribute("Code"));
    while(!isInvokeInstruction && !finished){
        pc = ExecutionEngine::execIntruction[attributeCode->code[pc]](classLoader, runtimeDataArea, pc, frame, methodInfo, attributeCode, returnStack, nextMethod, nextFrame, finished, isInvokeInstruction, false);
    }
}
void ExecutionEngine::exec(MethodInfo* nextMethod){
    Thread& thread = runtimeDataArea->getThread();
    LinearStack<uint32_t> returnStack(2);
    DynamicStack<MethodInfo*> methodStack;
    Frame* nextFrame = Frame::CreateFrame(nextMethod);
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
        execFrame(topFrame, methodStack.top(), pc, returnStack, &nextMethod, &nextFrame, finished);
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

void ExecutionEngine::setClassLoader(CassLoader* new_classLoader){
    classLoader = new_classLoader;
}
