#include "../include/Exceptions.h"

void generateException(ClassLoader* classLoader, RuntimeDataArea* runTimeData, ExecutionEngine* execEngine, std::string strAux, uint32_t &wasException){
    
    ObjectReference *exception = new ObjectReference();
        
        
    // strAux = "java/lang/NullPointerException";
    static uint32_t exceptionClassNum = classLoader->getClassNum(strAux);
    strAux = "<init>:()V";
    static MethodInfo* exceptionConstructor =  classLoader->getContructor(exceptionClassNum, strAux);
    static uint32_t exceptionInstanceSize = classLoader->getInstanceSize(exceptionClassNum);
    // static std::map<uint32_t, uint32_t*>* exceptionIterfaceMethodLocalization = classLoader->getIterfaceMethodLocalization(exceptionClassNum);
    static MethodInfo** exceptionMethodTable =  classLoader->getMethodTable(exceptionClassNum);
    static ClassFile* exceptionClassFile =  classLoader->getClassFile(exceptionClassNum);

    exception->classNum = exceptionClassNum;
    exception->classFile = exceptionClassFile;
    exception->methods = exceptionMethodTable;
    exception->createData(exceptionInstanceSize);

    runTimeData->pushHeap(exception);
    Frame* newFrame = Frame::CreateFrame(exceptionConstructor);
    uint32_t exceptionObject = runTimeData->heapSize();
    newFrame->varAt(0) = exceptionObject;
    wasException = exceptionObject;
    // uint32_t entryPoint = newFrame->topOperandStack();
    // newFrame->popOperandStack();
    // newFrame->pushOperandStack(exceptionObject);
    // newFrame->pushOperandStack(entryPoint);

    execEngine->exec(exceptionConstructor, newFrame);
}