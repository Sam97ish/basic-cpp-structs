#if !defined(QUEUE_H)
#define QUEUE_H
#include <exception>

/**
 * abstract class for all queue implementations.
 **/

template<class T>
class queue{

    virtual T firstElm()=0; //returns the first element without popping it.
    virtual bool isQueueEmpty()=0; //returns true if empty.
    virtual T popElm()=0; //pops the first element on the queue (FIFO).
    virtual void putElm(T e)=0; //puts the element in the queue.
};

//queue is full.
struct QueueIsFull : public std::exception{
    const char * what () const throw (){
        return "\nThe queue has only 10 places and is full, please free some elements." ;
    }
};

#endif // QUEUE_H
