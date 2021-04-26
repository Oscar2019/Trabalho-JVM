#ifndef __DELETER_H__
#define __DELETER_H__

#include <vector>

/**
 * @brief destrutor base para gerar polimorfismo
 * 
 */
class DestructBase{
    public:
        virtual ~DestructBase(){
            
        };
};
/**
 * @brief Destrutor para uma alocação simples
 * 
 * @tparam T 
 */
template<typename T>
class DestructSimple : virtual public DestructBase{
    private:
        /**
         * @brief pointeiro que será destruído
         * 
         */
        T* pointer;
    public:
        /**
         * @brief Construct a new Destruct Simple object
         * 
         * @param new_pointer 
         */
        DestructSimple(T* new_pointer){
            pointer = new_pointer;
        }
        /**
         * @brief Destroy the Destruct Simple object
         * 
         */
        ~DestructSimple(){
            delete pointer;
        }
};

/**
 * @brief Destrutor para uma alocação de array
 * 
 * @tparam T 
 */
template<typename T>
class DestructArray : virtual public DestructBase{
    private:
        /**
         * @brief pointeiro que será destruído
         * 
         */
        T* pointer;
    public:
        /**
         * @brief Construct a new Destruct Array object
         * 
         * @param new_pointer 
         */
        DestructArray(T* new_pointer){
            pointer = new_pointer;
        }
        /**
         * @brief Destroy the Destruct Array object
         * 
         */
        ~DestructArray(){
            delete[] pointer;
        }
};

#endif