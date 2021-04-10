#ifndef __CLASS_LOADER_H__
#define __CLASS_LOADER_H__

#include <vector>
#include <utility>
#include <cstdint>
#include <iostream>
#include <map>
#include <stdexcept>
#include <stack>

#include "../include/Trie.h"
#include "../include/MethodInfo.h"
#include "../include/ClassFile.h"
#include "../include/RuntimeDataArea.h"
#include "../include/FileSystem.h"
#include "../include/ExecutionEngine.h"

class CassLoader{
    private:
        struct NodeContent{
            uint32_t classNum;

            ClassFile *classFile;
            
            bool wasResolved;

            uint32_t qtdMethodsInstancePriv;
            uint32_t qtdMethodsInstanceNoPriv;
            uint32_t qtdMethodsClassPriv;
            uint32_t qtdMethodsClassNoPriv;
            uint32_t sizeInstance;
            uint32_t qtdFieldsInstancePriv;
            uint32_t qtdFieldsInstanceNoPriv;
            uint32_t qtdFieldsClassPriv;
            uint32_t qtdFieldsClassNoPriv;

            std::map<uint32_t, uint32_t*> iterfaceMethodLocalization;

            MethodInfo **acessMehodsTable;

            Trie<MethodInfo*> constructor;
            MethodInfo* constantConstructor;
            Trie<MethodInfo*> methodsInstancePriv;
            Trie<std::pair<uint32_t, MethodInfo*>> methodsInstanceNoPriv;
            Trie<MethodInfo*> methodsClassPriv;
            Trie<MethodInfo*> methodsClassNoPriv;
            Trie<uint32_t> fieldsInstancePriv;
            Trie<uint32_t> fieldsInstanceNoPriv;
            Trie<void*> fieldsClassPriv;
            Trie<void*> fieldsClassNoPriv;

            NodeContent();
        };
        Trie<NodeContent*> tree;
        FileSystem fs;
        std::stack<std::string> classToLoad;
        std::stack<NodeContent*> classPrepare;
        std::stack<NodeContent*> classResolve;
        std::stack<NodeContent*> classInitialize;
        RuntimeDataArea *runtimeDataArea;
        ExecutionEngine *executionEngine;

        
        void readClass(std::string s);
        void prepareClass(NodeContent *nodeContent);
        void resolveClass(NodeContent *nodeContent);
        void inicializeClass(NodeContent *nodeContent);
    public:
        CassLoader(std::string &&s);

        void addClassToLoad(std::string s);

        void setRuntimeDataArea(RuntimeDataArea* new_runtimeDataArea);
        void setExecutionEngine(ExecutionEngine* new_executionEngine);

        void exec();

        void resolveConstantPoolAt(ConstantPoolInfo** cp, uint32_t ind);
       
};

#endif