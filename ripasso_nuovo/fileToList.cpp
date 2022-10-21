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
        void changeData(int i; )

};

int main(){
    //kinda tired, going back to this in the morning
}