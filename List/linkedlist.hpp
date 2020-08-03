
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "lists.hpp"
#include <iostream>

using namespace std;

/**
 * list implemented using linked lists.
 **/

template<class T>
struct cell{
 cell* next;
 cell* prev;
 void setElem(T elm){ element = elm;}
 T getElm(){return this->element;}

 private:
 T element;
};

template<class T>
struct linkedlist{
    cell<T>* firstcell;
    cell<T>* lastcell;
    int nb=0;
};

template<class T>
class linked_list : public list<T> {
    private:
        linkedlist<T> ls;
    public:
    
        /**
         * @role: constructor.
         * @complexity: O(1).
         **/
        linked_list(){
            ls.firstcell = nullptr;
            ls.lastcell = ls.firstcell;
            ls.nb = 0;
        }
        /**
         * @role: deconstructor.
         * @complexity: O(size(list)).
         **/
        ~linked_list(){
            if(ls.firstcell != nullptr){

                cell<T>* lastelem = ls.lastcell;

                while(lastelem->prev != nullptr){
                    lastelem = lastelem->prev;
                    delete lastelem->next;
                }
                delete ls.firstcell;
            }
        }
        /**
        * @return: the size of the list in int.
        **/
        int size(){ return ls.nb;}
        /**
        * @return: returns the element at the given index.
        * @param: index (int).
        * @complexity: O(i).
        **/
        T elementAtInd(int i) override{

                if(i >= ls.nb){
                    throw OutOfBoundsIndex();
                }

                cell<T>* firstcell = ls.firstcell;

                for(int j =0; j < i; j++){
                    firstcell = firstcell->next;
                }
                T element = firstcell->getElm();
                return element;
        }
        /**
        * @role: delete the element at the index given.
        * @param: index (int)
        * @complexity: Omega(1), O(i).
        **/
        void deleteAtInd(int i) override{
                
                cell<T>* firstcell = ls.firstcell;

                if(i == 0){//case of first element.

                    cell<T>* rest_of_list = firstcell->next;
                    delete ls.firstcell;
                    ls.firstcell = rest_of_list;
                    ls.nb--;

                }else if(i == ls.nb-1){//case of last element.

                    ls.lastcell = ls.lastcell->prev;
                    delete ls.lastcell->next;
                    ls.nb--;
                    
                }
                else{//every other case.

                    for(int j = 0; j < i-1; j++){
                        
                        firstcell = firstcell->next;

                    }
                    cell<T>* rest_of_list = (firstcell->next)->next;
                    delete firstcell->next;
                    firstcell->next = rest_of_list;
                    ls.nb--;
                    

                }
        }
        /**
        * @role: inserts the element in the list.
        * @param: e : element of the specified type.
        * @complexity: Omega( 1 ), O( i ).
        **/
        void insert(T e){

            cell<T>* newcell = new cell<T>;
            newcell->setElem(e);

            if(ls.firstcell == nullptr){

                ls.firstcell = newcell;
                ls.firstcell->next = nullptr;
                ls.firstcell->prev = nullptr;
                ls.lastcell = ls.firstcell;
                ls.nb++;

            }else{
                cell<T>* tmp = ls.lastcell;
                ls.lastcell = newcell;
                ls.lastcell->prev = tmp;
                tmp->next = ls.lastcell;
                ls.lastcell->next = nullptr;
                ls.nb++;
            }
        }
        /**
         * @role: reverses the list.
         * @complexity: O(size(list)).
         **/
        void reverse() override{

            cell<T>* tmp = ls.firstcell;
            cell<T>* prevToNext;

            tmp->prev = tmp->next;
            for(int k =0; k < ls.nb-1; k++){
                tmp = tmp->prev;
                prevToNext = tmp->prev;
                tmp->prev = tmp->next;
                tmp->next = prevToNext;
            }
            tmp = ls.firstcell;
            ls.firstcell = ls.lastcell;
            ls.lastcell = tmp;
            ls.firstcell->prev = nullptr;
            ls.lastcell->next = nullptr;
            
        }
};

#endif //LINKEDLIST_H