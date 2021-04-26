#ifndef __TIPOS_H__
#define __TIPOS_H__

#include <cstdint>
#include <fstream>
#include <ostream>
#include "../include/ClassFile.h"
#include "../include/ConstantPoolInfo.h"
#include "../include/FieldInfo.h"
#include "../include/MethodInfo.h"
#include "../include/AttributeInfo.h"

/**
 * @brief Função para leitura de um vetor de uint8_t
 * 
 * @tparam U 
 * @param in 
 * @return U 
 */
template<typename U>
U read(const uint8_t *in){
    return {};
}

/**
 * @brief Função que lê uma um uint8_t de um vetor de uint8_t
 * 
 * @tparam  
 * @param in 
 * @return uint8_t 
 */
template<>
uint8_t read<uint8_t>(const uint8_t *in);

/**
 * @brief Função que lê um uinnt16_t de um vetor de uint8_t
 * 
 * @tparam  
 * @param in 
 * @return uint16_t 
 */
template<>
uint16_t read<uint16_t>(const uint8_t *in);

/**
 * @brief Função que lê um uinnt32_t de um vetor de uint8_t
 * 
 * @tparam  
 * @param in 
 * @return uint32_t 
 */
template<>
uint32_t read<uint32_t>(const uint8_t *in);

/**
 * @brief Função para leitura de arquivo.
 * 
 * @tparam U 
 * @param ifs 
 * @param u 
 */
template<typename U>
void read(std::ifstream &ifs, U* u){
    return;
}

/**
 * @brief Função para printagens
 * 
 * @tparam U 
 * @param u 
 * @param os 
 */
template<typename U>
void print(U& u, std::ostream &os){
    return;
}

/**
 * @brief Função para leitura de um uint8_t informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<uint8_t>(std::ifstream &ifs, uint8_t *u);

/**
 * @brief Função para leitura de um uint16_t informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<uint16_t>(std::ifstream &ifs, uint16_t *u);

/**
 * @brief Função para leitura de um uint32_t informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<uint32_t>(std::ifstream &ifs, uint32_t *u);

/**
 * @brief Função que printa o uint8_t informando um classFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<uint8_t>(uint8_t& u, std::ostream &os);

/**
 * @brief Função que printa o uint16_t informando um classFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<uint16_t>(uint16_t& u, std::ostream &os);

/**
 * @brief Função que printa o uint32_t informando um classFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<uint32_t>(uint32_t& u, std::ostream &os);

/**
 * @brief Função para leitura de um ClassFile informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<ClassFile>(std::ifstream &ifs, ClassFile *u);

/**
 * @brief Função que printa o ClassFile informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<ClassFile>(ClassFile& u, std::ostream &os);


/**
 * @brief Função para leitura de um ConstantPoolInfo* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<ConstantPoolInfo*>(std::ifstream &ifs, ConstantPoolInfo** u);

/**
 * @brief Função para leitura de um CPClass* informando um ifstream.
 * 
 * @tparam  
 * @param ifs  
 * @param u 
 */
template<>
void read<CPClass>(std::ifstream &ifs, CPClass *u);

/**
 * @brief Função para leitura de um CPFieldref* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPFieldref>(std::ifstream &ifs, CPFieldref *u);

/**
 * @brief Função para leitura de um CPMethodref* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPMethodref>(std::ifstream &ifs, CPMethodref *u);

/**
 * @brief Função para leitura de um CPInterfaceMethodref* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPInterfaceMethodref>(std::ifstream &ifs, CPInterfaceMethodref *u);

/**
 * @brief Função para leitura de um CPString* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPString>(std::ifstream &ifs, CPString *u);

/**
 * @brief Função para leitura de um CPInteger* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPInteger>(std::ifstream &ifs, CPInteger *u);

/**
 * @brief Função para leitura de um CPFloat* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPFloat>(std::ifstream &ifs, CPFloat *u);

/**
 * @brief Função para leitura de um CPLong* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPLong>(std::ifstream &ifs, CPLong *u);

/**
 * @brief Função para leitura de um CPDouble* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPDouble>(std::ifstream &ifs, CPDouble *u);

/**
 * @brief Função para leitura de um CPNameAndType* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPNameAndType>(std::ifstream &ifs, CPNameAndType *u);

/**
 * @brief Função para leitura de um CPUtf8* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPUtf8>(std::ifstream &ifs, CPUtf8 *u);

/**
 * @brief Função para leitura de um CPMethodHandle* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPMethodHandle>(std::ifstream &ifs, CPMethodHandle *u);

/**
 * @brief Função para leitura de um CPMethodType* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPMethodType>(std::ifstream &ifs, CPMethodType *u);

/**
 * @brief Função para leitura de um CPInvokeDynamic* informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<CPInvokeDynamic>(std::ifstream &ifs, CPInvokeDynamic *u);

/**
 * @brief Função que printa o ConstantPoolInfo informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<ConstantPoolInfo>(ConstantPoolInfo& u, std::ostream &os);
/**
 * @brief Função que printa o CPClass informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPClass>(CPClass& u, std::ostream &os);
/**
 * @brief Função que printa o CPFieldref informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPFieldref>(CPFieldref& u, std::ostream &os);
/**
 * @brief Função que printa o CPMethodref informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPMethodref>(CPMethodref& u, std::ostream &os);
/**
 * @brief Função que printa o CPInterfaceMethodref informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPInterfaceMethodref>(CPInterfaceMethodref& u, std::ostream &os);
/**
 * @brief Função que printa o CPString informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPString>(CPString& u, std::ostream &os);
/**
 * @brief Função que printa o CPInteger informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPInteger>(CPInteger& u, std::ostream &os);
/**
 * @brief Função que printa o CPFloat informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPFloat>(CPFloat& u, std::ostream &os);
/**
 * @brief Função que printa o CPLong informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPLong>(CPLong& u, std::ostream &os);
/**
 * @brief Função que printa o CPDouble informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPDouble>(CPDouble& u, std::ostream &os);
/**
 * @brief Função que printa o CPNameAndType informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPNameAndType>(CPNameAndType& u, std::ostream &os);
/**
 * @brief Função que printa o CPUtf8 informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPUtf8>(CPUtf8& u, std::ostream &os);
/**
 * @brief Função que printa o CPMethodHandle informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os
 */
template<>
void print<CPMethodHandle>(CPMethodHandle& u, std::ostream &os);
/**
 * @brief Função que printa o CPMethodType informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPMethodType>(CPMethodType& u, std::ostream &os);
/**
 * @brief Função que printa o CPInvokeDynamic informando um ClassFile e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<CPInvokeDynamic>(CPInvokeDynamic& u, std::ostream &os);


/**
 * @brief Função para leitura de um FieldInfo informando um ifstream.
 * 
 * @tparam  
 * @param ifs  
 * @param u 
 */
template<>
void read<FieldInfo>(std::ifstream &ifs, FieldInfo *u);

/**
 * @brief Função que printa o FieldInfo informando um FieldInfo e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<FieldInfo>(FieldInfo& u, std::ostream &os);


/**
 * @brief Função para leitura de um MethodInfo informando um ifstream.
 * 
 * @tparam  
 * @param ifs  
 * @param u 
 */
template<>
void read<MethodInfo>(std::ifstream &ifs, MethodInfo *u);

/**
 * @brief Função que printa o MethodInfo informando um MethodInfo e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os
 */
template<>
void print<MethodInfo>(MethodInfo& u, std::ostream &os);

/**
 * @brief Função para leitura de um AttributeInfo informando um ifstream.
 * 
 * @tparam  
 * @param ifs 
 * @param u 
 */
template<>
void read<AttributeInfoBasic*>(std::ifstream &ifs, AttributeInfoBasic** u);

/**
 * @brief Função que printa o AttributeInfo informando um AttributeInfo e um ostream.
 * 
 * @tparam  
 * @param u 
 * @param os 
 */
template<>
void print<AttributeInfoBasic>(AttributeInfoBasic& u, std::ostream &os);


#endif