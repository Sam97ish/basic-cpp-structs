#include <iostream>
#include "stack.hpp"
#include "linkedstack.hpp"
#include "dynstack.hpp"

using namespace std;

//main function for testing the stack implementations.

int main(){

    //uncomment to change between implementation.
    //linkedstack<int> stack = linkedstack<int>();
    dynstack<int> stack = dynstack<int>();

    cout << "checking if the stack is empty (true) : " << stack.isStackEmpty() << endl;

    stack.addElm(1);
    stack.addElm(2);
    stack.addElm(3);

    cout << "first element on the stack is : " << stack.firstElm() << endl;

    cout << "checking if the stack is empty (false) : " << stack.isStackEmpty() << endl;

    cout << "popping the stack " << stack.popElm() << endl;
    cout << "popping the stack " << stack.popElm() << endl;
    cout << "popping the stack " << stack.popElm() << endl;

    cout << "checking if the stack is empty (true) : " << stack.isStackEmpty() << endl;


}