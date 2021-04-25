#ifndef __FILE_SYSTEM_H__
#define __FILE_SYSTEM_H__

#include <string>
#include <algorithm>

class FileSystem{
    private:
        char bar;
        std::string javaClassPath;
        std::string userClassPath;
        uint32_t count;
    public:
        FileSystem(std::string &s){
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
        FileSystem(std::string &&s){
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
        const std::string& getJavaClassPath(){
            return javaClassPath;
        }
        const std::string& getUserClassPath(){
            return userClassPath;
        }
        void setUserClassPath(std::string& s){
            if(count == 0){
                userClassPath = environmentToJavaPathNotation(s);
                count = 1;
            }
        }
        std::string javaToEnvironmentPathNotation(std::string s){
            char myBar = bar;
            std::transform(s.begin(), s.end(), s.begin(), [myBar](char c){
                if(c == '\\' || c == '/'){
                    return myBar;
                }
                return c;
            });
            return s;
        }
        std::string environmentToJavaPathNotation(std::string s){
            std::transform(s.begin(), s.end(), s.begin(), [](char c){
                if(c == '\\' || c == '/'){
                    return '/';
                }
                return c;
            });
            return s;
        }
};

#endif