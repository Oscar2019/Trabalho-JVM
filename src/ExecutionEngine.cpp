#include "../include/ExecutionEngine.h"
#include <cstdint>
#include <string>
#include "../include/ClassLoader.h"
#include "../include/RuntimeDataArea.h"
#include "../include/MethodInfo.h"
#include "../include/tipos.h"
#include <codecvt>
#include <functional>

int32_t execOp_nop(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_aconst_null(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iconst_m1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iconst_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iconst_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iconst_2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iconst_3(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iconst_4(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iconst_5(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lconst_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lconst_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fconst_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fconst_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fconst_2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dconst_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dconst_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_bipush(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_sipush(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ldc(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ldc_w(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ldc2_w(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_aload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iload_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iload_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iload_2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iload_3(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lload_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lload_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lload_2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lload_3(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fload_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fload_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fload_2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fload_3(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dload_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dload_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dload_2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dload_3(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_aload_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_aload_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_aload_2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_aload_3(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iaload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_laload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_faload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_daload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_aaload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_baload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_caload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_saload(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_istore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lstore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fstore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dstore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_astore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_istore_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_istore_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_istore_2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_istore_3(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lstore_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lstore_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lstore_2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lstore_3(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fstore_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fstore_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fstore_2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fstore_3(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dstore_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dstore_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dstore_2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dstore_3(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_astore_0(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_astore_1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_astore_2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_astore_3(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iastore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lastore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fastore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dastore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_aastore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_bastore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_castore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_sastore(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_pop(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_pop2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dup(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dup_x1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dup_x2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dup2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dup2_x1(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dup2_x2(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_swap(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iadd(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ladd(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fadd(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dadd(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_isub(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lsub(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fsub(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dsub(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_imul(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lmul(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fmul(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dmul(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_idiv(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ldiv(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fdiv(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ddiv(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_irem(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lrem(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_frem(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_drem(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ineg(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lneg(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fneg(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dneg(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ishl(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lshl(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ishr(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lshr(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iushr(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lushr(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iand(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_land(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ior(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lor(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ixor(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lxor(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iinc(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_i2l(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_i2f(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_i2d(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_l2i(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_l2f(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_l2d(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_f2i(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_f2l(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_f2d(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_d2i(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_d2l(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_d2f(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_i2b(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_i2c(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_i2s(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lcmp(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fcmpl(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_fcmpg(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dcmpl(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dcmpg(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ifeq(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ifne(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_iflt(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ifge(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ifgt(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ifle(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_if_icmpeq(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_if_icmpne(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_if_icmplt(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_if_icmpge(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_if_icmpgt(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_if_icmple(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_if_acmpeq(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_if_acmpne(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_goto(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_jsr(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ret(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_tableswitch(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lookupswitch(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ireturn(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_lreturn(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_freturn(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_dreturn(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_areturn(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_return(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_getstatic(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_putstatic(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_getfield(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_putfield(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_invokevirtual(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_invokespecial(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_invokestatic(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_invokeinterface(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_invokedynamic(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_new(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_newarray(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_anewarray(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_arraylength(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_athrow(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_checkcast(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_instanceof(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_monitorenter(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_monitorexit(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_wide(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_multianewarray(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ifnull(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_ifnonull(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_goto_w(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

int32_t execOp_jsr_w(RuntimeDataArea* runTimeData, uint32_t pc, Frame* frame, MethodInfo* method, AttributeInfoCode* attrinbuteCode, bool& finished, bool& isInvokeInstruction){
    return pc + 0;
}

const std::array<std::function<int32_t(RuntimeDataArea*, uint32_t, Frame*, MethodInfo*, AttributeInfoCode*, bool&, bool&)>, 0xC9 + 1> ExecutionEngine::execIntruction{{
    
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
    execOp_ldc, // 0x12 ldc
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
    execOp_wide, // 0xC4
    execOp_multianewarray, // 0xC5
    execOp_ifnull, // 0xC6
    execOp_ifnonull, // 0xC7
    execOp_goto_w, // 0xC8
    execOp_jsr_w // 0xC9
}};

void ExecutionEngine::execFrame(Frame *frame, MethodInfo* methodInfo, uint32_t& pc, bool& finished){
}

void ExecutionEngine::exec(MethodInfo* nextMethod){
}

void ExecutionEngine::setRuntimeDataArea(RuntimeDataArea* new_runtimeDataArea){
    runtimeDataArea = new_runtimeDataArea;
}

void ExecutionEngine::setClassLoader(CassLoader* new_classLoader){
    classLoader = new_classLoader;
}
