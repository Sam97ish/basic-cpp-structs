#ifndef HASHMAP_H
#define HASHMAP_H

/**
 * abstract class for all hashmaps/hashtables implementations.
 **/


template<class K, class V>
class hashmap{

    public:
        virtual std::vector<K> keys()=0; //returns a vector of all keys in the hashmap.
        virtual V searchFor(K key)=0; //search for a value by giving a key for it.
        virtual void insert(std::pair(K key, V value))=0; //inserts a pair of a key and it's value.
        virtual void deleteValue(K key)=0; //deletes the corresponding value using the given key.


};

#endif //HASHMAP_H