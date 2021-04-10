#include "../include/ClassLoader.h"



bool isSameClass(std::string s1, std::string s2){
    return s1 == s2;
}

CassLoader::NodeContent::NodeContent(){
    classNum = 0;
    classFile = nullptr;
    wasResolved = false;
    qtdMethodsInstancePriv = 0;
    qtdMethodsInstanceNoPriv = 0;
    qtdMethodsClassPriv = 0;
    qtdMethodsClassNoPriv = 0;
    sizeInstance = 0; 
    qtdFieldsInstancePriv = 0;
    qtdFieldsInstanceNoPriv = 0;
    qtdFieldsClassPriv = 0;
    qtdFieldsClassNoPriv = 0;
    constantConstructor = nullptr;
    acessMehodsTable = nullptr;
}

void CassLoader::readClass(std::string s){
}

void CassLoader::prepareClass(NodeContent *nodeContent){
}
        
void CassLoader::resolveClass(NodeContent *nodeContent){
}

void CassLoader::inicializeClass(NodeContent *nodeContent){
}

CassLoader::CassLoader(std::string &&s) : fs(s){
    runtimeDataArea = nullptr;
    executionEngine = nullptr;
}

void CassLoader::addClassToLoad(std::string s){
    s = fs.javaToEnvironmentPathNotation(s);
    classToLoad.push(s);
}

void CassLoader::setRuntimeDataArea(RuntimeDataArea* new_runtimeDataArea){
    runtimeDataArea = new_runtimeDataArea;
}
void CassLoader::setExecutionEngine(ExecutionEngine* new_executionEngine){
    executionEngine = new_executionEngine;
}

void CassLoader::exec(){
    while(!classToLoad.empty() || !classPrepare .empty() || !classResolve .empty() || !classInitialize.empty()){
        if(!classInitialize.empty()){
            inicializeClass(classInitialize.top());
        } else if(!classToLoad.empty()){
            readClass(classToLoad.top());
        } else if(!classPrepare.empty()){
            prepareClass(classPrepare.top());
        } else if(!classResolve.empty()){
            resolveClass(classResolve.top());
        }
    }
}

void CassLoader::resolveConstantPoolAt(ConstantPoolInfo** cp, uint32_t ind){
    
}
       