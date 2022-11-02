#include <iostream>
using namespace std;

template <typename T>
class Node{
    private: 
        T value; 
        Node * prev; 
        Node * succ; 
    public: 
        Node(T x){
            this->value = x;
        };
        Node(){};
        //getters
        Node * getPrev(){
            return this->prev; 
        }
        Node * getSucc(){
            return this->succ; 
        }
        T getVal(){
            return this->value; 
        }

        //setters
        void setPrev(Node * x){
            this->prev = x; 
        }
        void setSucc(Node * x){
            this->succ = x; 
        }
        void setVal(T x){
            this->value = x; 
        }
};


template <typename T>
class StackArr{
    private: 
    public:
        T * arr; 
        int indexFondo;
        int lenghtArr; 
        int elements; 
    
        StackArr(int _l): lenghtArr(_l){
            arr = new T[_l]; 
            for(int i = 0; i<_l; i++){
                arr[i] = 0; 
            }
            elements = 0;  //elements = 1 <--
            indexFondo = -1; //indexFondo = 0 <--
        }
        StackArr(){}; 
        T pop(){
            T temp;
            if(indexFondo ==0){
                    cout << "ERROR: stack underflow"<<endl; 
                    return -1; 
            }else{
                temp = arr[indexFondo]; 
                arr[indexFondo] = 0; 
                indexFondo--; 
                elements--; 
                
            }
            return temp; 
        }
        void push(T x){
            if(indexFondo==lenghtArr){
                cout << "ERROR: stack overflow"<<endl; 
            }else{
                indexFondo++;
                elements++; 
                arr[indexFondo] = x; 

            }
        }
};


template <typename T>
class StackList{
    private:
        Node<T> * first;
        Node<T> * pointFondo; 
        int elements;

    public: 
        StackList(): first(nullptr), pointFondo(nullptr){
            elements = 0; 
        }; 

        T pop(){

            T temp; 
            if(pointFondo==nullptr){
                cout <<"ERROR: stack underflow"<<endl; 
                return -1;
            }else{
                temp = pointFondo->getVal();
                pointFondo->getPrev()->setSucc(nullptr); 
                pointFondo = pointFondo->getPrev();
                elements--; 
                
            }
            return temp; 
        };

        StackList * push(T va){

            Node<T> * newNode = new Node<T>;
            newNode->setSucc(nullptr);
            newNode->setVal(va); 

            if(pointFondo!=nullptr){
                newNode->setPrev(pointFondo); 
                pointFondo->setSucc(newNode); 
                newNode->setSucc(nullptr); 
                pointFondo = newNode; 
            }else{
                pointFondo=newNode; 
                first=newNode; 
                newNode->setPrev(first); 
                first->setSucc(newNode);

            }
            elements++; 
            return this; 
        };

        void print(){
            Node<T> * temp = new Node<T>; 
            temp = first;
            cout << "Printing..."<<endl;
            while(temp != nullptr){
                cout << temp->getVal() <<" -> ";
                temp = temp->getSucc(); 
            }
            cout <<"EndPrint"<<endl;
        }
        

};

int main(){
    StackArr<int> myStack1(20); 

    myStack1.push(29); 
    myStack1.push(578);
    myStack1.push(295);

    for(int i = 0; i < 3; i++){
        cout << myStack1.arr[i]<<" "<<endl; 
    }
    myStack1.pop(); 
    cout << endl; 
    for(int i = 0; i < 2; i++){
        cout << myStack1.arr[i]<<" "<<endl; 
    }

    StackList<int> myStack2; 
    myStack2.push(42); 
    myStack2.push(24); 
    myStack2.push(834);
    myStack2.print();
    myStack2.pop();
    myStack2.print();

    cout << endl<<endl; 

}