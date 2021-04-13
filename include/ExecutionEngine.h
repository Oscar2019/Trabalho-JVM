#ifndef __EXECUTION_ENGINE_H__
#define __EXECUTION_ENGINE_H__

#include <cstdint>
#include <string>
// #include "../include/RuntimeDataArea.h"
// #include "../include/MethodInfo.h"
// #include "../include/ClassLoader.h"
#include <functional>


class RuntimeDataArea;
class Frame;
class MethodInfo;
class CassLoader;
template<typename T>
class LinearStack;
class AttributeInfoCode;


class ExecutionEngine{
    private:
        RuntimeDataArea* runtimeDataArea;
        CassLoader* classLoader;
        void execFrame(Frame *frame, MethodInfo* methodInfo, uint32_t& pc, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished);
    public:
        static const std::array<std::function<int32_t(CassLoader*, RuntimeDataArea*, uint32_t, Frame*, MethodInfo*, AttributeInfoCode*, LinearStack<uint32_t>&, MethodInfo**, Frame**, bool&, bool&, bool)>, 0xC9 + 1> execIntruction;
        void exec(MethodInfo* nextMethod);
        void setRuntimeDataArea(RuntimeDataArea* new_runtimeDataArea);
        void setClassLoader(CassLoader* new_classLoader);
};

#endif