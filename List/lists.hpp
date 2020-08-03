#ifndef LISTS_H
#define LISTS_H

#include <exception>

//the type in which the list will accept
//typedef int TELEM; // type of element

template <class T>
class list{

    public:
    virtual int size() =0; //returns the size of the list
    virtual T elementAtInd(int i) =0; //returns the element at the index i
    virtual void deleteAtInd(int i) =0; // deletes the element at the index i
    virtual void reverse() =0 ; //reverses the list.
};

//index out of bounds handling.
struct OutOfBoundsIndex : public std::exception{
    const char * what () const throw (){
        return "\nError index out of bounds." ;
    }
};

#endif

