#include <iostream>
using namespace std; 

template <typename T>
class Node {
    public: 
        T data; 
        Node * succ; 
};

template <typename T>
class SList{
    private: 
        Node * head; 
    public: 
        SList(){head = nullptr;}
        ~SList();
        Node* getHead(){
            return head; 
        }
        
        void insert(T val){
            Node * newNode = new Node; 
            newNode->data = val; 
            newNode->succ = this->head; 
            this->head = newNode; 
        }

        void insert(Node * prev, T val){
            Node * newNode = new Node; 
            newNode->data = val; 

            newNode->succ = prev->succ;
            prev->succ = newNode;  
        }

        void insertInQueue(T val){
            Node * newNode = new Node;
            newNode->data = val; 
            newNode->succ = nullptr; 

            Node * iter = this->head; 
            if(iter == nullptr){
                this->head = newNode; 
            }else{
                while(iter->succ!=nullptr){
                    iter = iter->succ; 
                }
                iter->succ = newNode; 
            }
        }

        Nodo * research (T value){
            Node * p; 
            p=this->head; 
            while(p->succ!=nullptr){
                if(p->data == value){
                    return p; 
                }
                p=p->succ; 
            }
            return nullptr; 
        }
        
};

int main(){
    
}