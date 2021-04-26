#include "../include/ClassLoader.h"

#include <stdexcept>
#include <queue>
#include "../include/PrintTudo.h"
#include "../include/PrintMenu.h"

bool isSameClass(std::string s1, std::string s2){
    return s1 == s2;
}

ClassLoader::NodeContent::NodeContent(){
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

bool ClassLoader::interfacesAreLoaded(NodeContent *nodeContent){
    ClassFile *cf = nodeContent->classFile;
    for(uint32_t i = 0; i < cf->interfacesCount; i++){
        std::string s = getStringFromCPInfo(cf->constantPool, cf->interfaces[i]);
        if(!tree.hasKey(s)){
            return false;
        } else if(!tree.getValue(s)->wasResolved){
            throw std::logic_error("Heranca Circular");
        }
    }
    return true;
}

void ClassLoader::addInterfacesToLoad(NodeContent *nodeContent){
    ClassFile *cf = nodeContent->classFile;
    for(uint32_t i = 0; i < cf->interfacesCount; i++){
        std::string s = getStringFromCPInfo(cf->constantPool, cf->interfaces[i]);
        this->classToLoad.push(s);
    }
}

ClassFile* ClassLoader::readClass2(FileSystem &fs, std::string &s){

    std::ifstream is;
    is.open(fs.getJavaClassPath() + s + ".class", std::ios::binary);
    if(!is.is_open()){
        is.open(fs.getUserClassPath() + s + ".class", std::ios::binary);
        if(!is.is_open()){
            std::cerr << "Arquivo \"" + s + ".class\" nao foi encontrado\n"; 
            exit(1);
        }
    }
    is.exceptions(std::ifstream::eofbit);
    ClassFile *cf = new ClassFile();
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
    s = fs.environmentToJavaPathNotation(s);
    std::string strAux = getStringFromCPInfo(cf->constantPool, cf->thisClass);
    if(!isSameClass(strAux, s)){
        if(strAux.size() < s.size()){
            std::string strTmp = s.substr(0, s.size() - strAux.size());
            if(strTmp.back() == '/'){
                fs.setUserClassPath(strTmp);
                s = strAux;
            } else{
                std::cerr << "Nome do arquivo diferente do nome da classe\n";
            }
        } else{
            std::cerr << "Nome do arquivo diferente do nome da classe\n";
        }
    }
    conveterAttributeInfoInClassFile(cf->constantPool, cf);
    return cf;
}


std::string ClassLoader::getClassName(){
    ClassFile* cf = tree.getData()[0]->classFile;
    return getClass(cf->constantPool, cf->thisClass);
}

void ClassLoader::readClass(std::string &s){
    if(!tree.hasKey(s)){
        std::string s1 = fs.javaToEnvironmentPathNotation(s);

        ClassFile *cf = ClassLoader::readClass2(fs, s1);
        runtimeDataArea->pushMethodArea(new DestructSimple<ClassFile>(cf));

        NodeContent *nodeContent = new NodeContent();
        runtimeDataArea->pushMethodArea(new DestructSimple<NodeContent>(nodeContent));
        nodeContent->classNum = tree.size();
        nodeContent->classFile = cf;
        tree.insert(s1, nodeContent);
        inheranceGraph.push_back({});
        classToLoad.pop();
        classPrepare.push(nodeContent);
    } else{
        classToLoad.pop();
    }
}
void ClassLoader::prepare(NodeContent *nodeContent){
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
        
void ClassLoader::resolve(NodeContent *nodeContent, std::queue<NodeContent*>& classInitialize){
    ClassFile * cf = nodeContent->classFile;
    if(cf->superClass == 0){
        nodeContent->wasResolved = true;
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
                throw std::logic_error("Heranca Circular");
            }
            nodeContent->wasResolved = true;
            
            inheranceGraph[nodeContent->classNum].push_back(superNodeContent->classNum);
            for(uint32_t i = 0; i < nodeContent->classFile->interfacesCount; i++){
                std::string str = getStringFromCPInfo(nodeContent->classFile->constantPool, nodeContent->classFile->interfaces[i]);
                NodeContent *interfaceNodeContent = tree.getValue(str);
                inheranceGraph[nodeContent->classNum].push_back(interfaceNodeContent->classNum);
            }
            inheranceGraph[nodeContent->classNum].reserve(inheranceGraph[nodeContent->classNum].size());

            nodeContent->iterfaceMethodLocalization = superNodeContent->iterfaceMethodLocalization;
            nodeContent->qtdMethodsClassNoPriv = superNodeContent->qtdMethodsClassNoPriv;
            nodeContent->methodsClassNoPriv.copyFrom(superNodeContent->methodsClassNoPriv);
            nodeContent->qtdMethodsInstanceNoPriv = superNodeContent->qtdMethodsInstanceNoPriv;
            nodeContent->methodsInstanceNoPriv.copyFrom(superNodeContent->methodsInstanceNoPriv);
            nodeContent->qtdFieldsClassNoPriv = superNodeContent->qtdFieldsClassNoPriv;
            nodeContent->fieldsClassNoPriv.copyFrom(superNodeContent->fieldsClassNoPriv);
            nodeContent->qtdFieldsInstanceNoPriv = superNodeContent->qtdFieldsInstanceNoPriv;
            nodeContent->fieldsInstanceNoPriv.copyFrom(superNodeContent->fieldsInstanceNoPriv);
            nodeContent->sizeInstance = superNodeContent->sizeInstance;
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
                    // std::cout << method << "\n";
                    if(nodeContent->methodsInstanceNoPriv.hasKey(method)){
                        nodeContent->methodsInstanceNoPriv.getValue(method).second = cf->methods + i;
                    } else{
                        nodeContent->methodsInstanceNoPriv.insert(method, std::make_pair(nodeContent->qtdMethodsInstanceNoPriv, cf->methods + i));
                        nodeContent->qtdMethodsInstanceNoPriv++;
                    }
                } 
            }
            // std::cout << "\n";
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
                // std::string methodName = getStringFromCPInfo(vetData[i].second->cp, vetData[i].second->nameIndex);
                // std::string methodDescriptor = getStringFromCPInfo(vetData[i].second->cp, vetData[i].second->descriptorIndex);
                // std::string method = methodName + ":" + methodDescriptor;
                
                // std::cout << method << "\n";
                // uint32_t val = vetData[i].first;
                nodeContent->acessMehodsTable[i] = vetData[i].second;
            }
            // std::cout << "\n";
            for(uint32_t i = 0; i < nodeContent->classFile->interfacesCount; i++){
                std::string interfaceClassName = getStringFromCPInfo(cf->constantPool, cf->interfaces[i]);
                NodeContent* interfaceContent = tree.getValue(interfaceClassName);
                if(!nodeContent->iterfaceMethodLocalization.count(interfaceContent->classNum)){
                    uint32_t * table = new uint32_t[interfaceContent->qtdMethodsInstanceNoPriv];
                    runtimeDataArea->pushMethodArea(new DestructArray<uint32_t>(table));
                    nodeContent->iterfaceMethodLocalization[interfaceContent->classNum] = table;
                    auto &interfaceMethods = interfaceContent->methodsInstanceNoPriv.getData();
                    for(uint32_t i = 0; i < interfaceMethods.size(); i++){
                        std::string methodName = getStringFromCPInfo(interfaceMethods[i].second->cp, interfaceMethods[i].second->nameIndex);
                        std::string methodDescriptor = getStringFromCPInfo(interfaceMethods[i].second->cp, interfaceMethods[i].second->descriptorIndex);
                        std::string method = methodName + ":" + methodDescriptor;
                        // table[nodeContent->methodsInstanceNoPriv.getValue(method).first] = interfaceMethods[i].first;
                        // uint32_t val = nodeContent->methodsInstanceNoPriv.getValue(method).first;
                        table[interfaceMethods[i].first] = nodeContent->methodsInstanceNoPriv.getValue(method).first;
                    }
                }
            }
            classResolve.pop();
            classInitialize.push(nodeContent);
        } else{
            addInterfacesToLoad(nodeContent);
            if(!tree.hasKey(superClassName)){
                classToLoad.push(superClassName);
            }
        }
    }
}
void ClassLoader::inicialize(NodeContent *nodeContent, std::queue<NodeContent*>& classInitialize){
    classInitialize.pop();
    if(nodeContent->constantConstructor != nullptr){
        MethodInfo* method = nodeContent->constantConstructor;
        executionEngine->exec(method, Frame::CreateFrame(method));
    }
}

ClassLoader::ClassLoader(std::string &&s) : fs(s){
    runtimeDataArea = nullptr;
    objectNodeContent = nullptr;
}
ClassLoader::ClassLoader(std::string &s) : fs(s){
    runtimeDataArea = nullptr;
    objectNodeContent = nullptr;
}

void ClassLoader::addClassToLoad(std::string s){
    s = fs.javaToEnvironmentPathNotation(s);
    classToLoad.push(s);
}

void ClassLoader::setRuntimeDataArea(RuntimeDataArea* new_runtimeDataArea){
    runtimeDataArea = new_runtimeDataArea;
}
void ClassLoader::setExecutionEngine(ExecutionEngine* new_executionEngine){
    executionEngine = new_executionEngine;
}

void ClassLoader::exec(){
    std::queue<NodeContent*> classInitialize;
    while(!classToLoad.empty() || !classPrepare .empty() || !classResolve .empty() || !classInitialize.empty()){
        if(!classToLoad.empty()){
            readClass(classToLoad.front());
        } else if(!classPrepare.empty()){
            prepare(classPrepare.front());
        } else if(!classResolve.empty()){
            resolve(classResolve.top(), classInitialize);
        } else if(!classInitialize.empty()){
            inicialize(classInitialize.front(), classInitialize);
        }
    }
}

MethodInfo* ClassLoader::getMethod(std::string className, std::string methodName){
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

void ClassLoader::saveObejectInfo(){
    std::string str = "java/lang/Object";
    objectNodeContent = tree.getValue(str);
}

std::pair<MethodInfo**, uint32_t> ClassLoader::getObejectInfo(){
    return {objectNodeContent->acessMehodsTable, objectNodeContent->sizeInstance};
}

void ClassLoader::resolveConstantPoolAt(ConstantPoolInfo** cp, uint32_t ind){
    if(cp[ind]->tag == ConstantPoolInfoTag::CLASS){
        CPClass* classRef = dynamic_cast<CPClass*>(cp[ind]);
        std::string className = getStringFromCPInfo(cp, ind);
        classRef->wasLoaded = true;
        for(uint32_t i = 0; i < className.size(); i++){
            if(i == 0 && className[i] != '['){
                classRef->primitiveType = 'L';
                break;
            }
            if(i > 0 && className[i] != '['){
                classRef->primitiveType = className[i];
                className = className.substr(i+1);
                break;
            } else{
                classRef->dimensions++;
            }
        }
        if(className.empty()){
            return;
        }
        if(className.back() == ';'){
            className.pop_back();
        }
        if(!tree.hasKey(className)){
            classToLoad.push(className);
            exec();
        }
        NodeContent* nc = tree.getValue(className);
        classRef->classNum = nc->classNum;
        classRef->classFile = nc->classFile;
        classRef->instanceFieldSize = nc->sizeInstance;
        classRef->instanceMethodSize = nc->qtdMethodsInstanceNoPriv;
        // classRef-> = nc->acessMehodsTable;
    } else if(cp[ind]->tag == ConstantPoolInfoTag::FIELDREF){
        CPFieldref* fieldRef = dynamic_cast<CPFieldref*>(cp[ind]);
        CPNameAndType* nameAndType = dynamic_cast<CPNameAndType*>(cp[fieldRef->nameAndTypeIndex]);
        fieldRef->wasLoaded = true;
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
        CPNameAndType* nameAndType = dynamic_cast<CPNameAndType*>(cp[methodref->nameAndTypeIndex]);
        methodref->wasLoaded = true;
        std::string className = getStringFromCPInfo(cp, methodref->classIndex);
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
            auto aux = nc->methodsInstanceNoPriv.getValue(methodName);
            methodref->instanceMethodDesloc = aux.first;
            methodref->directMethod = aux.second;
        } else if(nc->methodsInstancePriv.hasKey(methodName)){
            methodref->directMethod = nc->methodsInstancePriv.getValue(methodName);
        }
    } else if(cp[ind]->tag == ConstantPoolInfoTag::INTERFACE_METHODREF){
        CPInterfaceMethodref* interfaceMethodref = dynamic_cast<CPInterfaceMethodref*>(cp[ind]);
        CPNameAndType* nameAndType = dynamic_cast<CPNameAndType*>(cp[interfaceMethodref->nameAndTypeIndex]);
        interfaceMethodref->wasLoaded = true;
        std::string className = getStringFromCPInfo(cp, interfaceMethodref->classIndex);
        std::string methodName = getStringFromCPInfo(cp, nameAndType->nameIndex) + ":" + getStringFromCPInfo(cp, nameAndType->descriptorIndex);
        if(!tree.hasKey(className)){
            classToLoad.push(className);
            exec();
        }
        NodeContent* nc = tree.getValue(className);
        interfaceMethodref->classNum = nc->classNum;
        if(nc->methodsInstanceNoPriv.hasKey(methodName)){
            interfaceMethodref->instanceMethodDesloc = nc->methodsInstanceNoPriv.getValue(methodName).first;
        }
    }
}

uint32_t ClassLoader::getClassNum(std::string &className){
    if(!tree.hasKey(className)){
        classToLoad.push(className);
        exec();
    }
    return tree.getValue(className)->classNum;
}

MethodInfo* ClassLoader::getContructor(uint32_t classNum, std::string &methodName){
    NodeContent* nodeContent = tree.getData()[classNum];
    return nodeContent->constructor.getValue(methodName);
}

uint32_t ClassLoader::getInstanceSize(uint32_t classNum){
    NodeContent* nodeContent = tree.getData()[classNum];
    return nodeContent->sizeInstance;
}

std::map<uint32_t, uint32_t*>* ClassLoader::getIterfaceMethodLocalization(uint32_t classNum){
    NodeContent* nodeContent = tree.getData()[classNum];
    return &nodeContent->iterfaceMethodLocalization;
}

MethodInfo** ClassLoader::getMethodTable(uint32_t classNum){
    NodeContent* nodeContent = tree.getData()[classNum];
    return nodeContent->acessMehodsTable;
}


ClassFile* ClassLoader::getClassFile(uint32_t classNum){
    NodeContent* nodeContent = tree.getData()[classNum];
    return nodeContent->classFile;
}

uint32_t ClassLoader::getDatafromObject(uint32_t object, std::string& name){
    ObjectReference* objReference = runtimeDataArea->objectAt(object);
    NodeContent* nodeContent = tree.getData()[objReference->classNum];
    if(nodeContent->fieldsInstanceNoPriv.hasKey(name)){
        return nodeContent->fieldsInstanceNoPriv.getValue(name);
    } else if(nodeContent->fieldsInstancePriv.hasKey(name)){
        return nodeContent->fieldsInstancePriv.getValue(name);
    }
    return 0;
}

bool ClassLoader::parentOf(uint32_t parent, uint32_t child){
    if(parent == child){
        return true;
    }
    std::queue<uint32_t> fila;
    fila.push(child);
    while(!fila.empty()){
        auto front = fila.front();
        fila.pop();
        for(auto p : inheranceGraph[front]){
            if(parent == p){
                return true;
            }
            fila.push(p);
        }
    }
    return false;
}