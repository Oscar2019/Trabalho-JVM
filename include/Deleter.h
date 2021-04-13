#ifndef __DELETER_H__
#define __DELETER_H__

#include <vector>

class DestructBase{
    public:
        virtual ~DestructBase(){
            
        };
};

template<typename T>
class DestructSimple : virtual public DestructBase{
    private:
        T* pointer;
    public:
        DestructSimple(T* new_pointer){
            pointer = new_pointer;
        }
        ~DestructSimple(){
            delete pointer;
        }
};

template<typename T>
class DestructArray : virtual public DestructBase{
    private:
        T* pointer;
    public:
        DestructArray(T* new_pointer){
            pointer = new_pointer;
        }
        ~DestructArray(){
            delete[] pointer;
        }
};

#endif