#ifndef __TRIE_H__
#define __TRIE_H__

#include <vector>
#include <utility>
#include <cstdint>
#include <map>
#include <stdexcept>


template<typename T>
class Trie{
    private:
        std::vector<std::pair<uint32_t, std::map<uint8_t, uint32_t>>> tree;
        std::vector<T> data;
    public:
        T& getValue(string &s){
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

        void insert(string &s, T &value){
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
            return tree[v].second.find(0) != tree[v].second.end();
        }

        bool hasKey(string &s){
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

        Trie() : tree(), data(){
            tree.push_back({});
        }

        ~Trie();
};

#endif