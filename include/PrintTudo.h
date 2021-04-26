#ifndef __PRINT_TUDO_H__
#define __PRINT_TUDO_H__

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <map>

#include "../include/ClassFile.h"
#include "../include/Tipos.h"
#include "../include/ISA.h"

void printTudo(ClassFile const& cf);

extern const std::map<uint16_t, std::string> versions;

#endif