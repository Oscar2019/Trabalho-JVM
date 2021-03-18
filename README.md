# Trabalho-JVM

Compile com: g++ -g -Wall -std=c++11 src/main.cpp src/Tipos.cpp src/ConstantPoolInfo.cpp src/ISA.cpp src/AttributeInfo.cpp src/ClassFile.cpp src/FieldInfo.cpp src/MethodInfo.cpp -o bin/a.out

Compile com: g++ -g -Wall -std=c++11 src/* -o bin/a.out

Execute com: ./bin/a.out


cppcheck --enable=all --suppress=missingIncludeSystem src/