#include "../include/FileSystem.h"


FileSystem::FileSystem(std::string &s){
    if(s.find('\\') != std::string::npos){
        bar = '\\';
    } else{
        bar = '/';
    }
    while(s.back() != '\\' && s.back() != '/'){
        s.pop_back();
    }
    javaClassPath = s + ".." + bar + "data" + bar + "JavaLib" + bar;
    userClassPath = "";
    count = 0;
}
FileSystem::FileSystem(std::string &&s){
    if(s.find('\\') != std::string::npos){
        bar = '\\';
    } else{
        bar = '/';
    }
    while(s.back() != '\\' && s.back() != '/'){
        s.pop_back();
    }
    javaClassPath = s + ".." + bar + "data" + bar + "JavaLib" + bar;
    userClassPath = "";
    count = 0;
}
const std::string& FileSystem::getJavaClassPath(){
    return javaClassPath;
}
const std::string& FileSystem::getUserClassPath(){
    return userClassPath;
}
void FileSystem::setUserClassPath(std::string& s){
    if(count == 0){
        userClassPath = environmentToJavaPathNotation(s);
        count = 1;
    }
}
std::string FileSystem::javaToEnvironmentPathNotation(std::string s){
    char myBar = bar;
    std::transform(s.begin(), s.end(), s.begin(), [myBar](char c){
        if(c == '\\' || c == '/'){
            return myBar;
        }
        return c;
    });
    return s;
}
std::string FileSystem::environmentToJavaPathNotation(std::string s){
    std::transform(s.begin(), s.end(), s.begin(), [](char c){
        if(c == '\\' || c == '/'){
            return '/';
        }
        return c;
    });
    return s;
}