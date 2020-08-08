#ifndef HASHCHAIN_H
#define HASHCHAIN_H

#include <utility>
#include <vector>
#include "hashmap.hpp"
#include "../List/linkedlist.hpp"

template<class K, class V>
struct hashchain{
    linked_list< std::pair<K,V> > *tab;
    int capa;
    int nb;
    int (*hashFunctionPtr)(K,int);
};

template<class K, class V>
class hashChain : public hashmap<K,V>{
    private:
        hashchain<K,V> tabch;
    public:
    /**
     * @role: constructor.
     * @complexity: O(1).
     **/
    hashChain(int (*hashFunctionPtrr)(K, int)){
        tabch.capa = 10;
        tabch.tab = new linked_list< std::pair<K,V> >[tabch.capa];
        tabch.hashFunctionPtr = (*hashFunctionPtrr(K, int));
    }
    /**
     * @role: deconstructor.
     * @complexity: O(size(hashmap)).
     **/
    ~hashChain(){
        for(int i =0; i<tabch.capa; i++){
            delete tabch.tab[i];
        }
        delete[] tabch.tab;
    }
    /**
     * @role: brings back all the keys in the hashmap.
     * @return: a vector for keys with their specific type.
     * @complexity: O(size(table)*size(biggest chain)). size(table) must be enlarged when the table compression is near 0.7 to keep the chain sizes small.
     **/
    std::vector<K> keys() override{

        std::vector<K> vec;

        for(int i =0; i<tabch.capa; i++){ // go through all the table.

            int sizeOfLL = tabch.tab[i].nb;
            cell< std::pair<K,V> >* chain = tabch.tab[i].firstcell;

            for(int k=0; k<sizeOfLL; k++){//go through all the chain. should not be too long thanks to the hash function and other mesures.
                std::pair<K,V> pr = chain->getElm();
                vec.emplace(pr.first);
                chain = chain->next;
            }


        }
        return vec;
    }
    /**
     * @role: inserts the pair of value and key into the hashmap (K, V).
     * @complexity: O(1).
     **/
    void insert(std::pair(K key, V value)) override{

        int index = tabch.(*hashFunctionPtr)(key); //using the hashfunction to compute the proper index.

        linked_list< std::pair<K,V> > chainedlist = tabch.tab[index];

        chainedlist.insert(std::make_pair(key, value)); //inserting it inside the corresponding linked chain.
    }
    V searchFor(K key) override{
        ;
    }
    void deleteValue(K key) override{
        ;
    }
};



















#endif //HASHCHAIN_H