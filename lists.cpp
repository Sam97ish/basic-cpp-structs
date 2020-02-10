#include <iostream>
#include "lists.hpp"
using namespace std;;

//code mimicing the functonality of std::lists

int main(){
    list_dyn list = list_dyn();
    list.insert(1,0);
    list.insert(2,1);
    list.insert(3,2);
    list.insert(4,3);


    cout << " the elements are " << list.elementAtInd(0) << " "
    << list.elementAtInd(1) << " " << list.elementAtInd(2) << " "
    << list.elementAtInd(3) << endl;

    cout << "the size is " << list.size() << endl;

    list.deleteAtInd(1);
    cout << "the size after deleting the first element is " << list.size() << endl;

    cout << "the elements are " << list.elementAtInd(0) << " "
    << list.elementAtInd(1) << " " << list.elementAtInd(2) << " "
    << list.elementAtInd(3) << endl;
}