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
        int head=0; 
        int tail=0; 
        int n; 
        T * queueArray; 
    public: 
        Queue(int len): n(len){
            queueArray = new T[len]; 
        }; 
        void enqueue(T x){
            queueArray[this->tail] = x; 
            if(this->tail == n){
                this->tail = 0;
            }else{
                this->tail++; 
            }
        }; 
        T dequeue(){
            T x = queueArray[head]; 
            if(this->head == n){
                this->head = 0; 
            }else{
                this->head++; 
            }
            return x; 
        }; 
        bool isEmpty(){
            if(head==tail){
                return true; 
            }else{
                return false; 
            }
        }; 
        bool isFull(){
            if(this->head == this->tail+1){
                return true; 
            }else{
                return false; 
            }
        }
        void printQueue(){
            cout <<"\t  |"<<endl<<"\t  |"<<endl<<"\t  V"<<endl<<"\t"; 
            int j = head; 
            while(j!= tail-1){
                cout <<"["<< queueArray[j] <<"] <-- "; 
                if(j == n){
                    j = 0; 
                }
                j++; 
            }
            cout << "[" << queueArray[j]<<"] "; 
        }
};



int main(){
    Stack<int> myStack(30);
    Queue<int> myQueue(30); 

    myQueue.enqueue(10); 
    myQueue.enqueue(13);
    myQueue.enqueue(39);
    myQueue.enqueue(21);
    myQueue.enqueue(124);
    myQueue.dequeue(); 
    myQueue.dequeue();
    myQueue.dequeue(); 
    myQueue.enqueue(420);
    myQueue.enqueue(3294);
    myQueue.enqueue(3248); 
    myQueue.printQueue(); 

    
}