# Trabalho-JVM

Compilar no Windows: g++ -g -Wall -std=c++11 src/* -o bin/a.exe

Compilar no Linux: g++ -g -Wall -std=c++11 src/* -o bin/a.out

----------------------------------------------------------------------------

Executar no Windows: ./bin/a.exe <caminho para o .class>

Executar no Linux: ./bin/a.out <caminho para o .class>

----------------------------------------------------------------------------

Usar o cppcheck: cppcheck --enable=all --suppress=missingIncludeSystem src/

----------------------------------------------------------------------------