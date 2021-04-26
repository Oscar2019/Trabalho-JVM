#ifndef __TRIE_H__
#define __TRIE_H__

#include <vector>
#include <utility>
#include <cstdint>
#include <map>
#include <queue>
#include <stdexcept>
#include <stack>
#include <string>

/**
 * @brief Estrutura de dados organizada em uma árvore de prefixos que armazena um valor.
 * 
 * @tparam T 
 */
template<typename T>
class Trie{
    private:
        /**
         * @brief Árvore de prefixos. 
         * 
         */
        std::vector<std::pair<uint32_t, std::map<uint8_t, uint32_t>>> tree;
        /**
         * @brief Dados que estão sendo armazenados.
         * 
         */
        std::vector<T> data;
    public:
        /**
         * @brief Obtém os dados da Trie
         * 
         * @return std::vector<T>& 
         */
        std::vector<T>& getData(){
            return data;
        }
        /**
         * @brief Obtém os dados de um prefixo
         * 
         * @param s 
         * @return T& 
         */
        T& getValue(std::string &s){
            uint32_t v = 0;
            for(auto p : s){
                auto it = tree[v].second.find(p);
                if(it != tree[v].second.end()){
                    v = it->second;
                } else{
                    throw std::invalid_argument("Chave" + s + "nao existe!");
                }
            }
            auto it = tree[v].second.find(0);
            if(it == tree[v].second.end()){
                throw std::invalid_argument("Chave" + s + "nao existe!");
            }
            return data[it->second];
        }
        /**
         * @brief Insere um elemento na Trie
         * 
         * @param s 
         * @param value 
         */
        void insert(std::string &s, T &value){
            uint32_t v = 0;
            for(auto p : s){
                auto it = tree[v].second.find(p);
                if(it != tree[v].second.end()){
                    v = it->second;
                } else{
                    tree[v].second[p] = tree.size();
                    v = tree.size();
                    tree.push_back({p, {}});
                }
            }
            auto it = tree[v].second.find(0);
            if(it != tree[v].second.end()){
                data[it->second] = value;
            } else{
                tree[v].second[0] = data.size();
                data.push_back(value);
            }
        }
        /**
         * @brief Insere um elemento na Trie
         * 
         * @param s 
         * @param value 
         */
        void insert(std::string &s, T &&value){
            uint32_t v = 0;
            for(auto p : s){
                auto it = tree[v].second.find(p);
                if(it != tree[v].second.end()){
                    v = it->second;
                } else{
                    tree[v].second[p] = tree.size();
                    v = tree.size();
                    tree.push_back({p, {}});
                }
            }
            auto it = tree[v].second.find(0);
            if(it != tree[v].second.end()){
                data[it->second] = value;
            } else{
                tree[v].second[0] = data.size();
                data.push_back(value);
            }
        }
        /**
         * @brief Determina se existe um elemento sobre um prefixo
         * 
         * @param s 
         * @return true 
         * @return false 
         */
        bool hasKey(std::string &s){
            uint32_t v = 0;
            for(auto p : s){
                auto it = tree[v].second.find(p);
                if(it != tree[v].second.end()){
                    v = it->second;
                } else{
                    return false;
                }
            }
            return tree[v].second.find(0) != tree[v].second.end();
        }
        /**
         * @brief Cópia os dados de uma outra Trie. 
         * 
         * @param other 
         */
        void copyFrom(Trie<T> &other){
            std::queue<std::pair<uint32_t, uint32_t>> myQueue;
            myQueue.emplace(0, 0); // first this, second other
            while(!myQueue.empty()){
                auto front = myQueue.front();
                myQueue.pop();
                for(auto p : other.tree[front.second].second){
                    auto it = tree[front.first].second.find(p.first);
                    if(p.first != 0){
                        if(it != tree[front.first].second.end()){
                            myQueue.emplace(it->second, p.second);
                        } else{
                            myQueue.emplace(tree.size(), p.second);
                            tree[front.first].second[p.first] = tree.size();
                            tree.push_back({p.first, {}});
                        }
                    } else{
                        if(it == tree[front.first].second.end()){
                            tree[front.first].second[0] = data.size();
                            data.push_back(other.data[p.second]);
                        }
                    }
                }
            }
        }
        /**
         * @brief Retorna o número de dados armazenados na Trie
         * 
         * @return uint32_t 
         */
        uint32_t size(){
            return data.size();
        }
        /**
         * @brief Construct da Trie
         * 
         */
        Trie() : tree(), data(){
            tree.push_back({});
            // currSize = 0;
        }
};

#endif