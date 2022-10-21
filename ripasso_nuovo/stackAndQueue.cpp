#include <iostream>
using namespace std; 

template <typename T>
class Stack{
    private:
        int top;
        int lenght;
        T * STarray; 
    public:
        Stack(int len): lenght(len){
            STarray = new T[len]; 
            top = -1; 
        }
        void push(T x){
            if(this->top == this->lenght){
                cout << "Error! Stack overflow!"<<endl; 
                return; 
            }else{
                top++; 
                STarray[this->top] = x;  
            }
        } 
        T pop(){
            if(isEmpty()){
                cout << "Error! Stack underflow!"<<endl; 
            }else{
                this->top--; 
                return STarray[top+1]; 
            }
        }
        bool isEmpty(){
            if(this->top < 0){
                return true; 
            }else{
                return false; 
            }
        }
        void print(){
            cout << "Printing stack: "<<endl; 
            cout << "first -->"; 
            for(int i = top; i >= 0; i--){
                cout << "["<< STarray[i] <<"] "<<endl<<"\t"; 
            }
        }

}; 

template <typename T>
class Queue{
    private:
        int head; 
        int tail; 
    public: 
        Queue(); 
        T enqueue(); 
        T dequeue(); 
        bool isEmpty(); 
};



int main(){
    Stack<int> myStack(30);



    myStack.print();    
}