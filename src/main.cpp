#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<sstream>
#include<string>
#include<map>

#include "../include/ClassFile.h"
#include "../include/Tipos.h"
#include "../include/ISA.h"
#include "../include/PrintMenu.h"
#include "../include/PrintTudo.h"


int main(int argc, char *argv[]){
    
    std::ifstream is;
    std::string fileName;
    const std::map<std::string, int32_t> ourSet{
        {"-p", 1},
        {"-b", 2},
    };
    int32_t flag = 0;
    if(argc == 1){
        std::string s;
        while(std::cin >> s){
            if(ourSet.find(s) != ourSet.end()){
                flag |= ourSet.at(s);
            } else{
                fileName = s;
            }
        }
    } else{
        for(int32_t i = 1; i < argc; i++){
            if(ourSet.find(argv[i]) != ourSet.end()){
                flag |= ourSet.at(argv[i]);
            } else{
                fileName = argv[i];
            }
        }
    }
    is.open(fileName, std::ios::binary);
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
    if(flag == 1){
        printTudo(cf);
    } else if(flag == 2){
        printMenu(cf);
    } else{
        std::cerr << "Ponha ou \"-p\"(para printar tudo), ou \"-b\"(para printar cmo menus)\n";
    }
    return 0;
}

