#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>

// #include "../include/FileSystem.h"
// #include "../include/ClassFile.h"
// #include "../include/Tipos.h"
// #include "../include/ISA.h"
// #include "../include/PrintMenu.h"
// #include "../include/PrintTudo.h"
#include "../include/ClassLoader.h"
#include "../include/RuntimeDataArea.h"
// #include "../include/ConstantPoolInfo.h"
#include "../include/ExecutionEngine.h"

// bool isSameClass(std::string s1, std::string s2){
//     std::reverse(s1.begin(), s1.end());
//     std::reverse(s2.begin(), s2.end());
//     uint32_t minSize = std::min(s2.size(), s1.size());
//     return s1.substr(0, minSize) == s2.substr(0, minSize);
// }

int main(int argc, char *argv[]){
    CassLoader classLoader(argv[0]);
    RuntimeDataArea runtimeDataArea;
    ExecutionEngine executionEngine;

    
    classLoader.setRuntimeDataArea(&runtimeDataArea);
    classLoader.setExecutionEngine(&executionEngine);
    executionEngine.setRuntimeDataArea(&runtimeDataArea);
    executionEngine.setClassLoader(&classLoader);
    
    std::string className = "SimplesChar";

    classLoader.addClassToLoad(className);
    classLoader.exec();

    executionEngine.exec(classLoader.getMethod(className, "main:([Ljava/lang/String;)V"));
    
    // FileSystem fs(argv[0]);
    // CassLoader classLoader(argv[0]);
    // std::cerr << fs.getJavaClassPath() + fs.javaToEnvironmentPathNotation("java\\lang\\Object.class") << "\n";
    // classLoader.readClass(fs.getJavaClassPath() + fs.javaToEnvironmentPathNotation("java\\lang\\Object.class"));
    // classLoader.prepare(fs.getJavaClassPath() + fs.javaToEnvironmentPathNotation("java\\lang\\Object.class"));
    
    // std::ifstream is;
    // std::string fileName;
    // const std::map<std::string, int32_t> ourSet{
    //     {"-p", 1},
    //     {"-b", 2},
    // };
    // int32_t flag = 0;
    // if(argc == 1){
    //     std::string s;
    //     while(std::cin >> s){
    //         if(ourSet.find(s) != ourSet.end()){
    //             flag |= ourSet.at(s);
    //         } else{
    //             fileName = s;
    //         }
    //     }
    // } else{
    //     for(int32_t i = 1; i < argc; i++){
    //         if(ourSet.find(argv[i]) != ourSet.end()){
    //             flag |= ourSet.at(argv[i]);
    //         } else{
    //             fileName = argv[i];
    //         }
    //     }
    // }
    
    // is.open(fileName + ".class", std::ios::binary);
    // if(!is.is_open()){
    //     std::cerr << "Arquivo \"" + fileName + ".class\" nao foi encontrado\n"; 
    //     return -1;
    // }
    // is.exceptions(std::ifstream::eofbit);
    // ClassFile cf;
    // try{
    //     read<ClassFile>(is, &cf);
    //     // try{
    //     //     is.peek();
    //     // } catch(std::exception &e){
    //     //     Terminou com sucesso
    //     // }
    // } catch(ClassFormatError &e){
    //     std::cerr << e.what() << "\n";
    //     return -1;
    // } catch(UnsupportedClassVersionError &e){
    //     std::cerr << e.what() << "\n";
    //     return -1;
    // } catch(std::exception &e){
    //     std::cerr << e.what() << "\n";
    //     return -1;
    // } catch( ... ){
    //     std::cerr << "Um erro qualquer\n";
    //     return -1;
    // }
    // if(!isSameClass(getStringFromCPInfo(cf.constantPool, cf.thisClass), fileName)){
    //     std::cerr << "Nome do arquivo diferente do nome da classe\n";
    //     return -1;
    // }
    // conveterAttributeInfoInClassFile(cf.constantPool, &cf);
    // if(flag == 1){
    //     printTudo(cf);
    // } else if(flag == 2){
    //     printMenu(cf);
    // } else{
    //     std::cerr << "Ponha ou \"-p\"(para printar tudo), ou \"-b\"(para printar cmo menus)\n";
    // }
    
    return 0;
}

