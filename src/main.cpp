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
#include "../include/PrintTudo.h"
#include "../include/PrintMenu.h"

// bool isSameClass(std::string s1, std::string s2){
//     std::reverse(s1.begin(), s1.end());
//     std::reverse(s2.begin(), s2.end());
//     uint32_t minSize = std::min(s2.size(), s1.size());
//     return s1.substr(0, minSize) == s2.substr(0, minSize);
// }

int main(int argc, char *argv[]){
    // CassLoader classLoader(argv[0]);
    // RuntimeDataArea runtimeDataArea;
    // ExecutionEngine executionEngine;

    
    // classLoader.setRuntimeDataArea(&runtimeDataArea);
    // classLoader.setExecutionEngine(&executionEngine);
    // executionEngine.setRuntimeDataArea(&runtimeDataArea);
    // executionEngine.setClassLoader(&classLoader);
    
    // std::string className = "Class04";

    // classLoader.addClassToLoad(className);
    // classLoader.exec();
    // classLoader.saveObejectInfo();

    // MethodInfo* method = classLoader.getMethod(className, "main:([Ljava/lang/String;)V");
    // executionEngine.exec(method, Frame::CreateFrame(method));
    
    
    std::ifstream is;
    std::string fileName;
    const std::map<std::string, int32_t> ourSet{
        {"-p", 1},
        {"-b", 2},
        {"-e", 4},
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
    if(flag == 1 || flag == 2){
        FileSystem fs(argv[0]);

        ClassFile* cf = ClassLoader::readClass2(fs, fileName);
        
        if(flag == 1){
            printTudo(*cf);
        } else if(flag == 2){
            printMenu(*cf);
        }
        delete cf;
    } else if(flag == 4){

        ClassLoader classLoader(argv[0]);
        RuntimeDataArea runtimeDataArea;
        ExecutionEngine executionEngine;

        
        classLoader.setRuntimeDataArea(&runtimeDataArea);
        classLoader.setExecutionEngine(&executionEngine);
        executionEngine.setRuntimeDataArea(&runtimeDataArea);
        executionEngine.setClassLoader(&classLoader);
        
        classLoader.addClassToLoad(fileName);
        classLoader.exec();
        classLoader.saveObejectInfo();

        fileName = classLoader.getClassName();

        MethodInfo* method = classLoader.getMethod(fileName, "main:([Ljava/lang/String;)V");
        executionEngine.exec(method, Frame::CreateFrame(method));
    } else{
        std::cerr << "Ponha ou \"-p\"(para printar tudo), ou \"-b\"(para printar cmo menus), ou \"-e\"(para executar o programa)\n";
    }
    
    return 0;
}

