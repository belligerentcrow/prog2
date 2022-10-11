#include <iostream>
using namespace std; 

class Nodo{
    private:
        int value; 
        Nodo * succ; 
    public:
        int getValue(){
            return value; 
        }
        void setValue(int i){
            this->value = i; 
        }
        Nodo * getSucc(){
            return succ; 
        }
        void setSucc(Nodo * s){
            this->succ = s; 
        }
        Nodo(): value(NULL), succ(nullptr){}; 
        Nodo(Nodo *n, int d): succ(n), value(d){};

};

class SList{
        Nodo * head; 
    public: 
        SList(): head(nullptr){};
        void insertBehind(int n){
            Nodo * prox = new Nodo; 
            prox->setValue(n); 
            prox->setSucc(this->head);
            this->head = prox; 
        }
        void insertNewHead(int n){

        }
         
};

int main(){

}