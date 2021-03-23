#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>

#include "../include/ClassFile.h"
#include "../include/Tipos.h"
#include "../include/ISA.h"

#ifdef _WIN32
#define CLEAR() system("CLS")
#else
#define CLEAR() system("clear")
#endif

void printMenu(ClassFile const& cf);
void printGeneralInformation(ClassFile const& cf);
void printConstantPool(ClassFile const& cf);
void printInterfaces(ClassFile const& cf);
void printFields(ClassFile const& cf);
void printField(ClassFile const& cf, FieldInfo *field);
void printMethods(ClassFile const& cf);
void printMethod(ClassFile const& cf, MethodInfo *field);
void printAttributes(ClassFile const& cf);
void printAttribute(ClassFile const& cf, AttributeInfo *attribute);
void printAttributeConstantValue(ClassFile const& cf, AttributeInfoConstantValue *attribute);
void printAttributeCode(ClassFile const& cf, AttributeInfoCode *attribute);
void printAssemplyCode(ClassFile const& cf, uint32_t codeSize, uint8_t *code);
void printAttributeExceptions(ClassFile const& cf, AttributeInfoExceptions *attribute);
void printAttributeInnerClasses(ClassFile const& cf, AttributeInfoInnerClasses *attribute);
void printAttributeSynthetic(ClassFile const& cf, AttributeInfoSynthetic *attribute);
void printAttributeSourceFile(ClassFile const& cf, AttributeInfoSourceFile *attribute);
void printAttributeLineNumberTable(ClassFile const& cf, AttributeInfoLineNumberTable *attribute);
void printAttributeLocalVariableTable(ClassFile const& cf, AttributeInfoLocalVariableTable *attribute);
void printAttributeDeprecated(ClassFile const& cf, AttributeInfoDeprecated *attribute);

int main(int argc, char *argv[]){
    
    std::ifstream is;
    std::string s;
    if(argc == 1){
        std::cin >> s;
    } else{
        s = argv[1];
    }
    std::cout << s << "\n";
    is.open(s, std::ios::binary);
    is.exceptions(std::ifstream::eofbit);
    ClassFile cf;
    read<ClassFile>(is, &cf);
    conveterAttributeInfoInClassFile(cf.constantPool, &cf);
    // print<ClassFile>(cf, std::cout);
    printMenu(cf);
    return 0;
}

void printMenu(ClassFile const& cf){
    int32_t option = -1;
    while(option != 6){
        CLEAR();
        std::cout << "0: General Information\n"; 
        std::cout << "1: Constant Pool\n"; 
        std::cout << "2: Interfaces\n"; 
        std::cout << "3: Fields\n"; 
        std::cout << "4: Methods\n"; 
        std::cout << "5: Attributes\n"; 
        std::cout << "6: Sair\n";
        std::cout << "Digite uma opcao: ";
        std::cin >> option;
        switch (option){
            case 0:
                printGeneralInformation(cf);
                break;
            case 1:
                printConstantPool(cf);
                break;
            case 2:
                printInterfaces(cf);
                break;
            case 3:
                printFields(cf);
                break;
            case 4:
                printMethods(cf);
                break;
            case 5:
                printAttributes(cf);
                break;
            case 6:
                break;
            default:
                std::cout << "Opcao invalida!\nDigite novamente.\n";
                std::cout << "Aperte <ENTER> para voltar.\n";
                getchar();
                break;
        }
    }
}


void printGeneralInformation(ClassFile const& cf){
    CLEAR();
    std::cout << "Minor version: " << cf.minorVersion << "\n"; 
    std::cout << "Major version: " << cf.majorVersion << "\n"; 
    std::cout << "Constantpool Count: " << cf.constantPoolCount << "\n"; 
    std::cout << "Access flags: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cf.accessFlags << std::dec << "\n"; 
    std::cout << "This class: <" << getClass(cf.constantPool, cf.thisClass) << ">\n"; 
    std::cout << "Super class: <" << (cf.superClass == 0 ? "null" : getClass(cf.constantPool, cf.superClass)) << ">\n"; 
    std::cout << "Interface count: " << cf.interfacesCount << "\n";
    std::cout << "Fields count: " << cf.fieldsCount << "\n";
    std::cout << "Methods count: " << cf.methodsCount << "\n";
    std::cout << "Attributes count: " << cf.attributesCount << "\n";
    std::cout << "Aperte <ENTER> para voltar";
    getchar();getchar();
}


void printConstantPool(ClassFile const& cf){
    uint32_t option = -1;
    while(option != cf.constantPoolCount){
        CLEAR();
        for(uint32_t i = 1; i < cf.constantPoolCount; i++){
            std::cout << "[" << i << "] ";
            if(cf.constantPool[i] != nullptr){
                switch (cf.constantPool[i]->tag){
                    case ConstantPoolInfoTag::CLASS:
                        std::cout << "CONSTANT_Class\n";
                        break;
                    case ConstantPoolInfoTag::FIELDREF:
                        std::cout << "CONSTANT_Fieldref\n";
                        break;
                    case ConstantPoolInfoTag::METHODREF:
                        std::cout << "CONSTANT_Methodref\n";
                        break;
                    case ConstantPoolInfoTag::INTERFACE_METHODREF:
                        std::cout << "CONSTANT_InterfaceMethodref\n";
                        break;
                    case ConstantPoolInfoTag::STRING:
                        std::cout << "CONSTANT_String\n";
                        break;
                    case ConstantPoolInfoTag::INTEGER:
                        std::cout << "CONSTANT_Integer\n";
                        break;
                    case ConstantPoolInfoTag::FLOAT:
                        std::cout << "CONSTANT_Float\n";
                        break;
                    case ConstantPoolInfoTag::LONG:
                        std::cout << "CONSTANT_Long\n";
                        break;
                    case ConstantPoolInfoTag::DOUBLE:
                        std::cout << "CONSTANT_Double\n";
                        break;
                    case ConstantPoolInfoTag::NAME_AND_TYPE:
                        std::cout << "CONSTANT_NameAndType\n";
                        break;
                    case ConstantPoolInfoTag::UTF8:
                        std::cout << "CONSTANT_Utf8\n";
                        break;
                    case ConstantPoolInfoTag::METHOD_HANDLE:
                        std::cout << "CONSTANT_MethodHandle\n";
                        break;
                    case ConstantPoolInfoTag::METHOD_TYPE:
                        std::cout << "CONSTANT_MethodType\n";
                        break;
                    case ConstantPoolInfoTag::INVOKE_DYNAMIC:
                        std::cout << "CONSTANT_InvokeDynamic\n";
                        break;
                    default:
                        break;
                }
            } else{
                std::cout << "null\n";
            }
        }
        std::cout << "[" << cf.constantPoolCount << "] Sair\n";
        std::cout << "Digite uma opcao: ";
        std::cin >> option;
        CLEAR();
        if(option < cf.constantPoolCount){
            if(cf.constantPool[option] != nullptr){
                switch (cf.constantPool[option]->tag){
                    case ConstantPoolInfoTag::CLASS:{
                        CPClass *cp = dynamic_cast<CPClass*>(cf.constantPool[option]);
                        std::cout << "Class name: <" << getClass(cf.constantPool, option) << "> // #" << cp->nameIndex << "\n";
                        }
                        break;
                    case ConstantPoolInfoTag::FIELDREF:{
                        CPFieldref *cp = dynamic_cast<CPFieldref*>(cf.constantPool[option]);
                        std::cout << "Class name: <" << getClass(cf.constantPool, cp->classIndex) << "> // #" << cp->classIndex << "\n";
                        std::cout << "Name and type: <" << getNameAndType(cf.constantPool, cp->nameAndTypeIndex) << "> // #" << cp->nameAndTypeIndex << "\n";
                        }
                        break;
                    case ConstantPoolInfoTag::METHODREF:{
                        CPMethodref *cp = dynamic_cast<CPMethodref*>(cf.constantPool[option]);
                        std::cout << "Class name: <" << getClass(cf.constantPool, cp->classIndex) << "> // #" << cp->classIndex << "\n";
                        std::cout << "Name and type: <" << getNameAndType(cf.constantPool, cp->nameAndTypeIndex) << "> // #" << cp->nameAndTypeIndex << "\n";
                        }
                        break;
                    case ConstantPoolInfoTag::INTERFACE_METHODREF:{
                        CPInterfaceMethodref *cp = dynamic_cast<CPInterfaceMethodref*>(cf.constantPool[option]);
                        std::cout << "Class name: <" << getClass(cf.constantPool, cp->classIndex) << "> // #" << cp->classIndex << "\n";
                        std::cout << "Name and type: <" << getNameAndType(cf.constantPool, cp->nameAndTypeIndex) << "> // #" << cp->nameAndTypeIndex << "\n";
                        }
                        break;
                    case ConstantPoolInfoTag::STRING:{
                        CPString *cp = dynamic_cast<CPString*>(cf.constantPool[option]);
                        std::cout << "String: <" << getCPUtf8(cf.constantPool, cp->stringIndex) << "> // #" << cp->stringIndex << "\n";
                        }
                        break;
                    case ConstantPoolInfoTag::INTEGER:{
                        CPInteger *cp = dynamic_cast<CPInteger*>(cf.constantPool[option]);
                        std::cout << "Bytes: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cp->bytes << std::dec << "\n";
                        std::cout << "Integer: " << getInteger(cf.constantPool, option) << "\n";
                        }
                        break;
                    case ConstantPoolInfoTag::FLOAT:{
                        CPFloat *cp = dynamic_cast<CPFloat*>(cf.constantPool[option]);
                        std::cout << "Bytes: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cp->bytes << std::dec << "\n";
                        std::cout << "Float: " << getFloat(cf.constantPool, option) << "\n";
                        }
                        break;
                    case ConstantPoolInfoTag::LONG:{
                        CPLong *cp = dynamic_cast<CPLong*>(cf.constantPool[option]);
                        std::cout << "High bytes: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cp->highBytes << std::dec << "\n";
                        std::cout << "Low bytes: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cp->lowBytes << std::dec << "\n";
                        std::cout << "Integer: " << getLong(cf.constantPool, option) << "\n";
                        }
                        break;
                    case ConstantPoolInfoTag::DOUBLE:{
                        CPDouble *cp = dynamic_cast<CPDouble*>(cf.constantPool[option]);
                        std::cout << "High bytes: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cp->highBytes << std::dec << "\n";
                        std::cout << "Low bytes: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cp->lowBytes << std::dec << "\n";
                        std::cout << "Integer: " << getDouble(cf.constantPool, option) << "\n";
                        }
                        break;
                    case ConstantPoolInfoTag::NAME_AND_TYPE:{
                        CPNameAndType *cp = dynamic_cast<CPNameAndType*>(cf.constantPool[option]);
                        std::cout << "Name: <" << getCPUtf8(cf.constantPool, cp->nameIndex) << "> // #" << cp->nameIndex << "\n";
                        std::cout << "Descriptor: <" << getCPUtf8(cf.constantPool, cp->descriptorIndex) << "> // #" << cp->descriptorIndex << "\n";
                        }
                        break;
                    case ConstantPoolInfoTag::UTF8:{
                        CPUtf8 *cp = dynamic_cast<CPUtf8*>(cf.constantPool[option]);
                        std::cout << "Lenght of string: " << cp->length << "\n";
                        std::cout << "String: " << getCPUtf8(cf.constantPool, option) << "\n";
                        }
                        break;
                    case ConstantPoolInfoTag::METHOD_HANDLE:
                        std::cout << "CONSTANT_MethodHandle\n";
                        break;
                    case ConstantPoolInfoTag::METHOD_TYPE:
                        std::cout << "CONSTANT_MethodType\n";
                        break;
                    case ConstantPoolInfoTag::INVOKE_DYNAMIC:
                        std::cout << "CONSTANT_InvokeDynamic\n";
                        break;
                    default:
                        break;
                }
            } else{
                std::cout << "null\n";
            }
        } else{
            break;
        }
        std::cout << "Aperte <ENTER> para voltar";
        getchar();getchar();
    }
}


void printInterfaces(ClassFile const& cf){
    CLEAR();
    for(uint32_t i = 0; i < cf.interfacesCount; i++){
        std::cout << "[" << i << "] ";
        std::cout << getClass(cf.constantPool, cf.interfaces[i]) << "\n";
    }
    std::cout << "Aperte <ENTER> para voltar";
    getchar();getchar();
}

void printFields(ClassFile const& cf){
    int32_t option = -1;
    while(option != cf.fieldsCount){
        CLEAR();
        for(uint32_t i = 0; i < cf.fieldsCount; i++){
            std::cout << "[" << i << "] ";
            std::cout << getCPUtf8(cf.constantPool, cf.fields[i].nameIndex) << "\n";
        }
        std::cout << "[" << cf.fieldsCount << "] Sair\n";
        std::cout << "Digite uma opcao: ";
        std::cin >> option;
        if(0 <= option && option < cf.fieldsCount){
            printField(cf, cf.fields + option);
        } else{
            option = cf.fieldsCount;
        }
    }
    std::cout << "Aperte <ENTER> para voltar";
    getchar();getchar();
}

void printField(ClassFile const& cf, FieldInfo *field){
    int32_t option = -1;
    while(option != field->attributesCount){
        CLEAR();
        std::cout << "Name: " << getCPUtf8(cf.constantPool, field->nameIndex) << "\n";    
        std::cout << "Descrictor: " << getCPUtf8(cf.constantPool, field->descriptorIndex) << "\n";
        std::cout << "Access flags: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)field->accessFlags << std::dec << "\n";    
        for(uint32_t i = 0; i < field->attributesCount; i++){
            std::cout << "[" << i << "] ";
            std::cout << getCPUtf8(cf.constantPool, field->attributes[i]->attributeNameIndex) << "\n";
        }
        std::cout << "[" << cf.fieldsCount << "] Sair\n";
        std::cout << "Digite uma opcao: ";
        std::cin >> option;
        if(0 <= option && option < cf.fieldsCount){
            printAttribute(cf, field->attributes[option]);
        } else{
            option = cf.fieldsCount;
        }
    }
}

void printMethods(ClassFile const& cf){
    int32_t option = -1;
    while(option != cf.methodsCount){
        CLEAR();
        for(uint32_t i = 0; i < cf.methodsCount; i++){
            std::cout << "[" << i << "] ";
            std::cout << getCPUtf8(cf.constantPool, cf.methods[i].nameIndex) << "\n";
        }
        std::cout << "[" << cf.methodsCount << "] Sair\n";
        std::cout << "Digite uma opcao: ";
        std::cin >> option;
        if(0 <= option && option < cf.methodsCount){
            printMethod(cf, cf.methods + option);
        } else{
            option = cf.methodsCount;
        }
    }
    std::cout << "Aperte <ENTER> para voltar";
    getchar();getchar();
}

void printMethod(ClassFile const& cf, MethodInfo *method){
    int32_t option = -1;
    while(option != method->attributesCount){
        CLEAR();
        std::cout << "Name: " << getCPUtf8(cf.constantPool, method->nameIndex) << "\n";    
        std::cout << "Descrictor: " << getCPUtf8(cf.constantPool, method->descriptorIndex) << "\n";
        std::cout << "Access flags: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)method->accessFlags << std::dec << "\n";    
        for(uint32_t i = 0; i < method->attributesCount; i++){
            std::cout << "[" << i << "] ";
            std::cout << getCPUtf8(cf.constantPool, method->attributes[i]->attributeNameIndex) << "\n";
        }
        std::cout << "[" << method->attributesCount << "] Sair\n";
        std::cout << "Digite uma opcao: ";
        std::cin >> option;
        if(0 <= option && option <  method->attributesCount){
            printAttribute(cf, method->attributes[option]);
        } else{
            option = method->attributesCount;
        }
    }
}

void printAttribute(ClassFile const& cf, AttributeInfo *attribute){
    CLEAR();
    std::string name = getCPUtf8(cf.constantPool, attribute->attributeNameIndex);
    if(name == "ConstantValue"){
        printAttributeConstantValue(cf, dynamic_cast<AttributeInfoConstantValue*>(attribute));
    } else if(name == "Code"){
        printAttributeCode(cf, dynamic_cast<AttributeInfoCode*>(attribute));
    } else if(name == "Exceptions"){
        printAttributeExceptions(cf, dynamic_cast<AttributeInfoExceptions*>(attribute));
    } else if(name == "InnerClasses"){
        printAttributeInnerClasses(cf, dynamic_cast<AttributeInfoInnerClasses*>(attribute));
    } else if(name == "Synthetic"){
        printAttributeSynthetic(cf, dynamic_cast<AttributeInfoSynthetic*>(attribute));
    } else if(name == "SourceFile"){
        printAttributeSourceFile(cf, dynamic_cast<AttributeInfoSourceFile*>(attribute));
    } else if(name == "LineNumberTable"){
        printAttributeLineNumberTable(cf, dynamic_cast<AttributeInfoLineNumberTable*>(attribute));
    } else if(name == "LocalVariableTable"){
        printAttributeLocalVariableTable(cf, dynamic_cast<AttributeInfoLocalVariableTable*>(attribute));
    } else if(name == "Deprecated"){   
        printAttributeDeprecated(cf, dynamic_cast<AttributeInfoDeprecated*>(attribute)); 
    }
    getchar();getchar();
}

void printAttributeConstantValue(ClassFile const& cf, AttributeInfoConstantValue *attribute){
    std::cout << "Name: " << getCPUtf8(cf.constantPool, attribute->attributeNameIndex) << "\n";        
    std::cout << "indexValue: #" <<  attribute->constantvalueIndex << " " << getStringFromCPInfo(cf.constantPool, attribute->constantvalueIndex) << "\n";
}

void printAttributeCode(ClassFile const& cf, AttributeInfoCode *attribute){
    int32_t option = -1;
    while(option != attribute->attributesCount + 2){
        CLEAR();
        std::cout << "Name: " << getCPUtf8(cf.constantPool, attribute->attributeNameIndex) << "\n";        
        std::cout << "Max stack: " <<  attribute->maxStack << "\n";
        std::cout << "Max locals: " <<  attribute->maxLocals << "\n";
        std::cout << "[0] Code\n";
        std::cout << "[1] Exception Table\n";
        for(uint32_t i = 0; i < attribute->attributesCount; i++){
            std::cout << "[" << i + 2 << "] ";
            std::cout << getCPUtf8(cf.constantPool, attribute->attributes[i]->attributeNameIndex) << "\n";
        }
        std::cout << "[" << attribute->attributesCount + 2 << "] Sair\n";
        std::cout << "Digite uma opcao: ";
        std::cin >> option;
        if(option == 0){
            printAssemplyCode(cf, attribute->codeLength, attribute->code);
        } else if(option == 1){
            CLEAR();

            std::cout << "\tStart PC; End PC; Handler PC; Catch type\n";
            for(uint32_t i = 0; i < attribute->exceptionTableLength; i++){
                std::cout << "\t" << attribute->exceptionTable[i].startPc << ";";
                std::cout << " " << attribute->exceptionTable[i].endPc << ";";
                std::cout << " " << attribute->exceptionTable[i].handlerPc << ";";
                std::cout << " " << attribute->exceptionTable[i].catchType << "\n";
            }
            getchar();getchar();
        } else if(2 <= option && option < attribute->attributesCount + 2){
            printAttribute(cf, attribute->attributes[option - 2]);
        } else{
            break;
        }
    }
    std::cout << "Aperte <ENTER> para voltar";
}

void printAssemplyCode(ClassFile const& cf, uint32_t codeSize, uint8_t *code){
    CLEAR();
    for(uint32_t pc = 0, line = 1; pc < codeSize; pc++, line++){
        uint32_t offset = qtdAttributes[code[pc]](code, pc, codeSize);
        std::cout << line << " : " << pc << " : " << printMnemonic[code[pc]](cf.constantPool, code, pc, codeSize);
        pc += offset;
    }
    std::cout << "Aperte <ENTER> para voltar";
    getchar();getchar();
}


void printAttributes(ClassFile const& cf){
    int32_t option = -1;
    while(option != cf.attributesCount){
        CLEAR();
        for(uint32_t i = 0; i < cf.attributesCount; i++){
            std::cout << "[" << i << "] ";
            std::cout << getCPUtf8(cf.constantPool, cf.attributes[i]->attributeNameIndex) << "\n";
        }
        std::cout << "[" << cf.attributesCount << "] Sair\n";
        std::cout << "Digite uma opcao: ";
        std::cin >> option;
        if(0 <= option && option < cf.attributesCount){
            printAttribute(cf, cf.attributes[option]);
        } else{
            option = cf.attributesCount;
        }
    }
    std::cout << "Aperte <ENTER> para voltar";
    getchar();getchar();
}


void printAttributeExceptions(ClassFile const& cf, AttributeInfoExceptions *attribute){
    std::cout << attribute->numberOfExceptions << "\n";
    std::cout << "num: exceptions\n";
    for(int32_t i = 0; i < attribute->numberOfExceptions; i++){
        std::cout  << i << ": #" << attribute->exceptionIndexTable[i] << " <" << getClass(cf.constantPool, attribute->exceptionIndexTable[i]) << ">\n";
    }
}

void printAttributeInnerClasses(ClassFile const& cf, AttributeInfoInnerClasses *attribute){
    std::cout << attribute->numberOfClasses << "\n";
    std::cout << "num: Inner Class Info Index; Outer Class Info Index; Inner Name Index; Inner Class Access Flags\n";
    for(int32_t i = 0; i < attribute->numberOfClasses; i++){
        std::cout << i << ": #" << attribute->classes[i].innerClassInfoIndex << " <" << getClass(cf.constantPool, attribute->classes[i].innerClassInfoIndex) << ">; " << attribute->classes[i].outerClassInfoIndex << " <" << getClass(cf.constantPool, attribute->classes[i].outerClassInfoIndex) << ">; " << attribute->classes[i].innerNameIndex << " <" << getCPUtf8(cf.constantPool, attribute->classes[i].innerNameIndex) << ">; " << attribute->classes[i].innerClassAccessFlags;
    }
}

void printAttributeSynthetic(ClassFile const& cf, AttributeInfoSynthetic *attribute){

}

void printAttributeSourceFile(ClassFile const& cf, AttributeInfoSourceFile *attribute){
    std::cout << ": #" << attribute->sourcefileIndex << " <" << getCPUtf8(cf.constantPool, attribute->sourcefileIndex) << ">\n";
}

void printAttributeLineNumberTable(ClassFile const& cf, AttributeInfoLineNumberTable *attribute){
    std::cout << attribute->lineNumberTableLength << "\n";
    std::cout << "num: Start PC; Line Number\n";
    for(int32_t i = 0; i < attribute->lineNumberTableLength; i++){
        std::cout << i << ": " << attribute->lineNumberTable[i].startPc << "; " << attribute->lineNumberTable[i].lineNumber <<  "\n";
    }
}

void printAttributeLocalVariableTable(ClassFile const& cf, AttributeInfoLocalVariableTable *attribute){
    std::cout << attribute->localVariableTableLength << "\n";
    std::cout << "num: Start PC; Lenght; Name Index; Descriptor Index; Index\n";
    for(int32_t i = 0; i < attribute->localVariableTableLength; i++){
        std::cout << i << ": " << attribute->localVariableTable[i].startPc << "; " << attribute->localVariableTable[i].length << " ;" << attribute->localVariableTable[i].nameIndex << " <" << getCPUtf8(cf.constantPool, attribute->localVariableTable[i].nameIndex) << " ;" << attribute->localVariableTable[i].descriptorIndex << " <" << getCPUtf8(cf.constantPool, attribute->localVariableTable[i].descriptorIndex) << "; " << attribute->localVariableTable[i].index << "\n";
    }

}

void printAttributeDeprecated(ClassFile const& cf, AttributeInfoDeprecated *attribute){

}
