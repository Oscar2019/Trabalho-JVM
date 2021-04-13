#include "../include/ConstantPoolInfo.h"
#include <string>


std::string getClass(ConstantPoolInfo** cp, uint32_t ind){
    CPClass *cpCLassCPClass = (CPClass *)cp[ind];
    return getCPUtf8(cp, cpCLassCPClass->nameIndex);
}

std::string getFieldref(ConstantPoolInfo** cp, uint32_t ind){
    CPFieldref *cpFieldref = (CPFieldref *)cp[ind];
    return getClass(cp, cpFieldref->classIndex) + getNameAndType(cp, cpFieldref->nameAndTypeIndex);
}

std::string getMethodref(ConstantPoolInfo** cp, uint32_t ind){
    CPMethodref *cpMethodref = (CPMethodref *)cp[ind];
    return getClass(cp, cpMethodref->classIndex) + getNameAndType(cp, cpMethodref->nameAndTypeIndex);
}

std::string getInterfaceMethodref(ConstantPoolInfo** cp, uint32_t ind){
    CPInterfaceMethodref *cpInterfaceMethodref = (CPInterfaceMethodref *)cp[ind];
    return getClass(cp, cpInterfaceMethodref->classIndex) + getNameAndType(cp, cpInterfaceMethodref->nameAndTypeIndex);
}

std::string getString(ConstantPoolInfo** cp, uint32_t ind){
    CPString *cpString = (CPString *)cp[ind];
    return getCPUtf8(cp, cpString->stringIndex);
}

int32_t getInteger(ConstantPoolInfo** cp, uint32_t ind){
    CPInteger *cpInteger = (CPInteger *)cp[ind];
    return static_cast<int32_t>(cpInteger->bytes);
}

float getFloat(ConstantPoolInfo** cp, uint32_t ind){
    CPFloat *cpFloat = (CPFloat*)cp[ind];
    return *reinterpret_cast<float*>(&cpFloat->bytes);
}

int64_t getLong(ConstantPoolInfo** cp, uint32_t ind){
    CPLong *cpLong = (CPLong*)cp[ind];
    uint64_t aux = 0;
    aux = (aux << 32) | static_cast<uint64_t>(cpLong->highBytes);
    aux = (aux << 32) | static_cast<uint64_t>(cpLong->lowBytes);
    return static_cast<int64_t>(aux);
}

double getDouble(ConstantPoolInfo** cp, uint32_t ind){
    CPDouble *cpDouble = (CPDouble*)cp[ind];
    uint64_t aux = 0;
    aux = (aux << 32) | cpDouble->highBytes;
    aux = (aux << 32) | cpDouble->lowBytes;
    return *reinterpret_cast<double*>(&aux);
}

std::string getNameAndType(ConstantPoolInfo** cp, uint32_t ind){
    CPNameAndType *cpNameAndType = (CPNameAndType *)cp[ind];
    return getCPUtf8(cp, cpNameAndType->nameIndex) + getCPUtf8(cp, cpNameAndType->descriptorIndex);
}

std::string getCPUtf8(ConstantPoolInfo** cp, uint32_t ind){
    CPUtf8 *cpUtf8 = (CPUtf8 *)cp[ind];
    return std::string((char*)cpUtf8->bytes, cpUtf8->length);
}

std::string getStringFromCPInfo(ConstantPoolInfo** cp, uint32_t ind){
    std::string res;
    switch (cp[ind]->tag){
        case ConstantPoolInfoTag::CLASS:
            res = getClass(cp, ind);
            break;
        case ConstantPoolInfoTag::FIELDREF:
            res = getFieldref(cp, ind);
            break;
        case ConstantPoolInfoTag::METHODREF:
            res = getMethodref(cp, ind);
            break;
        case ConstantPoolInfoTag::INTERFACE_METHODREF:
            res = getInterfaceMethodref(cp, ind);
            break;
        case ConstantPoolInfoTag::STRING:
            res = getString(cp, ind);
            break;
        case ConstantPoolInfoTag::INTEGER:
            res = std::to_string(getInteger(cp, ind));
            break;
        case ConstantPoolInfoTag::FLOAT:
            res = std::to_string(getFloat(cp, ind));
            break;
        case ConstantPoolInfoTag::LONG:
            res = std::to_string(getLong(cp, ind));
            break;
        case ConstantPoolInfoTag::DOUBLE:
            res = std::to_string(getDouble(cp, ind));
            break;
        case ConstantPoolInfoTag::NAME_AND_TYPE:
            res = getNameAndType(cp, ind);
            break;
        case ConstantPoolInfoTag::UTF8:
            res = getCPUtf8(cp, ind);
            break;
        case ConstantPoolInfoTag::METHOD_HANDLE:
            break;
        case ConstantPoolInfoTag::METHOD_TYPE:
            break;
        case ConstantPoolInfoTag::INVOKE_DYNAMIC:
            break;
        default:
            break;
    }
    return res;

}

ConstantPoolInfo::~ConstantPoolInfo(){
}

CPUtf8::~CPUtf8(){
    if(length > 0){
        delete[] bytes;
    }
}

ConstantPoolInfo::ConstantPoolInfo(){
    tag = 0;
}

CPClass::CPClass() : ConstantPoolInfo(){
    nameIndex = 0;
    wasLoaded = false;
    instanceFieldSize = 0;
    instanceMethodSize = 0;
    instanceMethodPointer = nullptr;
    classFile = nullptr;
}

CPFieldref::CPFieldref() : ConstantPoolInfo(){
    classIndex = 0;
    nameAndTypeIndex = 0;
    classFieldValue = nullptr;
    instanceFieldDesloc = -1;
}

CPMethodref::CPMethodref() : ConstantPoolInfo(){
    classIndex = 0;
    nameAndTypeIndex = 0;
    directMethod = nullptr;
    instanceMethodDesloc = -1;
}

CPInterfaceMethodref::CPInterfaceMethodref() : ConstantPoolInfo(){
    classIndex = 0;
    nameAndTypeIndex = 0;
}

CPString::CPString() : ConstantPoolInfo(){
    stringIndex = 0;
}

CPInteger::CPInteger() : ConstantPoolInfo(){
    bytes = 0;
}

CPFloat::CPFloat() : ConstantPoolInfo(){
    bytes = 0;
}

CPLong::CPLong() : ConstantPoolInfo(){
    highBytes = 0;
    lowBytes = 0;
}

CPDouble::CPDouble() : ConstantPoolInfo(){
    highBytes = 0;
    lowBytes = 0;
}

CPNameAndType::CPNameAndType() : ConstantPoolInfo(){
    nameIndex = 0;
    descriptorIndex = 0;
}

CPUtf8::CPUtf8() : ConstantPoolInfo(){
    length = 0;
    bytes = nullptr;
}

CPMethodHandle::CPMethodHandle() : ConstantPoolInfo(){
    referenceKind = 0;
    referenceIndex = 0;
}

CPMethodType::CPMethodType() : ConstantPoolInfo(){
    descriptorIndex = 0;
}

CPInvokeDynamic::CPInvokeDynamic() : ConstantPoolInfo(){
    bootstrapMethodAttrIndex = 0;
    nameAndTypeIndex = 0;
}