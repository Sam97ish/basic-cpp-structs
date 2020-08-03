#include <iostream>
#include "dynlist.hpp"
#include "linkedlist.hpp"

using namespace std;;

//test code mimicing the functonality of std::lists

void test_list_dyn(){

    list_dyn<int> list = list_dyn<int>();
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3);


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

int main(){

    //testing the functionality of lists made using dynamic tables.
    //test_list_dyn();
    
    linked_list<int> list = linked_list<int>();

    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3);

    cout << "the elements are " << list.elementAtInd(0) << " "
    << list.elementAtInd(1) << " " << list.elementAtInd(2) << " "
    << list.elementAtInd(3) << endl;


}
