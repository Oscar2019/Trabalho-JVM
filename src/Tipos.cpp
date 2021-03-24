#include "../include/Tipos.h"
#include <iomanip>


template<>
uint8_t read<uint8_t>(const uint8_t *in){
    uint8_t res = 0;
    res = *in; // Lê um natural de 8 bits
    return res;
}

template<>
uint16_t read<uint16_t>(const uint8_t *in){
    uint16_t res = 0;
    res = (res << 8) | static_cast<uint16_t>(read<uint8_t>(in + 0)); // Lê os primeiros 8 bits de um natural de 16 bits
    res = (res << 8) | static_cast<uint16_t>(read<uint8_t>(in + 1)); // Lê os segundos 8 bits de um natural de 16 bits
    return res;
}

template<>
uint32_t read<uint32_t>(const uint8_t *in){
    uint32_t res = 0;
    res = (res << 8) | static_cast<uint32_t>(read<uint8_t>(in + 0)); // Lê os primeiros 8 bits de um natural de 32 bits
    res = (res << 8) | static_cast<uint32_t>(read<uint8_t>(in + 1)); // Lê os segundos 8 bits de um natural de 32 bits
    res = (res << 8) | static_cast<uint32_t>(read<uint8_t>(in + 2)); // Lê os terceiros 8 bits de um natural de 32 bits
    res = (res << 8) | static_cast<uint32_t>(read<uint8_t>(in + 3)); // Lê os quartos 8 bits de um natural de 32 bits
    return res;
}

template<>
void read<uint8_t>(std::ifstream &ifs, uint8_t *u){
    *u = ifs.get(); // Lê um natural de 8 bits
    // ifs.read((char*)u, 1); // Lê um natural de 8 bits
}

template<>
void read<uint16_t>(std::ifstream &ifs, uint16_t *u){
    uint8_t aux = 0;
    *u = 0;
    read<uint8_t>(ifs, &aux); // Lê um natural de 8 bits e o coloca em aux
    *u = (*u << 8) | static_cast<uint16_t>(aux); // Estabelece que os primeiros 8 bits de um natural de 16 bits
    read<uint8_t>(ifs, &aux); // Lê um natural de 8 bits e o coloca em aux
    *u = (*u << 8) | static_cast<uint16_t>(aux); // Estabelece que os segundos 8 bits de um natural de 16 bits
}

template<>
void read<uint32_t>(std::ifstream &ifs, uint32_t *u){
    uint8_t aux = 0;
    read<uint8_t>(ifs, &aux); // Lê um natural de 8 bits e o coloca em aux
    *u = (*u << 8) | static_cast<uint32_t>(aux);  // Estabelece que os primeiros 8 bits de um natural de 32 bits
    read<uint8_t>(ifs, &aux); // Lê um natural de 8 bits e o coloca em aux
    *u = (*u << 8) | static_cast<uint32_t>(aux);  // Estabelece que os segundos 8 bits de um natural de 32 bits
    read<uint8_t>(ifs, &aux); // Lê um natural de 8 bits e o coloca em aux
    *u = (*u << 8) | static_cast<uint32_t>(aux);  // Estabelece que os terceiros 8 bits de um natural de 32 bits
    read<uint8_t>(ifs, &aux); // Lê um natural de 8 bits e o coloca em aux
    *u = (*u << 8) | static_cast<uint32_t>(aux);  // Estabelece que os quartos 8 bits de um natural de 32 bits
}

template<>
void print<uint8_t>(uint8_t& u, std::ostream &os){
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << static_cast<uint32_t>(u) << "\n";
}

template<>
void print<uint16_t>(uint16_t& u, std::ostream &os){
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << ((static_cast<uint32_t>(u) >> 8) & 0xFF) << " ";
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << ((static_cast<uint32_t>(u) >> 0) & 0xFF) << "\n";
}

template<>
void print<uint32_t>(uint32_t& u, std::ostream &os){
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << ((static_cast<uint32_t>(u) >> 24) & 0xFF) << " ";
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << ((static_cast<uint32_t>(u) >> 16) & 0xFF) << " ";
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << ((static_cast<uint32_t>(u) >> 8) & 0xFF) << " ";
    os << std::setfill('0') << std::setw(2) << std::right << std::hex << ((static_cast<uint32_t>(u) >> 0) & 0xFF) << "\n";
}


template<>
void read<ClassFile>(std::ifstream &ifs, ClassFile *u){
    u->constantPoolCount = 0;
    u->fieldsCount = 0;
    u->attributesCount = 0;
    u->methodsCount = 0;
    u->interfacesCount = 0;

    read<uint32_t>(ifs, &u->magic); // leitura do magic
    if(u->magic != 0xCAFEBABE){
        throw ClassFormatError("O arquivo nao possui 0xCAFEBABE nos primeiros bytes");
    }
    read<uint16_t>(ifs, &u->minorVersion); // leitura do número de menor versão
    read<uint16_t>(ifs, &u->majorVersion); // leitura do número de maior versão
    if(!((46 < u->majorVersion || (46 == u->majorVersion && 0 <= u->minorVersion)) && (u->majorVersion < 52 || (u->majorVersion == 52 && u->minorVersion <= 0)))){
        throw UnsupportedClassVersionError("Versao do class file não suportada.");
    }
    read<uint16_t>(ifs, &u->constantPoolCount); // leitura do número de elementos da tabela constant pool
    if(u->constantPoolCount > 0){ // Se existir elementos a ser lidos para o constant pool
        u->constantPool = new ConstantPoolInfo*[u->constantPoolCount]; // cria um novo constant pool
        for(uint32_t i = 0; i < u->constantPoolCount; i++){ // define o valor defaul de todos os u->constantPool[i] como nullptr
            u->constantPool[i] = nullptr;
        }
        for(uint32_t i = 1; i < u->constantPoolCount; i++){
            if(u->constantPool[i-1] == nullptr || (u->constantPool[i-1]->tag != ConstantPoolInfoTag::LONG && u->constantPool[i-1]->tag != ConstantPoolInfoTag::DOUBLE)){ // Verificação para o caso de espaço quando é um double ou um long
                read<ConstantPoolInfo*>(ifs, &u->constantPool[i]); // lê um elemento con constant pool
            }
        }
    }
    read<uint16_t>(ifs, &u->accessFlags); // leitura da flags de acesso
    read<uint16_t>(ifs, &u->thisClass); // leitura do indice para constant pool que atonta para essa classe
    read<uint16_t>(ifs, &u->superClass); // leitura do indice para constant pool que atonta para a super classe
    read<uint16_t>(ifs, &u->interfacesCount); // leitura do número de interfaces na class
    if(u->interfacesCount > 0){ // se existe interfaces
        u->interfaces = new uint16_t[u->interfacesCount]; // cria um vetor de indices de interfaces
        for(uint32_t i = 0; i < u->interfacesCount; i++){
            read<uint16_t>(ifs, &u->interfaces[i]); // leitura do indice para constant pool que atonta para classe que essa classe implementa
        }
    }
    read<uint16_t>(ifs, &u->fieldsCount); // leitura do número de field na class
    if(u->fieldsCount > 0){ // se existe fields na classe
        u->fields = new FieldInfo[u->fieldsCount]; // Cria um vetor de fields
        for(uint32_t i = 0; i < u->fieldsCount; i++){
            read<FieldInfo>(ifs, &u->fields[i]); // lê um field
        }
    }
    read<uint16_t>(ifs, &u->methodsCount);  // leitura do número de métodos na class
    if(u->methodsCount > 0){ // se existe métodos na classe
        u->methods = new MethodInfo[u->methodsCount]; // Cria um vetor de métodoss
        for(uint32_t i = 0; i < u->methodsCount; i++){
            read<MethodInfo>(ifs, &u->methods[i]); // lê um métodos
        }
    }
    read<uint16_t>(ifs, &u->attributesCount); // leitura do número de atributos na class
    if(u->attributesCount > 0){ // se existe atributos na classe
        u->attributes = new AttributeInfo*[u->attributesCount]; // Cria um vetor de atributos
        for(uint32_t i = 0; i < u->attributesCount; i++){
            AttributeInfoBasic *attribAux;
            read<AttributeInfoBasic*>(ifs, &attribAux); // lê um atrributo
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
    read<uint8_t>(ifs, &tag); // lê a tag te um elemento da constant pool 
    switch (tag){
        case ConstantPoolInfoTag::CLASS: // Se for do tipo class
            *u = new CPClass; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPClass>(ifs, dynamic_cast<CPClass*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::FIELDREF: // Se for do tipo field ref
            *u = new CPFieldref; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPFieldref>(ifs, dynamic_cast<CPFieldref*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::METHODREF: // Se for do tipo method ref
            *u = new CPMethodref; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPMethodref>(ifs, dynamic_cast<CPMethodref*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::INTERFACE_METHODREF: // Se for do tipo interface method ref
            *u = new CPInterfaceMethodref; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPInterfaceMethodref>(ifs, dynamic_cast<CPInterfaceMethodref*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::STRING: // Se for do tipo string 
            *u = new CPString; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPString>(ifs, dynamic_cast<CPString*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::INTEGER: // Se for do tipo integer
            *u = new CPInteger; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPInteger>(ifs, dynamic_cast<CPInteger*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::FLOAT: // Se for do tipo float
            *u = new CPFloat; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPFloat>(ifs, dynamic_cast<CPFloat*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::LONG: // Se for do tipo long
            *u = new CPLong; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPLong>(ifs, dynamic_cast<CPLong*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::DOUBLE: // Se for do tipo double
            *u = new CPDouble; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPDouble>(ifs, dynamic_cast<CPDouble*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::NAME_AND_TYPE: // Se for do tipo name and type
            *u = new CPNameAndType; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPNameAndType>(ifs, dynamic_cast<CPNameAndType*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::UTF8: // Se for do tipo utf8
            *u = new CPUtf8; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPUtf8>(ifs, dynamic_cast<CPUtf8*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::METHOD_HANDLE: // Se for do tipo method handle
            *u = new CPMethodHandle; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPMethodHandle>(ifs, dynamic_cast<CPMethodHandle*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::METHOD_TYPE: // Se for do tipo method type
            *u = new CPMethodType; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPMethodType>(ifs, dynamic_cast<CPMethodType*>(*u)); // lê os outros atributos desse constant pool
            break;
        case ConstantPoolInfoTag::INVOKE_DYNAMIC: // Se for do tipo involke dynamic
            *u = new CPInvokeDynamic; // Cria um constant pool para esse tipo
            (*u)->tag = tag; // armazena a tag
            read<CPInvokeDynamic>(ifs, dynamic_cast<CPInvokeDynamic*>(*u)); // lê os outros atributos desse constant pool
            break;
        default:
            break;
    }
}

template<>
void read<CPClass>(std::ifstream &ifs, CPClass *u){
    read<uint16_t>(ifs, &u->nameIndex); // lê um indice para o constant pool
}

template<>
void read<CPFieldref>(std::ifstream &ifs, CPFieldref *u){
    read<uint16_t>(ifs, &u->classIndex); // lê um indice para o constant pool
    read<uint16_t>(ifs, &u->nameAndTypeIndex); // lê um indice para o constant pool
}

template<>
void read<CPMethodref>(std::ifstream &ifs, CPMethodref *u){
    read<uint16_t>(ifs, &u->classIndex); // lê um indice para o constant pool
    read<uint16_t>(ifs, &u->nameAndTypeIndex); // lê um indice para o constant pool
}

template<>
void read<CPInterfaceMethodref>(std::ifstream &ifs, CPInterfaceMethodref *u){
    read<uint16_t>(ifs, &u->classIndex); // lê um indice para o constant pool
    read<uint16_t>(ifs, &u->nameAndTypeIndex); // lê um indice para o constant pool
}

template<>
void read<CPString>(std::ifstream &ifs, CPString *u){
    read<uint16_t>(ifs, &u->stringIndex); // lê um indice para o constant pool
}

template<>
void read<CPInteger>(std::ifstream &ifs, CPInteger *u){
    read<uint32_t>(ifs, &u->bytes);  // lê um inteiro
}

template<>
void read<CPFloat>(std::ifstream &ifs, CPFloat *u){
    read<uint32_t>(ifs, &u->bytes);  // lê um float
}

template<>
void read<CPLong>(std::ifstream &ifs, CPLong *u){
    read<uint32_t>(ifs, &u->highBytes); // lê os prtimeiro 32 bits de um long
    read<uint32_t>(ifs, &u->lowBytes); // lê os ultimos 32 bits de um long
}

template<>
void read<CPDouble>(std::ifstream &ifs, CPDouble *u){
    read<uint32_t>(ifs, &u->highBytes); // lê os prtimeiro 32 bits de um double
    read<uint32_t>(ifs, &u->lowBytes); // lê os prtimeiro 32 bits de um double
}

template<>
void read<CPNameAndType>(std::ifstream &ifs, CPNameAndType *u){
    read<uint16_t>(ifs, &u->nameIndex); // lê um indice para o constant pool
    read<uint16_t>(ifs, &u->descriptorIndex); // lê um indice para o constant pool
}

template<>
void read<CPUtf8>(std::ifstream &ifs, CPUtf8 *u){
    read<uint16_t>(ifs, &u->length); // lê o tamanho da string que será lida
    if(u->length > 0){
        u->bytes = new uint8_t[u->length];
        for(uint32_t i = 0; i < u->length; i++){
            read<uint8_t>(ifs, &u->bytes[i]); // lê cada byte da string
        }
    }
}

template<>
void read<CPMethodHandle>(std::ifstream &ifs, CPMethodHandle *u){
    read<uint8_t>(ifs, &u->referenceKind);
    read<uint16_t>(ifs, &u->referenceIndex); // lê um indice para o constant pool
}

template<>
void read<CPMethodType>(std::ifstream &ifs, CPMethodType *u){
    read<uint16_t>(ifs, &u->descriptorIndex); // lê um indice para o constant pool
}

template<>
void read<CPInvokeDynamic>(std::ifstream &ifs, CPInvokeDynamic *u){
    read<uint16_t>(ifs, &u->bootstrapMethodAttrIndex); // lê um indice para o constant pool
    read<uint16_t>(ifs, &u->nameAndTypeIndex); // lê um indice para o constant pool
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
    aux.i = 0;
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
    read<uint16_t>(ifs, &u->accessFlags); // lê as flags de acesso
    read<uint16_t>(ifs, &u->nameIndex); // lê um indice da constant pool que aponta para CPUTF8
    read<uint16_t>(ifs, &u->descriptorIndex); // lê um indice da constant pool que aponta para CPUTF8
    read<uint16_t>(ifs, &u->attributesCount); // lê a quantidade de atributos
    if(u->attributesCount > 0){
        u->attributes = new AttributeInfo*[u->attributesCount];
        for(uint32_t i = 0; i < u->attributesCount; i++){
            AttributeInfoBasic *attribAux;
            read<AttributeInfoBasic*>(ifs, &attribAux); // lê cada atributo
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
    read<uint16_t>(ifs, &u->accessFlags); // lê as flags de acesso
    read<uint16_t>(ifs, &u->nameIndex); // lê um indice da constant pool que aponta para CPUTF8
    read<uint16_t>(ifs, &u->descriptorIndex); // lê um indice da constant pool que aponta para CPUTF8
    read<uint16_t>(ifs, &u->attributesCount); // lê a quantidade de atributos
    if(u->attributesCount > 0){
        u->attributes = new AttributeInfo*[u->attributesCount];
        for(uint32_t i = 0; i < u->attributesCount; i++){
            AttributeInfoBasic *attribAux;
            read<AttributeInfoBasic*>(ifs, &attribAux); // lê cada atributo
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
    read<uint16_t>(ifs, &(*u)->attributeNameIndex);  // indice para CP onde está armazenado a UTF8 que é o nome do tipo
    read<uint32_t>(ifs, &(*u)->attributeLength); // lê o tamanho do restante da informação
    if((*u)->attributeLength > 0){
        (*u)->info = new uint8_t[(*u)->attributeLength];
        for(uint32_t i = 0; i < (*u)->attributeLength; i++){
            read<uint8_t>(ifs, &(*u)->info[i]); // lê as informações restantes do atributo
        }
    }
}

template<>
void print<AttributeInfoBasic>(AttributeInfoBasic& u, std::ostream &os){
    print<uint16_t>(u.attributeNameIndex, os);
    print<uint32_t>(u.attributeLength, os);
    for(uint32_t i = 0; i < u.attributeLength; i++){
        os << std::setfill('0') << std::setw(2) << std::right << std::hex << static_cast<uint32_t>(u.info[i]);
        if(i + 1 != u.attributeLength){
            os << " ";
        } else{
            os << "\n";
        }
    }
    os << "\n";
}

