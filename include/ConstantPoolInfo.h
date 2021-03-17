#ifndef __CONSTANT_POOL_INFO_H__
#define __CONSTANT_POOL_INFO_H__

#include <cstdint>
#include <string>

enum ConstantPoolInfoTag{
    CLASS = 7, 
    FIELDREF = 9, 
    METHODREF = 10, 
    INTERFACE_METHODREF = 11, 
    STRING = 8, 
    INTEGER = 3, 
    FLOAT = 4, 
    LONG = 5, 
    DOUBLE = 6, 
    NAME_AND_TYPE = 12, 
    UTF8 = 1, 
    METHOD_HANDLE = 15, 
    METHOD_TYPE = 16, 
    INVOKE_DYNAMIC = 18
};

struct ConstantPoolInfo{
    uint8_t tag;
    virtual ~ConstantPoolInfo();
};

std::string getStringFromCPInfo(ConstantPoolInfo** cp, uint32_t ind);

struct CPClass : public ConstantPoolInfo{
    uint16_t nameIndex;
};

std::string getClass(ConstantPoolInfo** cp, uint32_t ind);

struct CPFieldref : public ConstantPoolInfo{
    uint16_t classIndex;
    uint16_t nameAndTypeIndex;
};

std::string getFieldref(ConstantPoolInfo** cp, uint32_t ind);

struct CPMethodref : public ConstantPoolInfo{
    uint16_t classIndex;
    uint16_t nameAndTypeIndex;
};

std::string getMethodref(ConstantPoolInfo** cp, uint32_t ind);

struct CPInterfaceMethodref : public ConstantPoolInfo{
    uint16_t classIndex;
    uint16_t nameAndTypeIndex;
};

std::string getInterfaceMethodref(ConstantPoolInfo** cp, uint32_t ind);

struct CPString : public ConstantPoolInfo{
    uint16_t stringIndex;
};

std::string getString(ConstantPoolInfo** cp, uint32_t ind);

struct CPInteger : public ConstantPoolInfo{
    uint32_t bytes;
};

int32_t getInteger(ConstantPoolInfo** cp, uint32_t ind);

struct CPFloat : public ConstantPoolInfo{
    uint32_t bytes;
};

float getFloat(ConstantPoolInfo** cp, uint32_t ind);

struct CPLong : public ConstantPoolInfo{
    uint32_t highBytes;
    uint32_t lowBytes;
};

int64_t getLong(ConstantPoolInfo** cp, uint32_t ind);

struct CPDouble : public ConstantPoolInfo{
    uint32_t highBytes;
    uint32_t lowBytes;
};

double getDouble(ConstantPoolInfo** cp, uint32_t ind);

struct CPNameAndType : public ConstantPoolInfo{
    uint16_t nameIndex;
    uint16_t descriptorIndex;
};

std::string getNameAndType(ConstantPoolInfo** cp, uint32_t ind);

struct CPUtf8 : public ConstantPoolInfo{
    uint16_t length;
    uint8_t* bytes;
    ~CPUtf8();
};

std::string getCPUtf8(ConstantPoolInfo** cp, uint32_t ind);

struct CPMethodHandle : public ConstantPoolInfo{
    uint8_t referenceKind;
    uint16_t referenceIndex;
};

struct CPMethodType : public ConstantPoolInfo{
    uint16_t descriptorIndex;
};

struct CPInvokeDynamic : public ConstantPoolInfo{
    uint16_t bootstrapMethodAttrIndex;
    uint16_t nameAndTypeIndex;
};

#endif