#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hashmap.hpp"

template <class K, class V>
struct hashtablestr{
    std::pair<K,V>* tab;
    int capa;
    int nb;
};
template<class K, class V>
class hashtable : public hashmap<K,V>{
    private:
    hashtablestr<K, V> hstb;

    public:
    /**
     * @role: consrtructor.
     * @complexity: O(1).
     **/
    hashtable(){
        hstb.capa = 10;
        hstb.nb = 0;
        hstb.tab = new std::pair<K, V>[hstb.capa];
    }
    /**
     * @role: deconstructor.
     * @complexity: O(1).
     **/
    ~hashtable(){
        delete[] hstb.tab;
    }
    int hashfunc(){
        ;
    }
    void insert() override{
        ;
    }
    V searchFor() override{
        ;
    }
    void deleteValue() override{
        ;
    }
};





















#endif //HASHTABLE_H