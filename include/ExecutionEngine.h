#ifndef __EXECUTION_ENGINE_H__
#define __EXECUTION_ENGINE_H__

#include <cstdint>
#include <string>
// #include "../include/RuntimeDataArea.h"
// #include "../include/MethodInfo.h"
// #include "../include/ClassLoader.h"
#include <functional>
#include <codecvt>
#include <locale>


class RuntimeDataArea;
class Frame;
class MethodInfo;
class ClassLoader;
template<typename T>
class LinearStack;
class AttributeInfoCode;


class ExecutionEngine{
    private:
        RuntimeDataArea* runtimeDataArea;
        ClassLoader* classLoader;
        void execFrame(Frame *frame, MethodInfo* methodInfo, uint32_t& pc, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, uint32_t& wasException);
    public:
        static const std::array<std::function<int32_t(ClassLoader*, RuntimeDataArea*, ExecutionEngine*, uint32_t, Frame*, MethodInfo*, AttributeInfoCode*, LinearStack<uint32_t>&, MethodInfo**, Frame**, bool&, bool&, bool, uint32_t&)>, 0xC9 + 1> execIntruction;
        void exec(MethodInfo* nextMethod, Frame* nextFrame);
        void setRuntimeDataArea(RuntimeDataArea* new_runtimeDataArea);
        void setClassLoader(ClassLoader* new_classLoader);
};

#endif