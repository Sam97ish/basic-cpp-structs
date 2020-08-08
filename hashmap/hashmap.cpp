#include "hashmap.hpp"
#include "hashchain.hpp"
#include <iostream>
#include <math.h>

using namespace std;


int hashfunc(int key, int cap){


    int caluclated_code = (int)( floor( cap * ( ( (float)key * 0.6180339887) % 1 ) ) % cap ); //hash function by multi.
    
    return caluclated_code;
}


int main(){

    hashChain<int, string> hashmapp = hashChain<int, string>((*hashfunc));

}