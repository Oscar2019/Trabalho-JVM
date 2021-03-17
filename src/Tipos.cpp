#include "../include/Tipos.h"
#include <iomanip>


template<>
uint8_t read<uint8_t>(const uint8_t *in){
    uint8_t res = 0;
    res = *in;
    return res;
}

template<>
uint16_t read<uint16_t>(const uint8_t *in){
    uint16_t res = 0;
    res = (res << 8) | (uint16_t)read<uint8_t>(in + 0);
    res = (res << 8) | (uint16_t)read<uint8_t>(in + 1);
    return res;
}

template<>
uint32_t read<uint32_t>(const uint8_t *in){
    uint32_t res = 0;
    res = (res << 8) | (uint32_t)read<uint8_t>(in + 0);
    res = (res << 8) | (uint32_t)read<uint8_t>(in + 1);
    res = (res << 8) | (uint32_t)read<uint8_t>(in + 2);
    res = (res << 8) | (uint32_t)read<uint8_t>(in + 3);
    return res;
}

template<>
void read<uint8_t>(std::ifstream &ifs, uint8_t *u){
    ifs.read((char*)u, 1);
}

template<>
void read<uint16_t>(std::ifstream &ifs, uint16_t *u){
    uint8_t aux = 0;
    *u = 0;
    read<uint8_t>(ifs, &aux);
    *u = (*u << 8) | ((uint16_t) aux);
    read<uint8_t>(ifs, &aux);
    *u = (*u << 8) | ((uint16_t) aux);
}

template<>
void read<uint32_t>(std::ifstream &ifs, uint32_t *u){
    uint8_t aux = 0;
    read<uint8_t>(ifs, &aux);
    *u = (*u << 8) | ((uint32_t) aux);
    read<uint8_t>(ifs, &aux);
    *u = (*u << 8) | ((uint32_t) aux);
    read<uint8_t>(ifs, &aux);
    *u = (*u << 8) | ((uint32_t) aux);
    read<uint8_t>(ifs, &aux);
    *u = (*u << 8) | ((uint32_t) aux);
}

template<>
void print<uint8_t>(uint8_t& u, std::ostream &os){
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << (uint32_t)u << "\n";
}

template<>
void print<uint16_t>(uint16_t& u, std::ostream &os){
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << ((((uint32_t)u) >> 8) & 0xFF) << " ";
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << ((((uint32_t)u) >> 0) & 0xFF) << "\n";
}

template<>
void print<uint32_t>(uint32_t& u, std::ostream &os){
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << ((((uint32_t)u) >> 24) & 0xFF) << " ";
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << ((((uint32_t)u) >> 16) & 0xFF) << " ";
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << ((((uint32_t)u) >> 8) & 0xFF) << " ";
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << ((((uint32_t)u) >> 0) & 0xFF) << "\n";
}


template<>
void read<ClassFile>(std::ifstream &ifs, ClassFile *u){

    read<uint32_t>(ifs, &u->magic);
    read<uint16_t>(ifs, &u->minorVersion);
    read<uint16_t>(ifs, &u->majorVersion);
    read<uint16_t>(ifs, &u->constantPoolCount);
    if(u->constantPoolCount > 0){
        u->constantPool = new ConstantPoolInfo*[u->constantPoolCount];
        for(uint32_t i = 0; i < u->constantPoolCount; i++){
            u->constantPool[i] = nullptr;
        }
        for(uint32_t i = 1; i < u->constantPoolCount; i++){
            if(u->constantPool[i-1] == nullptr || (u->constantPool[i-1]->tag != ConstantPoolInfoTag::LONG && u->constantPool[i-1]->tag != ConstantPoolInfoTag::DOUBLE)){
                read<ConstantPoolInfo*>(ifs, &u->constantPool[i]);
            }
        }
    }
    read<uint16_t>(ifs, &u->accessFlags);
    read<uint16_t>(ifs, &u->thisClass);
    read<uint16_t>(ifs, &u->superClass);
    read<uint16_t>(ifs, &u->interfacesCount);
    if(u->interfacesCount > 0){
        u->interfaces = new uint16_t[u->interfacesCount];
        for(uint32_t i = 0; i < u->interfacesCount; i++){
            read<uint16_t>(ifs, &u->interfaces[i]);
        }
    }
    read<uint16_t>(ifs, &u->fieldsCount);
    if(u->fieldsCount > 0){
        u->fields = new FieldInfo[u->fieldsCount];
        for(uint32_t i = 0; i < u->fieldsCount; i++){
            read<FieldInfo>(ifs, &u->fields[i]);
        }
    }
    read<uint16_t>(ifs, &u->methodsCount);
    if(u->methodsCount > 0){
        u->methods = new MethodInfo[u->methodsCount];
        for(uint32_t i = 0; i < u->methodsCount; i++){
            read<MethodInfo>(ifs, &u->methods[i]);
        }
    }
    read<uint16_t>(ifs, &u->attributesCount);
    if(u->attributesCount > 0){
        u->attributes = new AttributeInfo*[u->attributesCount];
        for(uint32_t i = 0; i < u->attributesCount; i++){
            AttributeInfoBasic *attribAux;
            read<AttributeInfoBasic*>(ifs, &attribAux);
            u->attributes[i] = dynamic_cast<AttributeInfo*>(attribAux);
        }
    }
}

template<>
void print<ClassFile>(ClassFile& u, std::ostream &os){
    print<uint32_t>(u.magic, os);
    print<uint16_t>(u.minorVersion, os);
    print<uint16_t>(u.majorVersion, os);
    print<uint16_t>(u.constantPoolCount, os);
    for(uint32_t i = 0; i < u.constantPoolCount; i++){
        if(u.constantPool[i] != nullptr){
            print<ConstantPoolInfo>(*u.constantPool[i], os);
        }
    }
    print<uint16_t>(u.accessFlags, os);
    print<uint16_t>(u.thisClass, os);
    print<uint16_t>(u.superClass, os);
    print<uint16_t>(u.interfacesCount, os);
    for(uint32_t i = 0; i < u.interfacesCount; i++){
        print<uint16_t>(u.interfaces[i], os);
    }
    print<uint16_t>(u.fieldsCount, os);
    for(uint32_t i = 0; i < u.fieldsCount; i++){
        print<FieldInfo>(u.fields[i], os);
    }
    print<uint16_t>(u.methodsCount, os);
    for(uint32_t i = 0; i < u.methodsCount; i++){
        print<MethodInfo>(u.methods[i], os);
    }
    print<uint16_t>(u.attributesCount, os);
    for(uint32_t i = 0; i < u.attributesCount; i++){
        print<AttributeInfoBasic>(*dynamic_cast<AttributeInfoBasic*>(u.attributes[i]), os);
    }
}


template<>
void read<ConstantPoolInfo*>(std::ifstream &ifs, ConstantPoolInfo** u){
    uint8_t tag = 0;
    read<uint8_t>(ifs, &tag);
    switch (tag){
        case ConstantPoolInfoTag::CLASS:
            *u = new CPClass;
            (*u)->tag = tag;
            read<CPClass>(ifs, dynamic_cast<CPClass*>(*u));
            break;
        case ConstantPoolInfoTag::FIELDREF:
            *u = new CPFieldref;
            (*u)->tag = tag;
            read<CPFieldref>(ifs, dynamic_cast<CPFieldref*>(*u));
            break;
        case ConstantPoolInfoTag::METHODREF:
            *u = new CPMethodref;
            (*u)->tag = tag;
            read<CPMethodref>(ifs, dynamic_cast<CPMethodref*>(*u));
            break;
        case ConstantPoolInfoTag::INTERFACE_METHODREF:
            *u = new CPInterfaceMethodref;
            (*u)->tag = tag;
            read<CPInterfaceMethodref>(ifs, dynamic_cast<CPInterfaceMethodref*>(*u));
            break;
        case ConstantPoolInfoTag::STRING:
            *u = new CPString;
            (*u)->tag = tag;
            read<CPString>(ifs, dynamic_cast<CPString*>(*u));
            break;
        case ConstantPoolInfoTag::INTEGER:
            *u = new CPInteger;
            (*u)->tag = tag;
            read<CPInteger>(ifs, dynamic_cast<CPInteger*>(*u));
            break;
        case ConstantPoolInfoTag::FLOAT:
            *u = new CPFloat;
            (*u)->tag = tag;
            read<CPFloat>(ifs, dynamic_cast<CPFloat*>(*u));
            break;
        case ConstantPoolInfoTag::LONG:
            *u = new CPLong;
            (*u)->tag = tag;
            read<CPLong>(ifs, dynamic_cast<CPLong*>(*u));
            break;
        case ConstantPoolInfoTag::DOUBLE:
            *u = new CPDouble;
            (*u)->tag = tag;
            read<CPDouble>(ifs, dynamic_cast<CPDouble*>(*u));
            break;
        case ConstantPoolInfoTag::NAME_AND_TYPE:
            *u = new CPNameAndType;
            (*u)->tag = tag;
            read<CPNameAndType>(ifs, dynamic_cast<CPNameAndType*>(*u));
            break;
        case ConstantPoolInfoTag::UTF8:
            *u = new CPUtf8;
            (*u)->tag = tag;
            read<CPUtf8>(ifs, dynamic_cast<CPUtf8*>(*u));
            break;
        case ConstantPoolInfoTag::METHOD_HANDLE:
            *u = new CPMethodHandle;
            (*u)->tag = tag;
            read<CPMethodHandle>(ifs, dynamic_cast<CPMethodHandle*>(*u));
            break;
        case ConstantPoolInfoTag::METHOD_TYPE:
            *u = new CPMethodType;
            (*u)->tag = tag;
            read<CPMethodType>(ifs, dynamic_cast<CPMethodType*>(*u));
            break;
        case ConstantPoolInfoTag::INVOKE_DYNAMIC:
            *u = new CPInvokeDynamic;
            (*u)->tag = tag;
            read<CPInvokeDynamic>(ifs, dynamic_cast<CPInvokeDynamic*>(*u));
            break;
        default:
            break;
    }
}

template<>
void read<CPClass>(std::ifstream &ifs, CPClass *u){
    read<uint16_t>(ifs, &u->nameIndex);
}

template<>
void read<CPFieldref>(std::ifstream &ifs, CPFieldref *u){
    read<uint16_t>(ifs, &u->classIndex);
    read<uint16_t>(ifs, &u->nameAndTypeIndex);
}

template<>
void read<CPMethodref>(std::ifstream &ifs, CPMethodref *u){
    read<uint16_t>(ifs, &u->classIndex);
    read<uint16_t>(ifs, &u->nameAndTypeIndex);
}

template<>
void read<CPInterfaceMethodref>(std::ifstream &ifs, CPInterfaceMethodref *u){
    read<uint16_t>(ifs, &u->classIndex);
    read<uint16_t>(ifs, &u->nameAndTypeIndex);
}

template<>
void read<CPString>(std::ifstream &ifs, CPString *u){
    read<uint16_t>(ifs, &u->stringIndex);
}

template<>
void read<CPInteger>(std::ifstream &ifs, CPInteger *u){
    read<uint32_t>(ifs, &u->bytes);
}

template<>
void read<CPFloat>(std::ifstream &ifs, CPFloat *u){
    read<uint32_t>(ifs, &u->bytes);
}

template<>
void read<CPLong>(std::ifstream &ifs, CPLong *u){
    read<uint32_t>(ifs, &u->highBytes);
    read<uint32_t>(ifs, &u->lowBytes);
}

template<>
void read<CPDouble>(std::ifstream &ifs, CPDouble *u){
    read<uint32_t>(ifs, &u->highBytes);
    read<uint32_t>(ifs, &u->lowBytes);
}

template<>
void read<CPNameAndType>(std::ifstream &ifs, CPNameAndType *u){
    read<uint16_t>(ifs, &u->nameIndex);
    read<uint16_t>(ifs, &u->descriptorIndex);
}

template<>
void read<CPUtf8>(std::ifstream &ifs, CPUtf8 *u){
    read<uint16_t>(ifs, &u->length);
    if(u->length > 0){
        u->bytes = new uint8_t[u->length];
        for(uint32_t i = 0; i < u->length; i++){
            read<uint8_t>(ifs, &u->bytes[i]);
        }
    }
}

template<>
void read<CPMethodHandle>(std::ifstream &ifs, CPMethodHandle *u){
    read<uint8_t>(ifs, &u->referenceKind);
    read<uint16_t>(ifs, &u->referenceIndex);
}

template<>
void read<CPMethodType>(std::ifstream &ifs, CPMethodType *u){
    read<uint16_t>(ifs, &u->descriptorIndex);
}

template<>
void read<CPInvokeDynamic>(std::ifstream &ifs, CPInvokeDynamic *u){
    read<uint16_t>(ifs, &u->bootstrapMethodAttrIndex);
    read<uint16_t>(ifs, &u->nameAndTypeIndex);
}


template<>
void print<ConstantPoolInfo>(ConstantPoolInfo& u, std::ostream &os){
    switch (u.tag){
        case ConstantPoolInfoTag::CLASS:
            print<CPClass>(*((CPClass*)&u), os);
            break;
        case ConstantPoolInfoTag::FIELDREF:
            print<CPFieldref>(*((CPFieldref*)&u), os);
            break;
        case ConstantPoolInfoTag::METHODREF:
            print<CPMethodref>(*((CPMethodref*)&u), os);
            break;
        case ConstantPoolInfoTag::INTERFACE_METHODREF:
            print<CPInterfaceMethodref>(*((CPInterfaceMethodref*)&u), os);
            break;
        case ConstantPoolInfoTag::STRING:
            print<CPString>(*((CPString*)&u), os);
            break;
        case ConstantPoolInfoTag::INTEGER:
            print<CPInteger>(*((CPInteger*)&u), os);
            break;
        case ConstantPoolInfoTag::FLOAT:
            print<CPFloat>(*((CPFloat*)&u), os);
            break;
        case ConstantPoolInfoTag::LONG:
            print<CPLong>(*((CPLong*)&u), os);
            break;
        case ConstantPoolInfoTag::DOUBLE:
            print<CPDouble>(*((CPDouble*)&u), os);
            break;
        case ConstantPoolInfoTag::NAME_AND_TYPE:
            print<CPNameAndType>(*((CPNameAndType*)&u), os);
            break;
        case ConstantPoolInfoTag::UTF8:
            print<CPUtf8>(*((CPUtf8*)&u), os);
            break;
        case ConstantPoolInfoTag::METHOD_HANDLE:
            print<CPMethodHandle>(*((CPMethodHandle*)&u), os);
            break;
        case ConstantPoolInfoTag::METHOD_TYPE:
            print<CPMethodType>(*((CPMethodType*)&u), os);
            break;
        case ConstantPoolInfoTag::INVOKE_DYNAMIC:
            print<CPInvokeDynamic>(*((CPInvokeDynamic*)&u), os);
            break;
        default:
            break;
    }
}

template<>
void print<CPClass>(CPClass& u, std::ostream &os){
    print<uint8_t>(u.tag, os);
    print<uint16_t>(u.nameIndex, os);
}

template<>
void print<CPFieldref>(CPFieldref& u, std::ostream &os){
    print<uint8_t>(u.tag, os);
    print<uint16_t>(u.classIndex, os);
    print<uint16_t>(u.nameAndTypeIndex, os);
}

template<>
void print<CPMethodref>(CPMethodref& u, std::ostream &os){
    print<uint8_t>(u.tag, os);
    print<uint16_t>(u.classIndex, os);
    print<uint16_t>(u.nameAndTypeIndex, os);
}

template<>
void print<CPInterfaceMethodref>(CPInterfaceMethodref& u, std::ostream &os){
    print<uint8_t>(u.tag, os);
    print<uint16_t>(u.classIndex, os);
    print<uint16_t>(u.nameAndTypeIndex, os);
}

template<>
void print<CPString>(CPString& u, std::ostream &os){
    print<uint8_t>(u.tag, os);
    print<uint16_t>(u.stringIndex, os);
}

template<>
void print<CPInteger>(CPInteger& u, std::ostream &os){
    print<uint8_t>(u.tag, os);
    os << *(int32_t*)(&u.bytes) << "\n";
}

template<>
void print<CPFloat>(CPFloat& u, std::ostream &os){
    union {
        uint32_t i;
        float f;
    } aux;
    print<uint8_t>(u.tag, os);
    aux.i = u.bytes;
    os << aux.f << "\n";
}

template<>
void print<CPLong>(CPLong& u, std::ostream &os){
    int64_t aux = 0;
    print<uint8_t>(u.tag, os);
    aux = (aux << 32) | u.highBytes;
    aux = (aux << 32) | u.highBytes;
    os << *(int64_t*)(&aux) << "\n";
}

template<>
void print<CPDouble>(CPDouble& u, std::ostream &os){
    union {
        uint64_t i;
        double f;
    } aux;
    print<uint8_t>(u.tag, os);
    aux.i = (aux.i << 32) | u.highBytes;
    aux.i = (aux.i << 32) | u.highBytes;
    os << aux.f << "\n";
}

template<>
void print<CPNameAndType>(CPNameAndType& u, std::ostream &os){
    print<uint8_t>(u.tag, os);
    print<uint16_t>(u.nameIndex, os);
    print<uint16_t>(u.descriptorIndex, os);
}

template<>
void print<CPUtf8>(CPUtf8& u, std::ostream &os){
    print<uint8_t>(u.tag, os);
    print<uint16_t>(u.length, os);
    os << std::string((const char*)u.bytes, u.length) << "\n";
}

template<>
void print<CPMethodHandle>(CPMethodHandle& u, std::ostream &os){
    print<uint8_t>(u.tag, os);
    print<uint8_t>(u.referenceKind, os);
    print<uint16_t>(u.referenceIndex, os);
}

template<>
void print<CPMethodType>(CPMethodType& u, std::ostream &os){
    print<uint8_t>(u.tag, os);
    print<uint16_t>(u.descriptorIndex, os);
}

template<>
void print<CPInvokeDynamic>(CPInvokeDynamic& u, std::ostream &os){
    print<uint8_t>(u.tag, os);
    print<uint16_t>(u.bootstrapMethodAttrIndex, os);
    print<uint16_t>(u.nameAndTypeIndex, os);
}

template<>
void read<FieldInfo>(std::ifstream &ifs, FieldInfo *u){
    read<uint16_t>(ifs, &u->accessFlags);
    read<uint16_t>(ifs, &u->nameIndex);
    read<uint16_t>(ifs, &u->descriptorIndex);
    read<uint16_t>(ifs, &u->attributesCount);
    if(u->attributesCount > 0){
        u->attributes = new AttributeInfo*[u->attributesCount];
        for(uint32_t i = 0; i < u->attributesCount; i++){
            AttributeInfoBasic *attribAux;
            read<AttributeInfoBasic*>(ifs, &attribAux);
            u->attributes[i] = dynamic_cast<AttributeInfo*>(attribAux);
        }
    }
}

template<>
void print<FieldInfo>(FieldInfo& u, std::ostream &os){
    print<uint16_t>(u.accessFlags, os);
    print<uint16_t>(u.nameIndex, os);
    print<uint16_t>(u.descriptorIndex, os);
    print<uint16_t>(u.attributesCount, os);
    for(uint32_t i = 0; i < u.attributesCount; i++){
        print<AttributeInfoBasic>(*dynamic_cast<AttributeInfoBasic*>(u.attributes[i]), os);
    }
    os << "\n";
}

template<>
void read<MethodInfo>(std::ifstream &ifs, MethodInfo *u){
    read<uint16_t>(ifs, &u->accessFlags);
    read<uint16_t>(ifs, &u->nameIndex);
    read<uint16_t>(ifs, &u->descriptorIndex);
    read<uint16_t>(ifs, &u->attributesCount);
    if(u->attributesCount > 0){
        u->attributes = new AttributeInfo*[u->attributesCount];
        for(uint32_t i = 0; i < u->attributesCount; i++){
            AttributeInfoBasic *attribAux;
            read<AttributeInfoBasic*>(ifs, &attribAux);
            u->attributes[i] = dynamic_cast<AttributeInfo*>(attribAux);
        }
    }
}

template<>
void print<MethodInfo>(MethodInfo& u, std::ostream &os){
    print<uint16_t>(u.accessFlags, os);
    print<uint16_t>(u.nameIndex, os);
    print<uint16_t>(u.descriptorIndex, os);
    print<uint16_t>(u.attributesCount, os);
    for(uint32_t i = 0; i < u.attributesCount; i++){
        print<AttributeInfo>(*dynamic_cast<AttributeInfoBasic*>(u.attributes[i]), os);
    }
    os << "\n";
}


template<>
void read<AttributeInfoBasic*>(std::ifstream &ifs, AttributeInfoBasic** u){
    *u = new AttributeInfoBasic;
    read<uint16_t>(ifs, &(*u)->attributeNameIndex);
    read<uint32_t>(ifs, &(*u)->attributeLength);
    if((*u)->attributeLength > 0){
        (*u)->info = new uint8_t[(*u)->attributeLength];
        for(uint32_t i = 0; i < (*u)->attributeLength; i++){
            read<uint8_t>(ifs, &(*u)->info[i]);
        }
    }
}

template<>
void print<AttributeInfoBasic>(AttributeInfoBasic& u, std::ostream &os){
    print<uint16_t>(u.attributeNameIndex, os);
    print<uint32_t>(u.attributeLength, os);
    for(uint32_t i = 0; i < u.attributeLength; i++){
        os << std::setfill('0') << std::setw(2) << std::right << std::hex << (uint32_t)u.info[i];
        if(i + 1 != u.attributeLength){
            os << " ";
        } else{
            os << "\n";
        }
    }
    os << "\n";
}

