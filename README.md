# Trabalho-JVM

Compilar no Windows: g++ -g -Wall -std=c++11 src/* -o bin/a.exe

Compilar no Linux: g++ -g -Wall -std=c++11 src/* -o bin/a.out

----------------------------------------------------------------------------

Executar no Windows: ./bin/a.exe

Executar no Linux: ./bin/a.out

----------------------------------------------------------------------------

Usar o cppcheck: cppcheck --enable=all --suppress=missingIncludeSystem src/

----------------------------------------------------------------------------

Falta:

- Tradução das Flags na General Information
- Tradução das Flags nos Fields
- Tradução das Flags nos Methods
- Não printa instrução wide
