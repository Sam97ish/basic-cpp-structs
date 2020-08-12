#include "hashmap.hpp"
#include "hashchain.hpp"
#include <iostream>

using namespace std;


int main(){

    hashChain<int, string> hashmapp = hashChain<int, string>();

    try{
    hashmapp.insert(1, "first elem");
    hashmapp.insert(2, "second elem");
    hashmapp.insert(3, "third elem");
    hashmapp.insert(4, "fourth elem");
    }
    catch(exception& e){
        cout << e.what() << endl;
    }

    cout << "the elements are : " << hashmapp.searchFor(1) << " ," << hashmapp.searchFor(2)
     << " ," << hashmapp.searchFor(3) << " ," << hashmapp.searchFor(4)  << endl;

    vector<int> vec = hashmapp.keys();
    for(int i =0; i< vec.size(); i++){
        cout << "the keys are : " << vec.at(i) << endl;
    }
    
    cout<< "deleting the element with the key 2 : " <<endl;
    hashmapp.deleteValue(2);
    
    cout << "the elements after deleting are : " << hashmapp.searchFor(1) << " ," << hashmapp.searchFor(2)
     << " ," << hashmapp.searchFor(3) << " ," << hashmapp.searchFor(4) << endl;

    vector<int> vec2 = hashmapp.keys();
    for(int i =0; i< vec2.size(); i++){
        cout << "the keys after deleting are : " << vec2.at(i) << endl;
    }
}