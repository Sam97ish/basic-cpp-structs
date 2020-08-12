#ifndef HASHCHAIN_H
#define HASHCHAIN_H

#include <utility>
#include <vector>
#include <math.h>
#include <iostream>
#include "hashmap.hpp"
#include "../List/linkedlist.hpp"

template<class K, class V>
struct hashchain{
    linked_list< std::pair<K,V> >* *tab;
    int capa;
    int nb=0;
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
    hashChain(){
        tabch.capa = 10; //only 70% of the capacity can be used to keep the time complexities low.
        tabch.nb = 0;
        tabch.tab = new linked_list< std::pair<K,V> >*[tabch.capa];
    }
    /**
     * @role: deconstructor.
     * @complexity: O(1).
     **/
    ~hashChain(){
        for(int i=0; i<tabch.capa; i++){
            delete tabch.tab[i];
        }
        delete[] tabch.tab;
    }
    /**
     * @role: hash function by multiplication.
     * @complexity: O(1).
     **/
    int hashfunc(int key, int cap){ //customisable and changable.


    int caluclated_code = (int) floor(cap * std::fmod( ( key * 0.6180339887 ) , 1.0 ) ); //hash function by multi.
    
    return caluclated_code;
    }
    /**
     * @role: brings back all the keys in the hashmap.
     * @return: a vector for keys with their specific type.
     * @complexity: O(size(table)*size(biggest chain)). size(table) must be enlarged when the table compression is near 0.7 to keep the chain sizes small.
     **/
    std::vector<K> keys() override{

        std::vector<K> vec;

        for(int i =0; i<tabch.capa; i++){ // go through all the table.

            if(tabch.tab[i] != nullptr){

                int sizeOfLL = tabch.tab[i]->getnb();
                cell< std::pair<K,V> >* chain = tabch.tab[i]->getfirstcell();

                for(int k=0; k<sizeOfLL; k++){//go through all the chain. should not be too long thanks to the hash function and other mesures.
                    std::pair<K,V> pr = chain->getElm();
                    vec.emplace(vec.end(), pr.first);
                    chain = chain->next;
                }
            }
        }
        return vec;
    }
    /**
     * @role: inserts the pair of value and key into the hashmap (K, V).
     * @complexity: O(1).
     **/
    void insert(K key, V value) override{

        double alpha = ( ( (double) tabch.nb) / tabch.capa);

        if( alpha < 0.7){ //for optimisation purposes.
            
            int index = this->hashfunc(key, tabch.capa); //using the hashfunction to compute the proper index.

            if(tabch.tab[index] == nullptr){

                linked_list< std::pair<K,V> >* chainedlist = new linked_list<std::pair<K,V>>();
                chainedlist->insert(std::make_pair(key, value)); //inserting it inside the corresponding linked chain.
                tabch.nb++;
                tabch.tab[index] = chainedlist;

            }else{

                linked_list< std::pair<K,V> >* chainedlist = tabch.tab[index];
                chainedlist->insert(std::make_pair(key, value)); //inserting it inside the corresponding linked chain.
                tabch.nb++;
            }
        }else{
            throw hashmapIsFull();
        }

    }
    /**
     * @role: searches for the element and returns the corresponding value.
     * @return: value of type V specified or NULL if not found.
     * @complexity: O(size(chainedlist)). typically should be O(1 + alpha) where alpha (load factor) is lesser than 0.7 so that the complexity becomes constant.
     **/
    V searchFor(K key) override{

        int index = this->hashfunc(key, tabch.capa);
        linked_list< std::pair<K,V> >* chainedlist = tabch.tab[index];
        
        cell< std::pair<K,V> >* tmp = chainedlist->getfirstcell();
        bool notfound = true;
        V value;

        while(chainedlist->size() > 0 && tmp != nullptr && notfound){

           std::pair<K,V> couple = tmp->getElm();

           if(couple.first == key){
               notfound = false;
               value = couple.second;
           }

           tmp = tmp->next;

        }
        
        return value;
    }
    /**
     * @role: deletes the value corresponding to the given key in the hashmap.
     * @complexity: O(size(chainedlist)). typically should be O(1 + alpha) where alpha (load factor) is lesser than 0.7 so that the complexity becomes constant.
     **/
    void deleteValue(K key) override{

        int index = this->hashfunc(key, tabch.capa);
        linked_list< std::pair<K,V> >* chainedlist = tabch.tab[index];
        cell< std::pair<K,V> >* tmp = chainedlist->getfirstcell();
        bool notfound = true;
        V value;
        int ind = 0;

        while(chainedlist->size() > 0 && tmp != nullptr && notfound){

           std::pair<K,V> couple = tmp->getElm();

           if(couple.first == key){
                notfound = false;
                chainedlist->deleteAtInd(ind);
                tabch.nb--;       
           }
           
            ind++;
            tmp->next;

        }

        

    }
};



















#endif //HASHCHAIN_H