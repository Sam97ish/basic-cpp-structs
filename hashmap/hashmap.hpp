#ifndef HASHMAP_H
#define HASHMAP_H

#include<exception>
#include<vector>

/**
 * abstract class for all hashmaps/hashtables implementations.
 **/


template<class K, class V>
class hashmap{

    public:
        virtual std::vector<K> keys()=0; //returns a vector of all keys in the hashmap.
        virtual V searchFor(K key)=0; //search for a value by giving a key for it.
        virtual void insert(K key, V value)=0; //inserts a pair of a key and it's value.
        virtual void deleteValue(K key)=0; //deletes the corresponding value using the given key.


};

//compression size handling.
struct hashmapIsFull : public std::exception{
    const char * what () const throw (){
        return "\nHashmap is full, create a new instance or increase the hardcoded capacity." ;
    }
};

#endif //HASHMAP_H