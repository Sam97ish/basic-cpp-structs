#include <iostream>
#include "lists.hpp"
#include <stdexcept>
using namespace std;

//custom structs similar to what std::vector might be
typedef struct{
    int *tab; //dynamic table
    int capa; //capacity of the list
    int nb; //number of elements in the list
}dynamic_table;



template <class T>
class list_dyn:public list<T> {
    private:
        dynamic_table ls;
    public:

        /**
         * @role: create the list.
         * @complexity: O(1)
         **/
        list_dyn() { // constructor using dynamic table
            ls.capa = 3; ls.nb = 0;
            ls.tab = new T[ls.capa];
        }
        /**
         * @role: frees the alocated space.
         * @complexity: O(1)
         **/
        ~list_dyn() { delete[] ls.tab;} // deconstructor
        
        /**
         * @return : the size of the list.
         * @complexity : O(1)
         **/
        int size() override{return ls.nb;}

        /**
         * @return : returns the element at the given index
         * @param : index (int)
         * @complexity: O(1) 
         **/
        T elementAtInd(int i) override{

            if(i >= ls.nb){
                throw out_of_range("index is out of bounds");
            }else{
                return ls.tab[i];
            }
            
        }
        
        /**
         * @role: delete the element at the index given.
         * @param: index (int)
         * @complexity: O( size(list) - i )
         **/
        void deleteAtInd(int i) override{
            
            for(int j = i; j <= ls.nb-1; j++){
                ls.tab[j] = ls.tab[j+1];
            }
            ls.nb -=1;
        }
        /**
         * @role: inserts the element in the index given.
         * @param: e : element of the specified type, i : index (int)
         * @complexity: Omega( size(list) - i ), O( size(list) )
         **/
        void insert(T e, int i) override{
            
            if (ls.nb == ls.capa){
                int *temp;
                temp = new int[ls.capa *2];
                for(int i = 0; i <= ls.nb -1; i++){
                    temp[i] = ls.tab[i];
                 }
                delete[] ls.tab;
                ls.tab = temp;
                ls.capa = ls.capa*2;
               
            }

            for(int j = ls.nb-1; j >= i; j--){
                ls.tab[j+1] = ls.tab[j];
            }
            ls.tab[i] = e;
            ls.nb +=1;
            
        }

        void reverse() override{

        }

};

//error handling
struct OutOfBounds : public exception{
    const char* what() const throw(){
        return "Error index out of bounds" ;
    }
};