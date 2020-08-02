#include <iostream>

using namespace std;;

//the type in which the list will accept
//typedef int TELEM; // type of element

template <class T>
class list{

    public:
    virtual int size() =0; //returns the size of the list
    virtual int elementAtInd(int i) =0; //returns the element at the index i
    virtual void deleteAtInd(int i) =0; // deletes the element at the index i
    virtual void insert(T e, int i) =0; // inserts the element e at the index i
    virtual void reverse() =0 ; //reverses the list.
};

//index out of bounds handling.
struct OutOfBoundsIndex : public exception{
    const char * what () const throw (){
        return "\n Error index out of bounds." ;
    }
};

