# Trabalho-JVM

Compilar no Windows: g++ -g -Wall -std=c++11 src/* -o bin/a.exe

Compilar no Linux: g++ -g -Wall -std=c++11 src/* -o bin/a.out

----------------------------------------------------------------------------

Executar no Windows e printar sem menus: ./bin/a.exe -p <caminho para o .class sem colocar a extensão>
Executar no Windows e printar com menus: ./bin/a.exe -b <caminho para o .class sem colocar a extensão>

Executar no Linux e printar sem menus: ./bin/a.out -p <caminho para o .class sem colocar a extensão>
Executar no Linux e printar com menus: ./bin/a.out -b <caminho para o .class sem colocar a extensão>

----------------------------------------------------------------------------

Usar o cppcheck: cppcheck --enable=all --suppress=missingIncludeSystem src/

----------------------------------------------------------------------------