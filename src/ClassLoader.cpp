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

bool CassLoader::interfacesAreLoaded(NodeContent *nodeContent){
    ClassFile *cf = nodeContent->classFile;
    for(uint i = 0; i < cf->interfacesCount; i++){
        std::string s = getStringFromCPInfo(cf->constantPool, cf->interfaces[i]);
        if(!tree.hasKey(s)){
            return false;
        } else if(!tree.getValue(s)->wasResolved){
            throw std::string("Heranca Circular");
        }
    }
    return true;
}

void CassLoader::addInterfacesToLoad(NodeContent *nodeContent){
    ClassFile *cf = nodeContent->classFile;
    for(uint i = 0; i < cf->interfacesCount; i++){
        std::string s = getStringFromCPInfo(cf->constantPool, cf->interfaces[i]);
        addClassToLoad(s);
    }
}

void CassLoader::readClass(std::string s){
    if(!tree.hasKey(s)){

        std::ifstream is;
        is.open(fs.getJavaClassPath() + s + ".class", std::ios::binary);
        if(!is.is_open()){
            is.open(s + ".class", std::ios::binary);
            // std::cerr << "Arquivo \"" + s + ".class\" nao foi encontrado\n"; 
            // return -1;
        }
        is.exceptions(std::ifstream::eofbit);
        ClassFile *cf = new ClassFile();
        runtimeDataArea->pushMethodArea(new DestructSimple<ClassFile>(cf));
        try{
            read<ClassFile>(is, cf);
            // try{
            //     is.peek();
            // } catch(std::exception &e){
            //     Terminou com sucesso
            // }
        } catch(ClassFormatError &e){
            std::cerr << e.what() << "\n";
            // return -1;
        } catch(UnsupportedClassVersionError &e){
            std::cerr << e.what() << "\n";
            // return -1;
        } catch(std::exception &e){
            std::cerr << e.what() << "\n";
            // return -1;
        } catch( ... ){
            std::cerr << "Um erro qualquer\n";
            // return -1;
        }
        if(!isSameClass(getStringFromCPInfo(cf->constantPool, cf->thisClass), s)){
            std::cerr << "Nome do arquivo diferente do nome da classe\n";
            // return -1;
        }
        conveterAttributeInfoInClassFile(cf->constantPool, cf);
        NodeContent *nodeContent = new NodeContent();
        runtimeDataArea->pushMethodArea(new DestructSimple<NodeContent>(nodeContent));
        nodeContent->classNum = tree.size();
        nodeContent->classFile = cf;
        tree.insert(s, nodeContent);
        classToLoad.pop();
        classPrepare.push(nodeContent);
    } else{
        classToLoad.pop();
    }
}
void CassLoader::prepare(NodeContent *nodeContent){
    ClassFile * cf = nodeContent->classFile;
    for(uint32_t i = 0; i < cf->fieldsCount; i++){
        if(cf->fields[i].accessFlags & 0x0008){
            std::string name = getCPUtf8(cf->constantPool, cf->fields[i].nameIndex);
            std::string descriptor = getCPUtf8(cf->constantPool, cf->fields[i].descriptorIndex);
            std::string field = name + ":" + descriptor;
            if(cf->fields[i].accessFlags & 0x0002){
                if(descriptor[0] == 'B'){
                    uint8_t *value = new uint8_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint8_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'C'){
                    uint16_t *value = new uint16_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint16_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'D'){
                    double *value = new double;
                    runtimeDataArea->pushMethodArea(new DestructSimple<double>(value));
                    *value = 0;
                    nodeContent->fieldsClassPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'F'){
                    float *value = new float;
                    runtimeDataArea->pushMethodArea(new DestructSimple<float>(value));
                    *value = 0;
                    nodeContent->fieldsClassPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'I'){
                    uint32_t *value = new uint32_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint32_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'J'){
                    uint64_t *value = new uint64_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint64_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'S'){
                    uint16_t *value = new uint16_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint16_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'Z'){
                    uint8_t *value = new uint8_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint8_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'L'){
                    uint32_t *value = new uint32_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint32_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassPriv.insert(field, (void*)value);
                } else if(descriptor[0] == '['){
                    uint32_t *value = new uint32_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint32_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassPriv.insert(field, (void*)value);
                }
            } else{
                if(descriptor[0] == 'B'){
                    uint8_t *value = new uint8_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint8_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassNoPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'C'){
                    uint16_t *value = new uint16_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint16_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassNoPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'D'){
                    double *value = new double;
                    runtimeDataArea->pushMethodArea(new DestructSimple<double>(value));
                    *value = 0;
                    nodeContent->fieldsClassNoPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'F'){
                    float *value = new float;
                    runtimeDataArea->pushMethodArea(new DestructSimple<float>(value));
                    *value = 0;
                    nodeContent->fieldsClassNoPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'I'){
                    uint32_t *value = new uint32_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint32_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassNoPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'J'){
                    uint64_t *value = new uint64_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint64_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassNoPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'S'){
                    uint16_t *value = new uint16_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint16_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassNoPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'Z'){
                    uint8_t *value = new uint8_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint8_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassNoPriv.insert(field, (void*)value);
                } else if(descriptor[0] == 'L'){
                    uint32_t *value = new uint32_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint32_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassNoPriv.insert(field, (void*)value);
                } else if(descriptor[0] == '['){
                    uint32_t *value = new uint32_t;
                    runtimeDataArea->pushMethodArea(new DestructSimple<uint32_t>(value));
                    *value = 0;
                    nodeContent->fieldsClassNoPriv.insert(field, (void*)value);
                }
            }
        }
    }
    classPrepare.pop();
    classResolve.push(nodeContent);
}
        
void CassLoader::resolve(NodeContent *nodeContent){
    ClassFile * cf = nodeContent->classFile;
    if(cf->superClass == 0){
        for(uint32_t i = 0; i < cf->methodsCount; i++){
            std::string methodName = getStringFromCPInfo(cf->constantPool, cf->methods[i].nameIndex);
            std::string methodDescriptor = getStringFromCPInfo(cf->constantPool, cf->methods[i].descriptorIndex);
            std::string method = methodName + ":" + methodDescriptor;
            cf->methods[i].cp = cf->constantPool;
            if(methodName == "<init>"){
                nodeContent->constructor.insert(method, cf->methods + i);
            } else if(methodName == "<clinit>"){
                nodeContent->constantConstructor = cf->methods + i;
            } else if((cf->methods[i].accessFlags & 0x0008) && (cf->methods[i].accessFlags & 0x0002)){ // static private
                nodeContent->methodsClassPriv.insert(method, cf->methods + i);
                nodeContent->qtdMethodsClassPriv++;
            } else if((cf->methods[i].accessFlags & 0x0008)){ // static noPrivate
                nodeContent->methodsClassNoPriv.insert(method, cf->methods + i);
                nodeContent->qtdMethodsClassNoPriv++;
            } else if((cf->methods[i].accessFlags & 0x0002)){ // private
                nodeContent->methodsInstancePriv.insert(method, cf->methods + i);
                nodeContent->qtdMethodsInstancePriv++;
            } else { // noPrivate
                nodeContent->methodsInstanceNoPriv.insert(method, std::make_pair(nodeContent->qtdMethodsInstanceNoPriv, cf->methods + i));
                nodeContent->qtdMethodsInstanceNoPriv++;
            } 
        }
        for(uint32_t i = 0; i < cf->fieldsCount; i++){
            std::string fieldName = getStringFromCPInfo(cf->constantPool, cf->fields[i].nameIndex);
            std::string fieldDescriptor = getStringFromCPInfo(cf->constantPool, cf->fields[i].descriptorIndex);
            std::string field = fieldName + ":" + fieldDescriptor;
            if(!(cf->fields[i].accessFlags & 0x0008) && (cf->fields[i].accessFlags & 0x0002)){ // private
                if(fieldDescriptor[0] == 'B'){
                    nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint8_t);
                } else if(fieldDescriptor[0] == 'C'){
                    nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint16_t);
                } else if(fieldDescriptor[0] == 'D'){
                    nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(double);
                } else if(fieldDescriptor[0] == 'F'){
                    nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(float);
                } else if(fieldDescriptor[0] == 'I'){
                    nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint32_t);
                } else if(fieldDescriptor[0] == 'J'){
                    nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint64_t);
                } else if(fieldDescriptor[0] == 'S'){
                    nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint16_t);
                } else if(fieldDescriptor[0] == 'Z'){
                    nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint8_t);
                } else if(fieldDescriptor[0] == 'L'){
                    nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint32_t);
                } else if(fieldDescriptor[0] == '['){
                    nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint32_t);
                }
                nodeContent->qtdFieldsInstancePriv++;
            } else if(!(cf->fields[i].accessFlags & 0x0008)){ // noPrivate
                if(fieldDescriptor[0] == 'B'){
                    nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint8_t);
                } else if(fieldDescriptor[0] == 'C'){
                    nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint16_t);
                } else if(fieldDescriptor[0] == 'D'){
                    nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(double);
                } else if(fieldDescriptor[0] == 'F'){
                    nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(float);
                } else if(fieldDescriptor[0] == 'I'){
                    nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint32_t);
                } else if(fieldDescriptor[0] == 'J'){
                    nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint64_t);
                } else if(fieldDescriptor[0] == 'S'){
                    nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint16_t);
                } else if(fieldDescriptor[0] == 'Z'){
                    nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint8_t);
                } else if(fieldDescriptor[0] == 'L'){
                    nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint32_t);
                } else if(fieldDescriptor[0] == '['){
                    nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                    nodeContent->sizeInstance += sizeof(uint32_t);
                }
                nodeContent->qtdFieldsInstanceNoPriv++;
            }
        }
        nodeContent->wasResolved = true;
        if(nodeContent->qtdMethodsInstanceNoPriv > 0){
            nodeContent->acessMehodsTable = new MethodInfo*[nodeContent->qtdMethodsInstanceNoPriv];
            runtimeDataArea->pushMethodArea(new DestructArray<MethodInfo*>(nodeContent->acessMehodsTable));
        }
        auto &vetData = nodeContent->methodsInstanceNoPriv.getData();
        for(uint32_t i = 0; i < nodeContent->qtdMethodsInstanceNoPriv; i++){
            nodeContent->acessMehodsTable[i] = vetData[i].second;
        }
        classResolve.pop();
        classInitialize.push(nodeContent);
    } else{
        std::string superClassName = getStringFromCPInfo(cf->constantPool, cf->superClass);
        if(tree.hasKey(superClassName) && interfacesAreLoaded(nodeContent)){
            NodeContent *superNodeContent = tree.getValue(superClassName);
            if(!superNodeContent->wasResolved){
                throw std::string("Heranca Circular");
            }
            nodeContent->iterfaceMethodLocalization = superNodeContent->iterfaceMethodLocalization;
            nodeContent->qtdMethodsClassNoPriv = superNodeContent->qtdMethodsClassNoPriv;
            nodeContent->methodsClassNoPriv.copyFrom(superNodeContent->methodsClassNoPriv);
            nodeContent->qtdMethodsInstanceNoPriv = superNodeContent->qtdMethodsInstanceNoPriv;
            nodeContent->methodsClassNoPriv.copyFrom(superNodeContent->methodsClassNoPriv);
            nodeContent->qtdFieldsClassNoPriv = superNodeContent->qtdFieldsClassNoPriv;
            nodeContent->methodsClassNoPriv.copyFrom(superNodeContent->methodsClassNoPriv);
            nodeContent->qtdFieldsInstanceNoPriv = superNodeContent->qtdFieldsInstanceNoPriv;
            nodeContent->methodsClassNoPriv.copyFrom(superNodeContent->methodsClassNoPriv);
            for(uint32_t i = 0; i < cf->methodsCount; i++){
                std::string methodName = getStringFromCPInfo(cf->constantPool, cf->methods[i].nameIndex);
                std::string methodDescriptor = getStringFromCPInfo(cf->constantPool, cf->methods[i].descriptorIndex);
                std::string method = methodName + ":" + methodDescriptor;
                cf->methods[i].cp = cf->constantPool;
                if(methodName == "<init>"){
                    nodeContent->constructor.insert(method, cf->methods + i);
                } else if(methodName == "<clinit>"){
                    nodeContent->constantConstructor = cf->methods + i;
                } else if((cf->methods[i].accessFlags & 0x0008) && (cf->methods[i].accessFlags & 0x0002)){ // static private
                    nodeContent->methodsClassPriv.insert(method, cf->methods + i);
                    nodeContent->qtdMethodsClassPriv++;
                } else if((cf->methods[i].accessFlags & 0x0008)){ // static noPrivate
                    nodeContent->methodsClassNoPriv.insert(method, cf->methods + i);
                    nodeContent->qtdMethodsClassNoPriv++;
                } else if((cf->methods[i].accessFlags & 0x0002)){ // private
                    nodeContent->methodsInstancePriv.insert(method, cf->methods + i);
                    nodeContent->qtdMethodsInstancePriv++;
                } else{ // noPrivate
                    if(tree.hasKey(method)){
                        nodeContent->methodsInstanceNoPriv.getValue(method).second = cf->methods + i;
                    } else{
                        nodeContent->methodsInstanceNoPriv.insert(method, std::make_pair(nodeContent->qtdMethodsInstanceNoPriv, cf->methods + i));
                        nodeContent->qtdMethodsInstanceNoPriv++;
                    }
                } 
            }
            for(uint32_t i = 0; i < cf->fieldsCount; i++){
                std::string fieldName = getStringFromCPInfo(cf->constantPool, cf->fields[i].nameIndex);
                std::string fieldDescriptor = getStringFromCPInfo(cf->constantPool, cf->fields[i].descriptorIndex);
                std::string field = fieldName + ":" + fieldDescriptor;
                if(!(cf->fields[i].accessFlags & 0x0008) && (cf->fields[i].accessFlags & 0x0002)){ // private
                    if(fieldDescriptor[0] == 'B'){
                        nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint8_t);
                    } else if(fieldDescriptor[0] == 'C'){
                        nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint16_t);
                    } else if(fieldDescriptor[0] == 'D'){
                        nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(double);
                    } else if(fieldDescriptor[0] == 'F'){
                        nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(float);
                    } else if(fieldDescriptor[0] == 'I'){
                        nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint32_t);
                    } else if(fieldDescriptor[0] == 'J'){
                        nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint64_t);
                    } else if(fieldDescriptor[0] == 'S'){
                        nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint16_t);
                    } else if(fieldDescriptor[0] == 'Z'){
                        nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint8_t);
                    } else if(fieldDescriptor[0] == 'L'){
                        nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint32_t);
                    } else if(fieldDescriptor[0] == '['){
                        nodeContent->fieldsInstancePriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint32_t);
                    }
                    nodeContent->qtdFieldsInstancePriv++;
                } else if(!(cf->fields[i].accessFlags & 0x0008)){ // noPrivate
                    if(fieldDescriptor[0] == 'B'){
                        nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint8_t);
                    } else if(fieldDescriptor[0] == 'C'){
                        nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint16_t);
                    } else if(fieldDescriptor[0] == 'D'){
                        nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(double);
                    } else if(fieldDescriptor[0] == 'F'){
                        nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(float);
                    } else if(fieldDescriptor[0] == 'I'){
                        nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint32_t);
                    } else if(fieldDescriptor[0] == 'J'){
                        nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint64_t);
                    } else if(fieldDescriptor[0] == 'S'){
                        nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint16_t);
                    } else if(fieldDescriptor[0] == 'Z'){
                        nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint8_t);
                    } else if(fieldDescriptor[0] == 'L'){
                        nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint32_t);
                    } else if(fieldDescriptor[0] == '['){
                        nodeContent->fieldsInstanceNoPriv.insert(field, nodeContent->sizeInstance);
                        nodeContent->sizeInstance += sizeof(uint32_t);
                    }
                    nodeContent->qtdFieldsInstanceNoPriv++;
                }
            }
            nodeContent->wasResolved = true;
            if(nodeContent->qtdMethodsInstanceNoPriv > 0){
                nodeContent->acessMehodsTable = new MethodInfo*[nodeContent->qtdMethodsInstanceNoPriv];
                runtimeDataArea->pushMethodArea(new DestructArray<MethodInfo*>(nodeContent->acessMehodsTable));
            }
            auto &vetData = nodeContent->methodsInstanceNoPriv.getData();
            for(uint32_t i = 0; i < nodeContent->qtdMethodsInstanceNoPriv; i++){
                nodeContent->acessMehodsTable[i] = vetData[i].second;
            }
            for(uint32_t i = 0; i < nodeContent->classFile->interfacesCount; i++){
                std::string interfaceClassName = getStringFromCPInfo(cf->constantPool, cf->interfaces[i]);
                NodeContent* interfaceContent = tree.getValue(interfaceClassName);
                if(!nodeContent->iterfaceMethodLocalization.count(interfaceContent->classNum)){
                    uint32_t * table = new uint32_t[interfaceContent->qtdMethodsInstanceNoPriv];
                    runtimeDataArea->pushMethodArea(new DestructArray<uint32_t>(table));
                    nodeContent->iterfaceMethodLocalization[interfaceContent->classNum] = table;
                    auto &interfaceMethods = interfaceContent->methodsInstanceNoPriv.getData();
                    for(uint32_t i = 0; i < interfaceMethods.size(); i++){
                        std::string methodName = getStringFromCPInfo(interfaceContent->classFile->constantPool, interfaceMethods[i].second->nameIndex);
                        std::string methodDescriptor = getStringFromCPInfo(interfaceContent->classFile->constantPool, interfaceMethods[i].second->descriptorIndex);
                        std::string method = methodName + ":" + methodDescriptor;
                        table[interfaceMethods[i].first] = nodeContent->methodsInstanceNoPriv.getValue(method).first;
                    }
                }
            }
            classResolve.pop();
            classInitialize.push(nodeContent);
        } else{
            if(!tree.hasKey(superClassName)){
                addClassToLoad(superClassName);
            }
            addInterfacesToLoad(nodeContent);
        }
    }
}
void CassLoader::inicialize(NodeContent *nodeContent){
    classInitialize.pop();
    if(nodeContent->constantConstructor != nullptr){
        executionEngine->exec(nodeContent->constantConstructor);
    }
}

CassLoader::CassLoader(std::string &&s) : fs(s){
    runtimeDataArea = nullptr;
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
            inicialize(classInitialize.top());
        } else if(!classToLoad.empty()){
            readClass(classToLoad.top());
        } else if(!classPrepare.empty()){
            prepare(classPrepare.top());
        } else if(!classResolve.empty()){
            resolve(classResolve.top());
        }
    }
}

MethodInfo* CassLoader::getMethod(std::string className, std::string methodName){
    if(tree.hasKey(className)){
        NodeContent* nc = tree.getValue(className);
        if(nc->methodsClassNoPriv.hasKey(methodName)){
            return nc->methodsClassNoPriv.getValue(methodName);
        } else if(nc->methodsClassPriv.hasKey(methodName)){
            return nc->methodsClassPriv.getValue(methodName);
        }
    }
    return nullptr;
}

void CassLoader::resolveConstantPoolAt(ConstantPoolInfo** cp, uint32_t ind){
    if(cp[ind]->tag == ConstantPoolInfoTag::CLASS){
        CPClass* classRef = dynamic_cast<CPClass*>(cp[ind]);
        std::string className = getStringFromCPInfo(cp, ind);
        if(!tree.hasKey(className)){
            classToLoad.push(className);
            exec();
        }
        NodeContent* nc = tree.getValue(className);
        classRef->wasLoaded = true;
        classRef->instanceFieldSize = nc->sizeInstance;
        classRef->instanceMethodSize = nc->qtdMethodsInstanceNoPriv;
        classRef->instanceMethodPointer = nc->acessMehodsTable;
    } else if(cp[ind]->tag == ConstantPoolInfoTag::FIELDREF){
        CPFieldref* fieldRef = dynamic_cast<CPFieldref*>(cp[ind]);
        CPNameAndType* nameAndType = dynamic_cast<CPNameAndType*>(cp[fieldRef->nameAndTypeIndex]);
        std::string className = getStringFromCPInfo(cp, fieldRef->classIndex);
        std::string fieldName = getStringFromCPInfo(cp, nameAndType->nameIndex) + ":" + getStringFromCPInfo(cp, nameAndType->descriptorIndex);
        if(!tree.hasKey(className)){
            classToLoad.push(className);
            exec();
        }
        NodeContent* nc = tree.getValue(className);
        if(nc->fieldsClassNoPriv.hasKey(fieldName)){
            fieldRef->classFieldValue = nc->fieldsClassNoPriv.getValue(fieldName);
        } else if(nc->fieldsClassPriv.hasKey(fieldName)){
            fieldRef->classFieldValue = nc->fieldsClassPriv.getValue(fieldName);
        } else if(nc->fieldsInstanceNoPriv.hasKey(fieldName)){
            fieldRef->instanceFieldDesloc = nc->fieldsInstanceNoPriv.getValue(fieldName);
        } else if(nc->fieldsInstancePriv.hasKey(fieldName)){
            fieldRef->instanceFieldDesloc = nc->fieldsInstancePriv.getValue(fieldName);
        }
    } else if(cp[ind]->tag == ConstantPoolInfoTag::METHODREF){
        CPMethodref* methodref = dynamic_cast<CPMethodref*>(cp[ind]);
        CPNameAndType* nameAndType = dynamic_cast<CPNameAndType*>(cp[methodref->nameAndTypeIndex]);std::string className = getStringFromCPInfo(cp, methodref->classIndex);
        std::string methodName = getStringFromCPInfo(cp, nameAndType->nameIndex) + ":" + getStringFromCPInfo(cp, nameAndType->descriptorIndex);
        if(!tree.hasKey(className)){
            classToLoad.push(className);
            exec();
        }
        NodeContent* nc = tree.getValue(className);
        if(nc->constructor.hasKey(methodName)){
            methodref->directMethod = nc->constructor.getValue(methodName);
        } else if(nc->methodsClassNoPriv.hasKey(methodName)){
            methodref->directMethod = nc->methodsClassNoPriv.getValue(methodName);
        } else if(nc->methodsClassPriv.hasKey(methodName)){
            methodref->directMethod = nc->methodsClassPriv.getValue(methodName);
        } else if(nc->methodsInstanceNoPriv.hasKey(methodName)){
            methodref->instanceMethodDesloc = nc->methodsInstanceNoPriv.getValue(methodName).first;
        } else if(nc->methodsInstancePriv.hasKey(methodName)){
            methodref->directMethod = nc->methodsInstancePriv.getValue(methodName);
        }
    }
}
       