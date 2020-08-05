#ifndef DYNSTACK_H
#define DYNSTACK_H

#include "stack.hpp"

/**
 * stack implemented using a dynamic table struct.
 **/

template<class T>
struct dynamicStack{
    T *tab;
    int capa;
    int nb;
    int head;
};

template<class T>
class dynstack : public stack<T>{
    private:
        dynamicStack<T> stk;
    public:
    /**
     * @role: constructor.
     * @complexity: O(1).
     **/
    dynstack(){
        stk.capa =5; stk.nb = 0; 
        stk.tab = new T[stk.capa];
        stk.tab[0] = 0;
    }
    /**
     * @role: deconstructor.
     * @complexity: O(1).
     **/
    ~dynstack(){
        delete[] stk.tab;
    }
    /**
     * @role: checks if stack is empty.
     * @complexity: O(1).
     **/
    bool isStackEmpty() override{
        return (stk.nb == 0);
    }
    /**
     * @role: brings the first element in the stack.
     * @return: the first element without popping it.
     * @complexity: O(1).
     **/
    T firstElm() override{
        return (stk.tab[stk.nb]);
    }
    /**
     * @role: adds the given element to the stack.
     * @complexity: O(1). 
     **/
    void addElm(T e) override{
        stk.nb++;
        stk.tab[stk.nb] = e;
    }
    /**
     * @role: pops out the first element in the stack.
     * @return: returns the element after it gets popped.
     * @complexity: O(1).
     **/ 
    T popElm() override{
        T elm = stk.tab[stk.nb];
        stk.nb--;
        return elm;
    }
};


























#endif //DYNSTACK_H