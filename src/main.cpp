#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>

#include "../include/ClassFile.h"
#include "../include/Tipos.h"
#include "../include/ISA.h"
#include "../include/PrintMenu.h"
#include "../include/PrintTudo.h"


int main(int argc, char *argv[]){
    
    std::ifstream is;
    std::string s;
    if(argc == 1){
        std::cin >> s;
    } else{
        s = argv[1];
    }
    is.open(s, std::ios::binary);
    is.exceptions(std::ifstream::eofbit);
    ClassFile cf;
    try{
        read<ClassFile>(is, &cf);
        // try{
        //     is.peek();
        // } catch(std::exception &e){
        //     Terminou com sucesso
        // }
    } catch(ClassFormatError &e){
        std::cerr << e.what() << "\n";
        return -1;
    } catch(UnsupportedClassVersionError &e){
        std::cerr << e.what() << "\n";
        return -1;
    } catch(std::exception &e){
        std::cerr << e.what() << "\n";
        return -1;
    } catch( ... ){
        std::cerr << "Um erro qualquer\n";
        return -1;
    }
    conveterAttributeInfoInClassFile(cf.constantPool, &cf);
    printTudo(cf);
    return 0;
}

