#include <iostream>

using namespace std;;

//custom structs similar to what std::vector might be
typedef struct{
    int *tab;
    int capa;
    int nb;
}dynamic_table;



//the type in which the list will accept
typedef int TELEM; // type of element


class list{

    public:
    virtual int size() =0; //returns the size of the list
    virtual int elementAtInd(int i) =0; //returns the element at the index i
    virtual void deleteAtInd(int i) =0; // deletes the element at the index i
    virtual void insert(TELEM e, int i) =0; // inserts the element e at the index i
};

class list_dyn:public list {
    private:
        dynamic_table ls;
    public:
        list_dyn() { // conlsuctor using dynamic table
            ls.capa = 3; ls.nb = 0;
            ls.tab = new TELEM[ls.capa];
        }

        ~list_dyn() { delete[] ls.tab;} // deconlsuctor
        
        int size() override{return ls.nb;}

        TELEM elementAtInd(int i) override{

            if(i >= ls.nb){
                cout << "Error index " << i << " out of bounds" << endl;
                return -999;
            }else{
                return ls.tab[i];
            }
            
        }
        
        void deleteAtInd(int i) override{
            
            for(int j = i; j <= ls.nb-1; j++){
                ls.tab[j] = ls.tab[j+1];
            }
            ls.nb -=1;
        }

        void insert(int e, int i) override{
            
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

};

