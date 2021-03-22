# Trabalho-JVM

Compile com: g++ -g -Wall -std=c++11 src/main.cpp src/Tipos.cpp src/ConstantPoolInfo.cpp src/ISA.cpp src/AttributeInfo.cpp src/ClassFile.cpp src/FieldInfo.cpp src/MethodInfo.cpp -o bin/a.exe

Compile com: g++ -g -Wall -std=c++11 src/* -o bin/a.exe

Execute com: ./bin/a.exe


cppcheck --enable=all --suppress=missingIncludeSystem src/

- Tradução das Flags em General Information
- Adicionar as Flags nos Fields e Methods
- Não printa instrução wide
- Ver por que o cafebabe dá erro
