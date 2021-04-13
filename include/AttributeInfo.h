#ifndef __CLASS_ATTRIBUTE_H__
#define __CLASS_ATTRIBUTE_H__

#include <cstdint>
#include "../include/ConstantPoolInfo.h"

struct AttributeInfo{
    uint16_t attributeNameIndex;
    uint32_t attributeLength;
    AttributeInfo();
    virtual ~AttributeInfo();
};

struct AttributeInfoBasic : AttributeInfo{
    uint8_t *info;
    AttributeInfoBasic();
    ~AttributeInfoBasic();
};

struct AttributeInfoConstantValue : AttributeInfo{
    uint16_t constantvalueIndex;
    AttributeInfoConstantValue();
};

struct AttributeInfoCode : AttributeInfo{
    uint16_t maxStack;
    uint16_t maxLocals;
    uint32_t codeLength;
    uint8_t *code;
    uint16_t exceptionTableLength;
    struct ExceptionTable{
        uint16_t startPc;
        uint16_t endPc;
        uint16_t handlerPc;
        uint16_t catchType;
    };
    ExceptionTable *exceptionTable;
    uint16_t attributesCount;
    AttributeInfo **attributes;
    AttributeInfoCode();
    ~AttributeInfoCode();
};

struct AttributeInfoExceptions : AttributeInfo{
    uint16_t numberOfExceptions;
    uint16_t *exceptionIndexTable;
    AttributeInfoExceptions();
    ~AttributeInfoExceptions();
};

struct AttributeInfoInnerClasses : AttributeInfo{
    uint16_t numberOfClasses;
    struct Class{   
        uint16_t innerClassInfoIndex;
        uint16_t outerClassInfoIndex;
        uint16_t innerNameIndex;
        uint16_t innerClassAccessFlags;
    };
    Class *classes;
    AttributeInfoInnerClasses();
    ~AttributeInfoInnerClasses();
};

struct AttributeInfoSynthetic : AttributeInfo{
    AttributeInfoSynthetic();
};

struct AttributeInfoSourceFile : AttributeInfo{
    uint16_t sourcefileIndex;
    AttributeInfoSourceFile();
};

struct AttributeInfoLineNumberTable	 : AttributeInfo{
    uint16_t lineNumberTableLength;
    struct LineNumberTable{   
        uint16_t startPc;
        uint16_t lineNumber;	
    };
    LineNumberTable *lineNumberTable;
    AttributeInfoLineNumberTable();
    ~AttributeInfoLineNumberTable();
};

struct AttributeInfoLocalVariableTable : AttributeInfo{
    uint16_t localVariableTableLength;
    struct LocalVariableTable{   
        uint16_t startPc;
        uint16_t length;
        uint16_t nameIndex;
        uint16_t descriptorIndex;
        uint16_t index;
    };
    LocalVariableTable *localVariableTable;
    AttributeInfoLocalVariableTable();
    ~AttributeInfoLocalVariableTable();
};

struct AttributeInfoDeprecated : AttributeInfo{
    AttributeInfoDeprecated(); 
};

// struct AttributeInfoStackMapTable : AttributeInfo{
//     uint16_t numberOfEntries;
//     // StackMapFrame *entries;
// };
// struct AttributeInfoEnclosingMethod : AttributeInfo{
//     uint16_t classIndex;
//     uint16_t methodIndex;
// };
// struct AttributeInfoSignature : AttributeInfo{
//     uint16_t signatureIndex;
// };
// struct AttributeInfoSourceDebugExtension : AttributeInfo{
//     uint8_t *debug_Extension;
// };
// struct AttributeInfoLocalVariableTypeTable : AttributeInfo{
//     uint16_t localVariableTypeTableLength;
//     struct {   uint16_t startPc;
//         uint16_t length;
//         uint16_t nameIndex;
//         uint16_t signatureIndex;
//         uint16_t index;
//     } *localVariableTypeTable;
// };
// struct AttributeInfoRuntimeVisibleAnnotations : AttributeInfo{
//     uint16_t num_annotations;
//     // Annotation *annotations;
// };

// struct AttributeInfoRuntimeInvisibleAnnotations : AttributeInfo{
//     uint16_t num_annotations;
//     // Annotation *annotations;
// };

// struct AttributeInfoRuntimeVisibleParameterAnnotations : AttributeInfo{
//     uint8_t numParameters;
//     struct {   
//         uint16_t numAnnotations;
//         // Annotation *annotations;
//     } *parameterAnnotations;
// };

// struct AttributeInfoRuntimeInvisibleParameterAnnotations : AttributeInfo{
//     uint8_t numParameters;
//     struct {   
//         uint16_t numAnnotations;
//         // Annotation *annotations;
//     } *parameterAnnotations;
// };

// struct AttributeInfoRuntimeVisibleTypeAnnotations : AttributeInfo{
//     uint8_t numAnnotations;
//     // TypeAnnotation *annotations;
// };

// struct AttributeInfoRuntimeInvisibleTypeAnnotations : AttributeInfo{
//     uint8_t numAnnotations;
//     // TypeAnnotation *annotations;
// };

// struct AttributeInfoAnnotationDefault : AttributeInfo{
//     // ElementValue defaultValue;
// };

// struct AttributeInfoBootstrapMethods : AttributeInfo{
//     uint16_t numBootstrapMethods;
//     struct {   uint16_t bootstrapMethodRef;
//         uint16_t numBootstrapArguments;
//         uint16_t *bootstrapArguments;
//     } *bootstrap_methods;
// };

// struct AttributeInfoMethodParameters : AttributeInfo{
//     uint8_t parameters_count;
//     struct {   
//         uint16_t name_index;
//         uint16_t access_flags;
//     } *parameters;
// };

void conveterAttributeInfoInAttributeInfo(ConstantPoolInfo **cf, AttributeInfo **ai);

#endif
