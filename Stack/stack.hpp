#ifndef STACK_H
#define STACK_H




template<class T>
class stack{
    public:
        virtual bool isStackEmpty()=0; //checks if stack is empty.
        virtual T firstElm()=0; //returns the element at the top without popping it.
        virtual void addElm(T e)=0; //adds the given element to the stack.
        virtual  T popElm()=0; //pops the first element out of the stack.
};

















#endif //STACK_H
