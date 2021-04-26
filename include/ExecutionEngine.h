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

/**
 * @brief Representação de uma ExecutionEngine.
 * 
 */
class ExecutionEngine{
    private:
        /**
         * @brief RuntimeDataArea.
         * 
         */
        RuntimeDataArea* runtimeDataArea;
        /**
         * @brief ClassLoader
         * 
         */
        ClassLoader* classLoader;
        /**
         * @brief Função que executa um frame
         * 
         * @param frame 
         * @param methodInfo 
         * @param pc 
         * @param returnStack 
         * @param nextMethod 
         * @param nextFrame 
         * @param finished 
         * @param wasException 
         */
        void execFrame(Frame *frame, MethodInfo* methodInfo, uint32_t& pc, LinearStack<uint32_t>& returnStack, MethodInfo** nextMethod, Frame** nextFrame, bool& finished, uint32_t& wasException);
    public:
        /**
         * @brief Array de funções pra executar.
         * 
         */
        static const std::array<std::function<int32_t(ClassLoader*, RuntimeDataArea*, ExecutionEngine*, uint32_t, Frame*, MethodInfo*, AttributeInfoCode*, LinearStack<uint32_t>&, MethodInfo**, Frame**, bool&, bool&, bool, uint32_t&)>, 0xC9 + 1> execIntruction;
        /**
         * @brief Executa um metódo.
         * 
         * @param nextMethod 
         * @param nextFrame 
         */
        void exec(MethodInfo* nextMethod, Frame* nextFrame);
        /**
         * @brief Set the Runtime Data Area object
         * 
         * @param new_runtimeDataArea 
         */
        void setRuntimeDataArea(RuntimeDataArea* new_runtimeDataArea);
        /**
         * @brief Set the Class Loader object
         * 
         * @param new_classLoader 
         */
        void setClassLoader(ClassLoader* new_classLoader);
};

#endif