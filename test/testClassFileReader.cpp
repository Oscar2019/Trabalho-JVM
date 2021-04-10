#include<iostream>
#include<fstream>
#include<iomanip>

#include "../include/ClassFile.h"

int main(){
    std::ifstream is;
    is.open("data/JavaLib/java/lang/object.class");
    ClassFile cf;
    cf = read<ClassFile>(is);
    print<ClassFile>(cf, std::cout);
    return 0;
}