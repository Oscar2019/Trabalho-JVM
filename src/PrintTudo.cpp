#include "../include/PrintTudo.h"
#include <sstream>
#include <string>
#include <map>

#ifdef _WIN32
#define CLEAR() system("CLS")
#else
#define CLEAR() system("clear")
#endif

void printTudoGeneralInformation(ClassFile const& cf);
void printTudoConstantPool(ClassFile const& cf);
void printTudoInterfaces(ClassFile const& cf);
void printTudoFields(ClassFile const& cf);
void printTudoField(ClassFile const& cf, FieldInfo *field);
void printTudoMethods(ClassFile const& cf);
void printTudoMethod(ClassFile const& cf, MethodInfo *field);
void printTudoAttributes(ClassFile const& cf);
void printTudoAttribute(ClassFile const& cf, AttributeInfo *attribute);
void printTudoAttributeConstantValue(ClassFile const& cf, AttributeInfoConstantValue *attribute);
void printTudoAttributeCode(ClassFile const& cf, AttributeInfoCode *attribute);
void printTudoAssemplyCode(ClassFile const& cf, uint32_t codeSize, uint8_t *code);
void printTudoAttributeExceptions(ClassFile const& cf, AttributeInfoExceptions *attribute);
void printTudoAttributeInnerClasses(ClassFile const& cf, AttributeInfoInnerClasses *attribute);
void printTudoAttributeSynthetic(ClassFile const& cf, AttributeInfoSynthetic *attribute);
void printTudoAttributeSourceFile(ClassFile const& cf, AttributeInfoSourceFile *attribute);
void printTudoAttributeLineNumberTable(ClassFile const& cf, AttributeInfoLineNumberTable *attribute);
void printTudoAttributeLocalVariableTable(ClassFile const& cf, AttributeInfoLocalVariableTable *attribute);
void printTudoAttributeDeprecated(ClassFile const& cf, AttributeInfoDeprecated *attribute);
std::string translateTudoFlagMethod (uint16_t flag);
std::string translateTudoFlagField (std::string flag); 
std::string convertTudoAccessFlag (std::string hex);

std::string tab;

void printTudo(ClassFile const& cf){
        std::cout << "\n================General Information================\n"; 
        printTudoGeneralInformation(cf);
        std::cout << "\n===================Constant Pool===================\n"; 
        printTudoConstantPool(cf);
        std::cout << "\n=====================Interfaces====================\n"; 
        printTudoInterfaces(cf);
        std::cout << "\n======================Fields=======================\n"; 
        printTudoFields(cf);
        std::cout << "\n======================Methods======================\n"; 
        printTudoMethods(cf);
        std::cout << "\n=====================Attributes====================\n"; 
        printTudoAttributes(cf);
}

extern const std::map<uint16_t, std::string> versions{
    {46, "1.2"},  
    {47, "1.3"},  
    {48, "1.4"},  
    {49, "1.5"},  
    {50, "1.6"},  
    {51, "1.7"},  
    {52, "1.8"}  
};


void printTudoGeneralInformation(ClassFile const& cf){
    std::stringstream aux;
    aux << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cf.accessFlags << std::dec;
    tab += "\t";
    std::cout << tab << "Minor version: " << cf.minorVersion << "\n"; 
    std::cout << tab << "Major version: " << cf.majorVersion << "\n"; 
    std::cout << tab << "Java version of class file: " << versions.at(cf.majorVersion) << "\n"; 
    std::cout << tab << "Java version of jvm: " << 1. << "." << 8 << "\n"; 
    std::cout << tab << "Constantpool Count: " << cf.constantPoolCount << "\n"; 
    std::cout << tab << "Access flags: " << "0x" + aux.str() << " [" << convertTudoAccessFlag(aux.str()) << "]\n";
    std::cout << tab << "This class: <" << getClass(cf.constantPool, cf.thisClass) << ">\n"; 
    std::cout << tab << "Super class: <" << (cf.superClass == 0 ? "null" : getClass(cf.constantPool, cf.superClass)) << ">\n"; 
    std::cout << tab << "Interface count: " << cf.interfacesCount << "\n";
    std::cout << tab << "Fields count: " << cf.fieldsCount << "\n";
    std::cout << tab << "Methods count: " << cf.methodsCount << "\n";
    std::cout << tab << "Attributes count: " << cf.attributesCount << "\n";
    tab.pop_back();
}


void printTudoConstantPool(ClassFile const& cf){
    tab += "\t";
    for(uint32_t i = 1; i < cf.constantPoolCount; i++){
        std::cout << tab << "[" << i << "] ";
        if(cf.constantPool[i] != nullptr){
            if(cf.constantPool[i]->tag == ConstantPoolInfoTag::CLASS){
                CPClass *cp = dynamic_cast<CPClass*>(cf.constantPool[i]);
                std::cout << " CONSTANT_Class\n";
                tab += "\t";
                std::cout << tab << "Class name: <" << getClass(cf.constantPool, i) << "> // #" << cp->nameIndex << "\n";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::FIELDREF){
                std::cout << " CONSTANT_Fieldref\n";
                tab += "\t";
                CPFieldref *cp = dynamic_cast<CPFieldref*>(cf.constantPool[i]);
                std::cout << tab << "Class name: <" << getClass(cf.constantPool, cp->classIndex) << "> // #" << cp->classIndex << "\n";
                std::cout << tab << "Name and type: <" << getNameAndType(cf.constantPool, cp->nameAndTypeIndex) << "> // #" << cp->nameAndTypeIndex << "\n";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::METHODREF){
                std::cout << " CONSTANT_Methodref\n";
                tab += "\t";
                CPMethodref *cp = dynamic_cast<CPMethodref*>(cf.constantPool[i]);
                std::cout << tab << "Class name: <" << getClass(cf.constantPool, cp->classIndex) << "> // #" << cp->classIndex << "\n";
                std::cout << tab << "Name and type: <" << getNameAndType(cf.constantPool, cp->nameAndTypeIndex) << "> // #" << cp->nameAndTypeIndex << "\n";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::INTERFACE_METHODREF){
                std::cout << " CONSTANT_InterfaceMethodref\n";
                CPInterfaceMethodref *cp = dynamic_cast<CPInterfaceMethodref*>(cf.constantPool[i]);
                std::cout << tab << "Class name: <" << getClass(cf.constantPool, cp->classIndex) << "> // #" << cp->classIndex << "\n";
                std::cout << tab << "Name and type: <" << getNameAndType(cf.constantPool, cp->nameAndTypeIndex) << "> // #" << cp->nameAndTypeIndex << "\n";
                tab += "\t";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::STRING){
                std::cout << " CONSTANT_String\n";
                tab += "\t";
                CPString *cp = dynamic_cast<CPString*>(cf.constantPool[i]);
                std::cout << tab << "String: <" << getCPUtf8(cf.constantPool, cp->stringIndex) << "> // #" << cp->stringIndex << "\n";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::INTEGER){
                std::cout << " CONSTANT_Integer\n";
                tab += "\t";
                CPInteger *cp = dynamic_cast<CPInteger*>(cf.constantPool[i]);
                std::cout << tab << "Bytes: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cp->bytes << std::dec << "\n";
                std::cout << tab << "Integer: " << getInteger(cf.constantPool, i) << "\n";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::FLOAT){
                std::cout << " CONSTANT_Float\n";
                tab += "\t";
                CPFloat *cp = dynamic_cast<CPFloat*>(cf.constantPool[i]);
                std::cout << tab << "Bytes: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cp->bytes << std::dec << "\n";
                std::cout << tab << "Float: " << getFloat(cf.constantPool, i) << "\n";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::LONG){
                std::cout << " CONSTANT_Long\n";
                tab += "\t";
                CPLong *cp = dynamic_cast<CPLong*>(cf.constantPool[i]);
                std::cout << tab << "High bytes: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cp->highBytes << std::dec << "\n";
                std::cout << tab << "Low bytes: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cp->lowBytes << std::dec << "\n";
                std::cout << tab << "Long: " << getLong(cf.constantPool, i) << "\n";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::DOUBLE){
                std::cout << " CONSTANT_Double\n";
                tab += "\t";
                CPDouble *cp = dynamic_cast<CPDouble*>(cf.constantPool[i]);
                std::cout << tab << "High bytes: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cp->highBytes << std::dec << "\n";
                std::cout << tab << "Low bytes: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)cp->lowBytes << std::dec << "\n";
                std::cout << tab << "Double: " << getDouble(cf.constantPool, i) << "\n";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::NAME_AND_TYPE){
                std::cout << " CONSTANT_NameAndType\n";
                tab += "\t";
                CPNameAndType *cp = dynamic_cast<CPNameAndType*>(cf.constantPool[i]);
                std::cout << tab << "Name: <" << getCPUtf8(cf.constantPool, cp->nameIndex) << "> // #" << cp->nameIndex << "\n";
                std::cout << tab << "Descriptor: <" << getCPUtf8(cf.constantPool, cp->descriptorIndex) << "> // #" << cp->descriptorIndex << "\n";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::UTF8){
                std::cout << " CONSTANT_Utf8\n";
                tab += "\t";
                CPUtf8 *cp = dynamic_cast<CPUtf8*>(cf.constantPool[i]);
                std::cout << tab << "Lenght of string: " << cp->length << "\n";
                std::cout << tab << "String: " << getCPUtf8(cf.constantPool, i) << "\n";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::METHOD_HANDLE){
                std::cout << " CONSTANT_MethodHandle\n";
                tab += "\t";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::METHOD_TYPE){
                std::cout << " CONSTANT_MethodType\n";
                tab += "\t";
                tab.pop_back();
            } else if(cf.constantPool[i]->tag == ConstantPoolInfoTag::INVOKE_DYNAMIC){
                std::cout << " CONSTANT_MethodType\n";
                tab += "\t";
                tab.pop_back();
            }
        } else{
            std::cout << tab << "null\n";
        }
    }
    tab.pop_back();
}


void printTudoInterfaces(ClassFile const& cf){
    tab += "\t";
    for(uint32_t i = 0; i < cf.interfacesCount; i++){
        std::cout << tab << "[" << i << "] #" << cf.interfaces[i] << " ";
        std::cout << getClass(cf.constantPool, cf.interfaces[i]) << "\n";
    }
    tab.pop_back();
}

void printTudoFields(ClassFile const& cf){
    tab += "\t";
    for(uint32_t i = 0; i < cf.fieldsCount; i++){
        std::cout << tab << "[" << i << "] ";
        std::cout << getCPUtf8(cf.constantPool, cf.fields[i].nameIndex) << "\n";
        printTudoField(cf, cf.fields + i);
    }
    tab.pop_back();
}

void printTudoField(ClassFile const& cf, FieldInfo *field){
    std::stringstream aux;
    aux << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)field->accessFlags << std::dec;
    tab += "\t";
    std::cout << tab << "Name: " << getCPUtf8(cf.constantPool, field->nameIndex) << "\n";    
    std::cout << tab << "Descrictor: " << getCPUtf8(cf.constantPool, field->descriptorIndex) << "\n";
    std::cout << tab << "Access flags: " << "0x" + aux.str() << " [" << translateTudoFlagField("0x" + aux.str()) << "]\n";
    for(uint32_t i = 0; i < field->attributesCount; i++){
        printTudoAttribute(cf, field->attributes[i]);
    }
    tab.pop_back();
}

void printTudoMethods(ClassFile const& cf){
    tab += "\t";
    for(uint32_t i = 0; i < cf.methodsCount; i++){
        std::cout << tab << "[" << i << "] ";
        std::cout << tab << getCPUtf8(cf.constantPool, cf.methods[i].nameIndex) << "\n";
        printTudoMethod(cf, cf.methods + i);
    }
    tab.pop_back();
}

std::string translateTudoFlagMethod (uint16_t flag) {
    switch (flag) {
    case 1:
        return "Public";
        break;
    case 2:
        return "Private";
        break;
    case 4:
        return "Protected";
        break;
    case 8:
        return "Static";
        break;
    case 9:
        return "Public Static";
        break;
    case 11:
        return "Public Final";
        break;
    case 33:
        return "Public Synchronized";
        break;
    case 65:
        return "Public Bridge";
        break;
    case 129:
        return "Public Varargs";
        break;
    case 257:
        return "Public Native";
        break;
    case 2049:
        return "Public Strict";
        break;
    case 4097:
        return "Public Synthetic";
        break;
    case 25:
        return "Public Static Final";
        break;
    case 41:
        return "Public Static Synchronized";
        break;
    case 73:
        return "Public Static Bridge";
        break;
    case 137:
        return "Public Static Varargs";
        break;
    case 265:
        return "Public Static Native";
        break;
    case 2057:
        return "Public Static Strict";
        break;
    case 4105:
        return "Public Static Synthetic";
        break;
    case 49:
        return "Public Final Synchronized";
        break;
    case 81:
        return "Public Final Bridge";
        break;
    case 145:
        return "Public Final Varargs";
        break;
    case 273:
        return "Public Final Native";
        break;
    case 2065:
        return "Public Final Strict";
        break;
    case 4113:
        return "Public Final Synthetic";
        break;
    case 57:
        return "Public Static Final Synchronized";
        break;
    case 89:
        return "Public Static Final Bridge";
        break;
    case 153:
        return "Public Static Final Varargs";
        break;
    case 281:
        return "Public Static Final Native";
        break;
    case 2073:
        return "Public Static Final Strict";
        break;
    case 4121:
        return "Public Static Final Synthetic";
        break;
    case 10:
        return "Private Static";
        break;
    case 18:
        return "Private Final";
        break;
    case 34:
        return "Private Synchronized";
        break;
    case 66:
        return "Private Bridge";
        break;
    case 130:
        return "Private Varargs";
        break;
    case 258:
        return "Private Native";
        break;
    case 2050:
        return "Private Strict";
        break;
    case 4098:
        return "Private Synthetic";
        break;
    case 26:
        return "Private Static Final";
        break;
    case 42:
        return "Private Static Synchronized";
        break;
    case 74:
        return "Private Static Bridge";
        break;
    case 138:
        return "Private Static Varargs";
        break;
    case 266:
        return "Private Static Native";
        break;
    case 2058:
        return "Private Static Strict";
        break;
    case 4106:
        return "Private Static Synthetic";
        break;
    case 50:
        return "Private Final Synchronized";
        break;
    case 82:
        return "Private Final Bridge";
        break;
    case 146:
        return "Private Final Varargs";
        break;
    case 274:
        return "Private Final Native";
        break;
    case 2066:
        return "Private Final Strict";
        break;
    case 4114:
        return "Private Final Synthetic";
        break;
    case 58:
        return "Private Static Final Synchronized";
        break;
    case 90:
        return "Private Static Final Bridge";
        break;
    case 154:
        return "Private Static Final Varargs";
        break;
    case 282:
        return "Private Static Final Native";
        break;
    case 2074:
        return "Private Static Final Strict";
        break;
    case 4122:
        return "Private Static Final Synthetic";
        break;
    case 12:
        return "Protected Static";
        break;
    case 20:
        return "Protected Final";
        break;
    case 36:
        return "Protected Synchronized";
        break;
    case 68:
        return "Protected Bridge";
        break;
    case 132:
        return "Protected Varargs";
        break;
    case 260:
        return "Protected Native";
        break;
    case 2052:
        return "Protected Strict";
        break;
    case 4100:
        return "Protected Synthetic";
        break;
    case 28:
        return "Protected Static Final";
        break;
    case 44:
        return "Protected Static Synchronized";
        break;
    case 76:
        return "Protected Static Bridge";
        break;
    case 140:
        return "Protected Static Varargs";
        break;
    case 268:
        return "Protected Static Native";
        break;
    case 2060:
        return "Protected Static Strict";
        break;
    case 4108:
        return "Protected Static Synthetic";
        break;
    case 52:
        return "Protected Final Synchronized";
        break;
    case 84:
        return "Protected Final Bridge";
        break;
    case 148:
        return "Protected Final Varargs";
        break;
    case 276:
        return "Protected Final Native";
        break;
    case 2068:
        return "Protected Final Strict";
        break;
    case 4116:
        return "Protected Final Synthetic";
        break;
    case 60:
        return "Protected Static Final Synchronized";
        break;
    case 92:
        return "Protected Static Final Bridge";
        break;
    case 156:
        return "Protected Static Final Varargs";
        break;
    case 284:
        return "Protected Static Final Native";
        break;
    case 2076:
        return "Protected Static Final Strict";
        break;
    case 4124:
        return "Protected Static Final Synthetic";
        break;
    case 1025:
        return "Public Abstract";
        break;
    case 1028:
        return "Protected Abstract";
        break;
    default:
        return "Nenhuma flag foi encontrada";
    }
}

void printTudoMethod(ClassFile const& cf, MethodInfo *method){
    std::stringstream aux;
    aux << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)method->accessFlags << std::dec;
    std::string aFlag = aux.str();
    tab += "\t";
    std::cout << tab << "Name: " << getCPUtf8(cf.constantPool, method->nameIndex) << "\n";    
    std::cout << tab << "Descrictor: " << getCPUtf8(cf.constantPool, method->descriptorIndex) << "\n";
    std::cout << tab << "Access flags: " << "0x" << std::setfill('0') << std::setw(4) << std::right << std::hex << (uint32_t)method->accessFlags << std::dec << " [" << translateTudoFlagMethod((uint32_t)method->accessFlags) << "] \n";     
    for(uint32_t i = 0; i < method->attributesCount; i++){
        printTudoAttribute(cf, method->attributes[i]);
    }
    tab.pop_back();
}

void printTudoAttribute(ClassFile const& cf, AttributeInfo *attribute){
    std::string name = getCPUtf8(cf.constantPool, attribute->attributeNameIndex);
    if(name == "ConstantValue"){
        std::cout << tab << "Attribute" << name << "\n";
        printTudoAttributeConstantValue(cf, dynamic_cast<AttributeInfoConstantValue*>(attribute));
    } else if(name == "Code"){
        std::cout << tab << "Attribute" << name << "\n";
        printTudoAttributeCode(cf, dynamic_cast<AttributeInfoCode*>(attribute));
    } else if(name == "Exceptions"){
        std::cout << tab << "Attribute" << name << "\n";
        printTudoAttributeExceptions(cf, dynamic_cast<AttributeInfoExceptions*>(attribute));
    } else if(name == "InnerClasses"){
        std::cout << tab << "Attribute" << name << "\n";
        printTudoAttributeInnerClasses(cf, dynamic_cast<AttributeInfoInnerClasses*>(attribute));
    } else if(name == "Synthetic"){
        std::cout << tab << "Attribute" << name << "\n";
        printTudoAttributeSynthetic(cf, dynamic_cast<AttributeInfoSynthetic*>(attribute));
    } else if(name == "SourceFile"){
        std::cout << tab << "Attribute" << name << "\n";
        printTudoAttributeSourceFile(cf, dynamic_cast<AttributeInfoSourceFile*>(attribute));
    } else if(name == "LineNumberTable"){
        std::cout << tab << "Attribute" << name << "\n";
        printTudoAttributeLineNumberTable(cf, dynamic_cast<AttributeInfoLineNumberTable*>(attribute));
    } else if(name == "LocalVariableTable"){
        std::cout << tab << "Attribute" << name << "\n";
        printTudoAttributeLocalVariableTable(cf, dynamic_cast<AttributeInfoLocalVariableTable*>(attribute));
    } else if(name == "Deprecated"){
        std::cout << tab << "Attribute" << name << "\n";   
        printTudoAttributeDeprecated(cf, dynamic_cast<AttributeInfoDeprecated*>(attribute)); 
    }
}

void printTudoAttributeConstantValue(ClassFile const& cf, AttributeInfoConstantValue *attribute){
    tab += "\t";
    std::cout << tab << "Name: " << getCPUtf8(cf.constantPool, attribute->attributeNameIndex) << "\n";        
    std::cout << tab << "indexValue: #" <<  attribute->constantvalueIndex << " <" << getStringFromCPInfo(cf.constantPool, attribute->constantvalueIndex) << ">\n";
    tab.pop_back();
}

void printTudoAttributeCode(ClassFile const& cf, AttributeInfoCode *attribute){
    tab += "\t";
    std::cout << tab << "Name: " << getCPUtf8(cf.constantPool, attribute->attributeNameIndex) << "\n";        
    std::cout << tab << "Max stack: " <<  attribute->maxStack << "\n";
    std::cout << tab << "Max locals: " <<  attribute->maxLocals << "\n";
    std::cout << tab << "Code: \n";
    printTudoAssemplyCode(cf, attribute->codeLength, attribute->code);
    tab += "\t";
    std::cout << tab << "Exception Table: \n";
    std::cout << tab << "\tStart PC; End PC; Handler PC; Catch type\n";
    for(uint32_t i = 0; i < attribute->exceptionTableLength; i++){
        std::cout << tab << "\t" << attribute->exceptionTable[i].startPc << ";";
        std::cout << " " << attribute->exceptionTable[i].endPc << ";";
        std::cout << " " << attribute->exceptionTable[i].handlerPc << ";";
        std::cout << " " << attribute->exceptionTable[i].catchType << "\n";
    }
    tab.pop_back();
    for(uint32_t i = 0; i < attribute->attributesCount; i++){
        printTudoAttribute(cf, attribute->attributes[i]);
    }
    tab.pop_back();
}

void printTudoAssemplyCode(ClassFile const& cf, uint32_t codeSize, uint8_t *code){
    tab += "\t";
    for(uint32_t pc = 0, line = 1; pc < codeSize; pc++, line++){
        uint32_t offset = qtdAttributes[code[pc]](code, pc, codeSize);
        std::string str = printMnemonic[code[pc]](cf.constantPool, code, pc, codeSize);
        std::stringstream sstr(str);
        std::getline(sstr, str, '\n');
        // sstr.ignore();
        std::cout << tab << line << " : " << pc << " : " << str << "\n";
        while(std::getline(sstr, str, '\n')){
            // sstr.ignore();
            std::cout << tab << str << "\n";
        }
        pc += offset;
    }
    tab.pop_back();
}


void printTudoAttributes(ClassFile const& cf){
    tab += "\t";
    for(uint32_t i = 0; i < cf.attributesCount; i++){
        printTudoAttribute(cf, cf.attributes[i]);
    }
    tab.pop_back();
}


void printTudoAttributeExceptions(ClassFile const& cf, AttributeInfoExceptions *attribute){
    tab += "\t";
    std::cout << tab << attribute->numberOfExceptions << "\n";
    std::cout << tab << "num: exceptions\n";
    for(int32_t i = 0; i < attribute->numberOfExceptions; i++){
        std::cout << tab << i << ": #" << attribute->exceptionIndexTable[i] << " <" << getClass(cf.constantPool, attribute->exceptionIndexTable[i]) << ">\n";
    }
    tab.pop_back();
}

void printTudoAttributeInnerClasses(ClassFile const& cf, AttributeInfoInnerClasses *attribute){
    tab += "\t";
    std::cout << tab << attribute->numberOfClasses << "\n";
    std::cout << tab << "num: Inner Class Info Index; Outer Class Info Index; Inner Name Index; Inner Class Access Flags\n";
    for(int32_t i = 0; i < attribute->numberOfClasses; i++){
        std::cout << tab << i << ": #" << attribute->classes[i].innerClassInfoIndex << " <" << getClass(cf.constantPool, attribute->classes[i].innerClassInfoIndex) << ">; " << attribute->classes[i].outerClassInfoIndex << " <" << getClass(cf.constantPool, attribute->classes[i].outerClassInfoIndex) << ">; " << attribute->classes[i].innerNameIndex << " <" << getCPUtf8(cf.constantPool, attribute->classes[i].innerNameIndex) << ">; " << attribute->classes[i].innerClassAccessFlags;
    }
    tab.pop_back();
}

void printTudoAttributeSynthetic(ClassFile const& cf, AttributeInfoSynthetic *attribute){

}

void printTudoAttributeSourceFile(ClassFile const& cf, AttributeInfoSourceFile *attribute){
    tab += "\t";
    std::cout << tab << "Source file: #" << attribute->sourcefileIndex << " <" << getCPUtf8(cf.constantPool, attribute->sourcefileIndex) << ">\n";
    tab.pop_back();
}

void printTudoAttributeLineNumberTable(ClassFile const& cf, AttributeInfoLineNumberTable *attribute){
    tab += "\t";
    std::cout << tab << attribute->lineNumberTableLength << "\n";
    std::cout << tab << "num: Start PC; Line Number\n";
    for(int32_t i = 0; i < attribute->lineNumberTableLength; i++){
        std::cout << tab << i << ": " << attribute->lineNumberTable[i].startPc << "; " << attribute->lineNumberTable[i].lineNumber <<  "\n";
    }
    tab.pop_back();
}

void printTudoAttributeLocalVariableTable(ClassFile const& cf, AttributeInfoLocalVariableTable *attribute){
    tab += "\t";
    std::cout << tab << attribute->localVariableTableLength << "\n";
    std::cout << tab << "num: Start PC; Lenght; Name Index; Descriptor Index; Index\n";
    for(int32_t i = 0; i < attribute->localVariableTableLength; i++){
        std::cout << tab << i << ": " << attribute->localVariableTable[i].startPc << "; " << attribute->localVariableTable[i].length << " ;" << attribute->localVariableTable[i].nameIndex << " <" << getCPUtf8(cf.constantPool, attribute->localVariableTable[i].nameIndex) << " ;" << attribute->localVariableTable[i].descriptorIndex << " <" << getCPUtf8(cf.constantPool, attribute->localVariableTable[i].descriptorIndex) << "; " << attribute->localVariableTable[i].index << "\n";
    }
    tab.pop_back();

}

void printTudoAttributeDeprecated(ClassFile const& cf, AttributeInfoDeprecated *attribute){

}


std::string translateTudoFlagField (std::string flag) {
         if (flag == "0x0001") return "Public";
    else if (flag == "0x0009") return "Public Static";
    else if (flag == "0x0011") return "Public Final";
    else if (flag == "0x0041") return "Public Volatile";
    else if (flag == "0x0081") return "Public Transient";
    else if (flag == "0x1001") return "Public Synthetic";
    else if (flag == "0x4001") return "Public Enum";
    else if (flag == "0x0019") return "Public Static Final";
    else if (flag == "0x0049") return "Public Static Volatile";
    else if (flag == "0x0089") return "Public Static Transient";
    else if (flag == "0x1009") return "Public Static Synthetic";
    else if (flag == "0x4009") return "Public Static Enum";
    else if (flag == "0x0099") return "Public Static Final Transient";
    else if (flag == "0x1019") return "Public Static Final Synthetic";
    else if (flag == "0x4019") return "Public Static Final Enum";
    else if (flag == "0x0002") return "Private";
    else if (flag == "0x000A") return "Private Static";
    else if (flag == "0x0012") return "Private Final";
    else if (flag == "0x0042") return "Private Volatile";
    else if (flag == "0x0082") return "Private Transient";
    else if (flag == "0x1002") return "Private Synthetic";
    else if (flag == "0x4002") return "Private Enum";
    else if (flag == "0x001A") return "Private Static Final";
    else if (flag == "0x004A") return "Private Static Volatile";
    else if (flag == "0x008A") return "Private Static Transient";
    else if (flag == "0x100A") return "Private Static Synthetic";
    else if (flag == "0x400A") return "Private Static Enum";
    else if (flag == "0x009A") return "Private Static Final Transient";
    else if (flag == "0x101A") return "Private Static Final Synthetic";
    else if (flag == "0x401A") return "Private Static Final Enum";
    else if (flag == "0x0004") return "Protected";
    else if (flag == "0x000C") return "Protected Static";
    else if (flag == "0x0014") return "Protected Final";
    else if (flag == "0x0044") return "Protected Volatile";
    else if (flag == "0x0084") return "Protected Transient";
    else if (flag == "0x1004") return "Protected Synthetic";
    else if (flag == "0x4004") return "Protected Enum";
    else if (flag == "0x001C") return "Protected Static Final";
    else if (flag == "0x004C") return "Protected Static Volatile";
    else if (flag == "0x008C") return "Protected Static Transient";
    else if (flag == "0x100C") return "Protected Static Synthetic";
    else if (flag == "0x400C") return "Protected Static Enum";
    else if (flag == "0x009C") return "Protected Static Final Transient";
    else if (flag == "0x101C") return "Protected Static Final Synthetic";
    else if (flag == "0x401C") return "Protected Static Final Enum";
    else return "Nenhuma flag foi encontrada";
}


std::string convertTudoAccessFlag (std::string hex){
    std::stringstream ret;
    if(hex[3] == '1'){
        ret << "PUBLIC ";
    }
    if(hex[2] == '1'){
        ret << "FINAL ";
    }else if(hex[2] == '2'){
        ret << "SUPER ";
    }else if(hex[2] == '3'){
        ret << "FINAL SUPER ";
    }
    
    if(hex[1] == '2'){
        ret << "INTERFACE ";
    }else if(hex[1] == '4'){
        ret << "ABSTRACT ";
    }else if(hex[1] == '6'){
        ret << "INTERFACE ABSTRACT ";
    }

    if(hex[0] == '1'){
        ret << "SYNTHETIC ";
    }else if(hex[0] == '2'){
        ret << "ANNOTATION ";
    }else if(hex[0] == '4'){
        ret << "ENUM ";
    }else if(hex[0] == '3'){
        ret << "SYNTHETIC ANNOTATION ";
    }else if(hex[0] == '5'){
        ret << "SYNTHETIC ENUM ";
    }else if(hex[0] == '6'){
        ret << "ANNOTATION ENUM ";
    }else if(hex[0] == '6'){
        ret << "SYNTHETIC ANNOTATION ENUM ";
    }

    return ret.str();
}