#if !defined(LINKEDSTACK_H)
#define LINKEDSTACK_H
#include "stack.hpp"

template<class T>
struct cell{
    cell* next;
    T getElm(){return element;}
    void setElm(T e){element = e;}

    private:
    T element;
};

template<class T>
struct pointerToCell{
    cell<T>* first;
    int nb;
};

template<class T>
class linkedstack : public stack<T>{

    private:
    pointerToCell<T> head;

    public:
    /**
     * @role: constructor.
     * @complexity: O(1).
     */
    linkedstack(){
        head.first = nullptr;
        head.nb = 0;
    }
    /**
     * @role: deconstructor.
     * @complexity: O(size(stack)).
     **/
    ~linkedstack(){
        cell<T>* tmp;
        for(int i=0; i< head.nb; i++){
            tmp = (head.first)->next;
            delete head.first;
            head.first = tmp;
        }
        delete head.first;
    }
    /**
     * @role: checks if stack is empty.
     * @return: boolean, true if empty.
     * @complexity: O(1).
     **/
    bool isStackEmpty() override{
        bool check = (head.nb == 0);
        return check;
    }
    /**
     * @role: brings the first element in the stack.
     * @return: the first element without popping it.
     * @complexity: O(1).
     **/
    T firstElm() override{
        return (head.first)->getElm();
    }
    /**
     * @role: adds the given element to the stack.
     * @complexity: O(1).
     **/
    void addElm(T e) override{
        cell<T>* tmp;
        tmp = head.first;
        head.first = new cell<T>;
        (head.first)->setElm(e);
        (head.first)->next = tmp;
        head.nb++;
    }
    /**
     * @role: pops out the first element in the stack.
     * @return: returns the element after it gets popped.
     * @complexity: O(1).
     **/
    T popElm() override{
        cell<T>* tmp;
        tmp = (head.first)->next;
        T element = (head.first)->getElm();
        delete head.first;
        head.first = tmp;
        head.nb--;
        return element;
    }
};


#endif // LINKEDSTACK_H
