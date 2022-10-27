#include <iostream>
using namespace std; 

template <typename T>
class Node {
    public:
        T key; 
        Node * left; 
        Node * right; 
        Node * parent; 
}; 

template <typename T>
class BST{
    private:
        //Node<T> * root; 
        int numElem;

        void inOrderPriv(Node<T> * p) const{
            // sx - root - dx
            inOrderPriv(p->left);
            cout << p->key << " "; 
            inOrderPriv(p->right); 
        } 
        void postOrderPriv(Node<T> * p) const{
            // root - sx - dx
            cout << p->key << " "; 
            inOrderPriv(p->left);
            inOrderPriv(p->right); 
        }    
        void preOrderPriv(Node<T> * p) const{  
            // sx - dx - root
            inOrderPriv(p->left);
            inOrderPriv(p->right); 
            cout << p->key << " "; 
        } 

        void cancellaPriv(Node<T> *); 
        void trapianta(Node<T> * u, Node<T> * v); 
        Node<T> * min(Node<T> * x); 

    public:
        BST(): root(nullptr){}; 
        
        Node<T> * root; 

        void insert(T val){
            //initialize the actual node i need
            Node<T> * newNode = new Node<T>; 

            Node<T> * x = root; //pointer: tracks where i will put my node
            Node<T> * y = nullptr; //pointer: tracks the parent of the new node

            //i give the value i want to insert to the new node
            newNode->key = val;

            //the new node has 2 nullptr children
            newNode->left = newNode->right = nullptr; 

            // until i reach an empty leaf
            while(x != nullptr){
                y = x; 
                if(val < x->key){
                    x = x->left; 
                }else{
                    x = x->right; 
                }                
            }

            //this newNode that contains my value becomes y's child
            newNode->parent = y; 

            if(y==nullptr){
                root = newNode; 
            }else if(val > y->key){
                y->right = newNode; 
            }else{
                y->left = newNode; 
            }
            numElem++;
        }

        void inOrder() const{
            inOrderPriv(root); 
        } 
        void preOrder() const{
            preOrderPriv(root); 
        }
        void postOrder() const{
            postOrderPriv(root); 
        }

        int height(Node<T> * brain) const{ //weird counting system????
            if((brain == nullptr)||( brain== root && brain->left ==nullptr &&brain->right == nullptr)) return 0; 

            int leftH = height(brain->left); 
            int rightH = height(brain->right); 

            if(leftH > rightH){
                return (leftH); //ortis said leftH+1
            }else{
                return(rightH); //ortis said rightH+1
            }
        }

        bool erase(T x); 
        T minimum(); 

        friend
        ostream & operator<<(ostream& out, const BST<T>& t); 

};

int main(){
    
}