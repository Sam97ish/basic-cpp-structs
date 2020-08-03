#include "queue.hpp"
#include "linkedqueue.hpp"
#include "dynqueue.hpp"
#include <iostream>

using namespace std;

//main function for testing the queue implementations.

int main(){
    //uncomment to test the other implementation.
    //linkedqueue<int> queue = linkedqueue<int>();
    dynqueue<char> queue = dynqueue<char>();

    cout << "is the queue empty (true) : " << queue.isQueueEmpty() << endl;
    try{
    queue.putElm('c');
    queue.putElm('b');
    queue.putElm('a');
    }
    catch(exception& e){
        cout << e.what() << endl;
    }
    cout << "the first element in the queue is : " << queue.firstElm() << endl;
    cout << "is the queue empty (false) : " << queue.isQueueEmpty() << endl;
    try{
    cout << "popping the elements in the queue : " << queue.popElm() << endl;
    cout << "popping the elements in the queue : " << queue.popElm() << endl;
    cout << "popping the elements in the queue : " << queue.popElm() << endl;
    }
    catch(exception& e){
        cout << e.what() << endl;
    }

}