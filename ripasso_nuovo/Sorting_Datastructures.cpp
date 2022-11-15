#include <iostream> //this thing lets me print stuff to the terminal 
#include <stdlib.h> //a library that uses the random function 
#include <ctime> //this is the thing i use to generate the random seed (uses time as a reference dont ask how please)
using namespace std; 

template <typename W>
int binarySearch2(W array2[], int low, int high, W key){
    W center_element; 
    int center; 
    while(low <= high){
        center = (low + high)/2; 
        center_element = array2[center]; 

        if(key == center_element){
            return center; 
        }else if(key < center_element){
            high = center -1; 
        }else{
            low = center + 1; 
        }
    }
    return -1; 
}

template <typename T>
int linearSearch(T array[], int n, T key){
    for(int i = 0; i < n; i++){
        if(array[i]==key){
            return i; 
        }
    }
    return -1; 
}

template <typename F>
void insertionSort(F array[], int n){ // i'm giving the "insertionSort()" function the things it needs to work inside of the parentheses
    F aux;
    for(int i = 1; i < n; i++){
        aux = array[i]; 
        int j = i-1; 
        while((j>=0)&&(array[j]>aux)){
            array[j+1] = array[j]; 
            j--; 
        }
        array[j+1] = aux; 
    } 
}

template <typename T>
void printArray(T array[], int n){
    for(int i = 0; i < n; i++){
        cout << array[i] <<" ";
    }
}


template <typename T>
class Node {
    public:
        T data; 
        Node * next;     
        Node(){}; 

};

template <typename T>
class SList{
    private: 
       Node<T> * nuts = nullptr; 
    public:
        
        //constructor
        SList(){nuts = nullptr;}

        //destructor
        ~SList(){
            Node<T> * iter = this->nuts; 
            while(iter != nullptr){
                Node<T> * tmp = iter->next; 
                delete iter; 
                iter = tmp; 
            }
        }

        //this returns the head of the list
        Node<T> * getNuts(){
            return nuts; 
        }

        void insert(T val){
            Node<T> * newNode = new Node<T>; 
            newNode->data = val; 
            newNode->next = this->nuts; 
            this->nuts = newNode;
        }

        //use this to create a node in front of another node in the list
        void insert(Node<T> * previous, T val){
            Node * newNode = new Node; 
            newNode->data = val; 

            newNode->next = previous->next;
            previous->next = newNode; 
        }

        Node<T> * research(T val){
            Node * p; 
            p = this->nuts; 
            while(p->next != nullptr){
                if(p->data == val){
                    return p; 
                }
                p=p->next;
            }
            return nullptr; 
        }

        void deleteNode(T val){
            Node * ant; 
            Node * thisnode; 
           
            if(this->nuts == nullptr){
                cout << "here1"<<endl; 
                cout << "this list is empty. no elements to remove"<<endl;
            }else if(this->nuts->data == val){
                ant = this->nuts;
                this->nuts = ant->next; 
                delete ant; 
            }else{
                
                ant = this->nuts;
                thisnode = this->nuts->next;

                //

                while( (ant != nullptr) &&(thisnode->data!=val)){ // 
                    cout << thisnode->data <<" "<<endl; 
                    ant = ant->next;
                    thisnode = thisnode->next;  
                }

                if(thisnode != nullptr){
                    ant->next = thisnode->next; 
                    delete thisnode; 
                }
            }
        }

        friend
        ostream& operator<<(ostream& out, SList& ls);
};

template <typename T>
class DNode{
    public: 
        T data;
        DNode * previous; 
        DNode * next;  
        DNode(DNode *pre, DNode *suc, T d): previous(pre), next(suc), data(d){};
};

template <typename T>
class DLinkedList{
    DNode<T> * nuts;
    public: 
        DLinkedList(){
            nuts->previous = nullptr; 
            nuts->next = nulllptr;
        }
        void DlistInsert(DNode<T> nod){
            nod.next = this->nuts; 
            if(this->head != nullptr){
                this->head->previous = nod; 
            }
            this->head = nod; 
            nod->previous = nullptr; 
        } 

        void DlistInsertHead(T value){
            DNode<T> * newNode = new DNode;
            newNode->data = value; 
            newNode->next = this->nuts; 
            if(this->nuts->previous != nullptr){
                newNode->previous = this->nuts->previous; 
            }
            this->nuts = newNode; 
        }

        void DListInsertInPlace(T value){
            DNode<T> * point = research(value); 
            
            DNode<T> * newNode = new DNode; 
            newNode->data = value; 
            newNode->next = point->next; 
            newNode->previous = point->next->previous; 
            point->next->previous = newNode;
            point->next = newNode; 

        }

        void DListDelete(T val){
            DNode<T> * toRemove = research(val);
            DNode<T> * ant = toRemove->previous; 
        }

        DNode<T> * research(T value){
            DNode * p; 
            p = this->head; 
            if(p->data ==value){
                return p; 
            }else if(p->next->data == value){
                return (p->next); 
            }else{
                while(p->next != nullptr){
                    if(p->data == value){
                        return p; 
                    } 
                }
            }
            return nullptr; 
        }

        friend
        ostream& operator<<(ostream& out, DLinkedList<T> & ls);
};

template <typename T>
ostream& operator<<(ostream& out, SList<T>& ls){
    Node* iter = ls.getNuts();
// for(Nodo* iter=ls.testa;iter!=nullptr;iter=iter->succ)
    while(iter!=nullptr){
        out << iter->data << " <--> ";
        iter = iter->next;
    }
    cout << "NULL" << endl;
    return out;
}

template <typename T>
ostream& operator<<(ostream& out, DLinkedList<T> & ls){
    Node* iter = ls.getNuts();
// for(Nodo* iter=ls.testa;iter!=nullptr;iter=iter->succ)
    while(iter!=nullptr){
        out << iter->data << " --> ";
        iter = iter->next;
    }
    cout << "NULL" << endl;
    return out;
}

int main(){
    srand(time(NULL));  

    int myArray[] = {8, 1, 3, 2, 10, -2, 203, 100, 53, 4};
    double myArray2[] = {0.4, 0.1, -37.7, 10, 2.43, 8.34, 92.4, 2.56, 94.3, 100.23};

    /*cout << "the number 5 is in index "<< (linearSearch(myArray, 14, 3))<< endl; 
    cout << "the number 7 is in index "<< (linearSearch(myArray, 14, 9))<< endl;
    cout << "the number 5 is in index "<< (linearSearch(myArray, 14, 748))<< endl;
    */

   //printArray(myArray2, 10); 
   
   //insertionSort(myArray2, 10); 
   //printArray(myArray2, 10); 

    
    SList<int> myList; 

    /*myList.insert(39); 
    myList.insert(42);
    myList.insert(8);
    myList.insert(248);
    myList.insert(69);
    myList.insert(33);
    myList.insert(420); 
    myList.insert(53);
 
 
    myList.deleteNode(33);  
    myList.deleteNode(69); 

    cout << myList; 
    cout << myList; 
    cout << myList;*/

    DLinkedList<int> listy; 
    listy.DlistInsertHead(192);
    listy.DlistInsertHead(19);
    listy.DlistInsertHead(1);

    cout << listy; 

}