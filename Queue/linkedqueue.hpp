#if !defined(LINKEDQUEUE_H)
#define LINKEDQUEUE_H

#include "queue.hpp"

/**
 * queue implemented using linked lists.
 **/

template<class T>
struct Lqueue{
    Lqueue<T>* next;
    T getElm(){return element;}
    void setElm(T e){ element = e;}

    private:
    T element;
};

template<class T>
struct controller{
    Lqueue<T>* head;
    Lqueue<T>* tail;
    int nb;
};
template<class T>
class linkedqueue : public queue<T>{
    private:
    controller<T> cntrl;

    public:
    /**
     * @role: constructor.
     * @complexity: O(1).
     **/
    linkedqueue(){
        cntrl.head = new Lqueue<T>;
        cntrl.tail = cntrl.head;
        cntrl.nb = 0;
    }
    /**
     * @role: deconstructor.
     * @complexity: O(size(queue))
     **/
    ~linkedqueue(){
        Lqueue<T>* tmp ;
        for(int i=0; i< cntrl.nb; i++){
            tmp = cntrl.head->next;
            delete cntrl.head;
            cntrl.head = tmp;
        }
        delete cntrl.head;
    }
    /**
     * @role: checks if the queue is empty.
     * @complexity: O(1)
     **/
    bool isQueueEmpty() override{
        return (cntrl.nb == 0);
    }
    /**
     * @role: brings the first element of the queue.
     * @return: the first element in the queue without popping it.
     * @complexity: O(1)
     **/
    T firstElm() override{
        return cntrl.head->getElm();
    }
    /**
     * @role: puts the given element in the queue.
     * @complexity: O(1).
     **/
    void putElm(T e) override{


        if(cntrl.nb == 0){
            cntrl.tail = cntrl.head;
            cntrl.tail->setElm(e);
            cntrl.nb++;
        }else{
            Lqueue<T>* tmp = cntrl.tail;
            cntrl.tail = new Lqueue<T>;
            cntrl.tail->setElm(e);
            tmp->next = cntrl.tail;
            cntrl.nb++;
        }
    }
    /**
     * @role: pops the element from the queue.
     * @return: returns the element popped.
     * @complexity: O(1).
     **/
    T popElm() override{
        Lqueue<T>* tmp = cntrl.head->next;
        T element = cntrl.head->getElm();
        delete cntrl.head;
        cntrl.head = tmp;
        cntrl.nb--;
        return element;
    }
};

#endif // LINKEDQUEUE_H
