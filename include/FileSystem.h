#ifndef __FILE_SYSTEM_H__
#define __FILE_SYSTEM_H__

#include <string>
#include <algorithm>

/**
 * @brief Classe dedicada para o sistemas de arquivo do SO
 * 
 */
class FileSystem{
    private:
        /**
         * @brief Induca se é uma parra ou uma contrabarra
         * 
         */
        char bar;
        /**
         * @brief Path para a biblioteca padrão do java
         * 
         */
        std::string javaClassPath;
        /**
         * @brief Path para o usuário java
         * 
         */
        std::string userClassPath;
        uint32_t count;
    public:
        /**
         * @brief Construct a new File System object
         * 
         * @param s 
         */
        FileSystem(std::string &s);
        /**
         * @brief Construct a new File System object
         * 
         * @param s 
         */
        FileSystem(std::string &&s);
        /**
         * @brief Get the Java Class Path object
         * 
         * @return const std::string& 
         */
        const std::string& getJavaClassPath();
        /**
         * @brief Get the User Class Path object
         * 
         * @return const std::string& 
         */
        const std::string& getUserClassPath();
        /**
         * @brief Set the User Class Path object
         * 
         * @param s 
         */
        void setUserClassPath(std::string& s);
        /**
         * @brief  converte o padrão de barra para a notaçãço da máquina.
         * 
         * @param s 
         * @return std::string 
         */
        std::string javaToEnvironmentPathNotation(std::string s);
        /**
         * @brief converte o padrão de barra para a notaçãço do Java.
         * 
         * @param s 
         * @return std::string 
         */
        std::string environmentToJavaPathNotation(std::string s);
};

#endif