#ifndef __POINTER_H__
#define __POINTER_H__

#include <vector>
#include <utility>
#include <cstdint>
#include <map>
#include <stdexcept>
#include "../include/ClassFile.h"
#include "../include/MethodInfo.h"


struct Pointer{
    uint8_t *data;
    ClassFile *classFile;
    uint32_t metSize;
    MethodInfo **methods;
    Pointer(){
        data = nullptr;
        classFile = nullptr;
        metSize = 0;
        methods = nullptr;
    }
};

#endif