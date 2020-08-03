#ifndef DYNQUEUE_H
#define DYNQUEUE_H

#include "queue.hpp"

/**
 * queue implemented using a dynamic table struct.
 **/

template<class T>
struct dynamicQueue{
    T* tab;
    int capa;
    int nb;
    int first;
    int last;
};

template<class T>
class dynqueue : public queue<T>{
    private:
    dynamicQueue<T> que;

    public:
    /**
     * @role:constructor.
     * @complexity: O(1).
     **/
    dynqueue(){
        que.capa = 10; que.first = 0;
        que.last = 0; que.nb =0;
        que.tab = new T[que.capa];
    }
    /**
     * @role:deconstructor.
     * @complexity: O(1).
     **/
    ~dynqueue(){
        delete que.tab;
    }
    /**
     * @role: checks if the queue is empty.
     * @complexity: O(1).
     **/
    bool isQueueEmpty() override{
        return (que.nb == 0);
    }
    /**
     * @role: brings the first element of the queue.
     * @return: the first element in the queue without popping it.
     * @complexity: O(1)
     **/
    T firstElm() override{
        return que.tab[que.first];
    }
    /**
     * @role: puts the given element in the queue.
     * @complexity: O(1).
     **/
    void putElm(T e) override{
        if(que.nb == 0){
            que.tab[que.last] = e;
            que.nb++;
        }else{
            int pos = (que.last + 1) % que.capa;
            if(pos == que.first){
                throw QueueIsFull();
            }else{
                que.tab[pos] = e;
                que.last++;
                que.nb++;
            }
        }
    }
    /**
     * @role: pops the element from the queue.
     * @return: returns the element popped.
     * @complexity: O(1).
     **/
    T popElm() override{
        if(que.first == que.last+1){
            throw QueueIsFull();
        }else{
            T element = que.tab[que.first];
            que.first = (que.first+1) % que.capa;
            que.nb--;
            return element;
        }
    }

    

};


#endif // DYNQUEUE_H