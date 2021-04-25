#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include "../include/ClassLoader.h"
#include "../include/RuntimeDataArea.h"
#include "../include/ExecutionEngine.h"
#include <string>

void generateException(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, std::string strAux, uint32_t &wasException);

#endif