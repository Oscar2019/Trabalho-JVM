#ifndef __CONSTANT_POOL_INFO_H__
#define __CONSTANT_POOL_INFO_H__

#include <cstdint>
#include <string>

/**
 * @brief Enum que contém o número das tags
 * 
 */
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

/**
 * @brief Estrutura base de todos os constant Pool
 * 
 */
struct ConstantPoolInfo{
    /**
     * @brief O tipo de valor que essa ConstantPool armazena
     * 
     */
    uint8_t tag;
    /**
     * @brief Construct a new Constant Pool Info object
     * 
     */
    ConstantPoolInfo();
    /**
     * @brief Destrói os objetos de um ConstantPoolInfo 
     * 
     */
    virtual ~ConstantPoolInfo();
};

/**
 * @brief Gera uma string do ConstantPoolInfo no índice ind
 * 
 * @param cp 
 * @param ind 
 * @return std::string 
 */
std::string getStringFromCPInfo(ConstantPoolInfo** cp, uint32_t ind);

/**
 * @brief Estrutura usada para representar uma classe ou interface.
 * 
 */
struct CPClass : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPClass object
     * 
     */
    CPClass();
    /**
     * @brief Ídice para a tabela do ConstantPool que contém um CPUtf8.
     * 
     */
    uint16_t nameIndex;
};

/**
 * @brief Gera a string que é apontada pelo nameIndex
 * 
 * @param cp 
 * @param ind 
 * @return std::string 
 */
std::string getClass(ConstantPoolInfo** cp, uint32_t ind);

/**
 * @brief Estrutura usada para representar um campo.
 * 
 */
struct CPFieldref : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPFieldref object
     * 
     */
    CPFieldref();
    /**
     * @brief Ídice para a tabela do ConstantPool que contém um CPClass.
     * 
     */
    uint16_t classIndex;
    /**
     * @brief Ídice para a tabela do ConstantPool que contém um CPNameAndType.
     * 
     */
    uint16_t nameAndTypeIndex; 
};

/**
 * @brief Gera a string
 * 
 * @param cp 
 * @param ind 
 * @return std::string 
 */
std::string getFieldref(ConstantPoolInfo** cp, uint32_t ind);

/**
 * @brief Estrutura usada para representar um método.
 * 
 */
struct CPMethodref : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPMethodref object
     * 
     */
    CPMethodref();
    /**
     * @brief Ídice para a tabela do ConstantPool que contém um CPClass.
     * 
     */
    uint16_t classIndex;
    /**
     * @brief Ídice para a tabela do ConstantPool que contém um CPNameAndType.
     * 
     */
    uint16_t nameAndTypeIndex;
};

/**
 * @brief Gera a string
 * 
 * @param cp 
 * @param ind 
 * @return std::string 
 */
std::string getMethodref(ConstantPoolInfo** cp, uint32_t ind);

/**
 * @brief Estrutura usada para representar um método de interface.
 * 
 */
struct CPInterfaceMethodref : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPInterfaceMethodref object
     * 
     */
    CPInterfaceMethodref();
    /**
     * @brief Ídice para a tabela do ConstantPool que contém um CPClass.
     * 
     */
    uint16_t classIndex;
    /**
     * @brief Ídice para a tabela do ConstantPool que contém um CPNameAndType.
     * 
     */
    uint16_t nameAndTypeIndex;
};

/**
 * @brief Gera a string
 * 
 * @param cp 
 * @param ind 
 * @return std::string 
 */
std::string getInterfaceMethodref(ConstantPoolInfo** cp, uint32_t ind);

/**
 * @brief Estrutura usada para representar uma objeto de uma strnig.
 * 
 */
struct CPString : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPString object
     * 
     */
    CPString();
    /**
     * @brief Ídice para a tabela do ConstantPool que contém um CPUtf8.
     * 
     */
    uint16_t stringIndex;
};

/**
 * @brief Gera a string
 * 
 * @param cp 
 * @param ind 
 * @return std::string 
 */
std::string getString(ConstantPoolInfo** cp, uint32_t ind);

/**
 * @brief Estrutura usada para representar um inteiro.
 * 
 */
struct CPInteger : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPInteger object
     * 
     */
    CPInteger();
    /**
     * @brief Bytes do inteiro.
     * 
     */
    uint32_t bytes;
};

/**
 * @brief Gera um inteiro que está sendo armazenado no CPInteger.
 * 
 * @param cp 
 * @param ind 
 * @return int32_t 
 */
int32_t getInteger(ConstantPoolInfo** cp, uint32_t ind);

/**
 * @brief Estrutura usada para representar um float.
 * 
 */
struct CPFloat : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPFloat object
     * 
     */
    CPFloat();
    /**
     * @brief Bytes do float.
     * 
     */
    uint32_t bytes;
};

/**
 * @brief Gera um float que está sendo armazenado no CPFloat.
 * 
 * @param cp 
 * @param ind 
 * @return float 
 */
float getFloat(ConstantPoolInfo** cp, uint32_t ind);

/**
 * @brief Estrutura usada para representar um long.
 * 
 */
struct CPLong : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPLong object
     * 
     */
    CPLong();
    /**
     * @brief Bytes menos significativos do long
     * 
     */
    uint32_t highBytes;
    /**
     * @brief Bytes mais significativos do long 
     * 
     */
    uint32_t lowBytes;
};

/**
 * @brief Gera um long que está sendo armazenado no CPLong.
 * 
 * @param cp 
 * @param ind 
 * @return int64_t 
 */
int64_t getLong(ConstantPoolInfo** cp, uint32_t ind);

/**
 * @brief Estrutura usada para representar um double.
 * 
 */
struct CPDouble : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPDouble object
     * 
     */
    CPDouble();
    /**
     * @brief Bytes menos significativos do long
     * 
     */
    uint32_t highBytes;
    /**
     * @brief Bytes mais significativos do long 
     * 
     */
    uint32_t lowBytes;
};


/**
 * @brief Gera um double que está sendo armazenado no CPDouble.
 * 
 * @param cp 
 * @param ind 
 * @return double 
 */
double getDouble(ConstantPoolInfo** cp, uint32_t ind);

/**
 * @brief Estrutura usada para representa um campo ou método sem informar a que classe ou interface ele pertence. 
 * 
 */
struct CPNameAndType : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPNameAndType object
     * 
     */
    CPNameAndType();
    /**
     * @brief Ídice para a tabela do ConstantPool que contém um CPUtf8.
     * 
     */
    uint16_t nameIndex;
    /**
     * @brief Ídice para a tabela do ConstantPool que contém um CPUtf8.
     * 
     */
    uint16_t descriptorIndex;
};

/**
 * @brief Gera a string
 * 
 * @param cp 
 * @param ind 
 * @return std::string 
 */
std::string getNameAndType(ConstantPoolInfo** cp, uint32_t ind);

/**
 * @brief Estrutura que armazena uma string
 * 
 */
struct CPUtf8 : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPUtf8 object
     * 
     */
    CPUtf8();
    /**
     * @brief tamanho na string
     * 
     */
    uint16_t length;
    /**
     * @brief vetor que armazena os bytes da string
     * 
     */
    uint8_t* bytes;
    /**
     * @brief Destrói um objeto CPUtf8
     * 
     */
    ~CPUtf8();
};

/**
 * @brief Gera uma string que está sendo armazenada por CPUtf8
 * 
 * @param cp 
 * @param ind 
 * @return std::string 
 */
std::string getCPUtf8(ConstantPoolInfo** cp, uint32_t ind);

/**
 * @brief 
 * 
 */
struct CPMethodHandle : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPMethodHandle object
     * 
     */
    CPMethodHandle();
    /**
     * @brief 
     * 
     */
    uint8_t referenceKind;
    /**
     * @brief 
     * 
     */
    uint16_t referenceIndex;
};

/**
 * @brief 
 * 
 */
struct CPMethodType : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPMethodType object
     * 
     */
    CPMethodType();
    /**
     * @brief 
     * 
     */
    uint16_t descriptorIndex;
};

/**
 * @brief 
 * 
 */
struct CPInvokeDynamic : public ConstantPoolInfo{
    /**
     * @brief Construct a new CPInvokeDynamic object
     * 
     */
    CPInvokeDynamic();
    /**
     * @brief 
     * 
     */
    uint16_t bootstrapMethodAttrIndex;
    /**
     * @brief 
     * 
     */
    uint16_t nameAndTypeIndex;
};

#endif