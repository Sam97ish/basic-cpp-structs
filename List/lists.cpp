#include <iostream>
#include "dynlist.hpp"
#include "linkedlist.hpp"

using namespace std;;

//main function for testing the list implementations.

int main(){

    //testing the functionality of lists made using dynamic tables.
    /*// uncomment to test dynlist (dynamic table implementation).
    list_dyn<int> list = list_dyn<int>();

    list.insert(11, 0);
    list.insert(20, 1);
    list.insert(38, 2);
    list.insert(4, 3);
    */
    linked_list<char> list = linked_list<char>();

    list.insert('a');
    list.insert('b');
    list.insert('c');
    list.insert('d');

    try{
    cout << "the elements are " << list.elementAtInd(0) << " "
    << list.elementAtInd(1) << " " << list.elementAtInd(2) << " "
    << list.elementAtInd(3) << endl;

    list.reverse();
    cout << "the reversed elements are " << list.elementAtInd(0) << " "
    << list.elementAtInd(1) << " " << list.elementAtInd(2) << " "
    << list.elementAtInd(3) << endl;
    }
    catch(exception& e){
        cout << e.what() << endl;
    }

    cout << "the size is " << list.size() << endl;

    //list.deleteElm('a');
    list.deleteAtInd(0);
    cout << "the size after deleting the first element is " << list.size() << endl;

    try{
    cout << "the elements are " << list.elementAtInd(0) << " "
    << list.elementAtInd(1) << " " << list.elementAtInd(2) << " "
    << list.elementAtInd(3) << endl;
    }
    catch(exception& e){
        cout << e.what() << endl;
    }

}
