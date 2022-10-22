#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std; 

template <typename T>
class DoubleNode{
    private:
        T value; 
        DoubleNode * prev; 
        DoubleNode * next; 
    public:
        T getValue(){
            return this->value;
        }
        DoubleNode * getPrev(){
            return this->prev;
        }
        DoubleNode * getNext(){
            return this->next;
        }
        DoubleNode(T val): value(val){
            prev = nullptr; 
            next = nullptr; 
        }

};

template <typename T>
class DLList{
    private:
        DoubleNode<T> * head; 
        int len; 
    public: 
        DLList(): len(0){}
        DoubleNode * search(T x){
            DoubleNode<T> * temp; 
            temp->prev = nullptr; 
            temp->next = head; 
            while((temp->next != nullptr) &&(temp->getValue()!=x)){
                temp = temp->next; 
            }
            return temp; 
        }
        void insert(){

        }
        void delete(){

        }

};

int main(){

}