#include <iostream>
using namespace std; 

template <typename T>
class BSTNode{
    private:
        T key; 
        BSTNode * parent = nullptr; 
        BSTNode * left; 
        BSTNode * right; 
    public:
        //constructor
        BSTNode(T _k){
            key = _k; 
            parent = nullptr; 
            left = nullptr; 
            right = nullptr; 
        }

        //getters
        BSTNode * getParent(){
            return parent; 
        }
        BSTNode * getLeft(){
            return left; 
        }
        BSTNode * getRight(){
            return right; 
        }
        T getKey(){
            return key; 
        }
        void setLeft(BSTNode * leftnode){
            this->left = leftnode; 
        }
        void setLeft(T x){
            this->left->key = x; 
        }
        void setRight(BSTNode * rightnode){
            this->right = rightnode; 
        }
        void setRight(T x){
            this->right->key = x; 
        }
        void setParent(BSTNode * _p){
            this->parent = _p; 
        }
        void setParent(T x){
            this->parent->key = x; 
        }
}; 

template <typename T>
class BST{
    private:
        BSTNode<T> * root; 
    public: 
        BST(){
            root = nullptr;
        }
        BST(T _k){
            root = new BSTNode<T>(_k); 
        }
        BSTNode<T> * getRoot(){
            return root; 
        }
        void inorderTreeWalkPrint(BSTNode<T> * x){
            if(x != nullptr){
                inorderTreeWalkPrint(x->getLeft());
                cout << x->getKey() <<" "<<endl; 
                inorderTreeWalkPrint(x->getRight()); 
            }
        }

        void preOrder(BSTNode<T> * x){
            if(x != nullptr){
                cout << x->getKey() << " "; //nota del prof = visita la radice ?
                preOrder(x->getLeft());     //visita il sottoalbero sinistro
                preOrder(x->getRight());    //visita il sottoalbero destro
            }
        }

        void postOrder(BSTNode<T> * x){
            if(x != nullptr){
                postOrder(x->getLeft());
                postOrder(x->getRight()); 
                cout << x->getKey() << " "; 
            }
        }

        void treeInsert(T newVal){
            BSTNode<T> * y = nullptr; 
            BSTNode<T> * x = this->root; 
            while(x != nullptr){
                y = x; 
                if(newVal < x->getKey()){
                    x = x->getLeft(); 
                }else{
                    x = x->getRight(); 
                }
            }
            BSTNode<T> * newNode = new BSTNode(newVal); 
            newNode->setParent(y); 
            if(y == nullptr){
                this->root = newNode; 
            }else if(newVal < y->getKey()){
                y->setLeft(newNode); 
            }else{
                y->setRight(newNode); 
            }
            }
        BSTNode<T> * iterativeSearch(T key){
            BSTNode<T> * searchNode;
            searchNode = this->root;
            while((searchNode != nullptr)&&(key != searchNode->getKey())){
                if(key < searchNode->getKey()){
                    searchNode = searchNode->left; 
                }else{
                    searchNode = searchNode->right; 
                }
            }
            return searchNode; 
        }
        BSTNode<T> * getMin(BSTNode<T> * fromHere){
            BSTNode<T> * minNode = fromHere;
            while(minNode->getLeft() != nullptr){
                minNode = minNode->getLeft(); 
            }
            return minNode; 
        }
        BSTNode<T> * getMax(BSTNode<T> * fromHere){
            BSTNode<T> * maxNode = fromHere;
            while(maxNode->getRight() != nullptr){
                maxNode = maxNode->getRight(); 
            }
            return maxNode; 
        }

        //Due casi: 1) il sottoalbero destro di x non è vuoto. caso banale
        //2) il sottoalbero dx di x non lo è 
        BSTNode<T> * getSuccessor(BSTNode<T> * fruit = getRoot()){
            if(fruit!=nullptr){
                return getMin(fruit); 
            }
            BSTNode<T> * succ = fruit->getParent();
            while(succ != nullptr && fruit == succ->right){
                fruit = succ; 
                succ = succ->getParent(); 
            }
            return succ; 
        }

        //ricerca in un albero binario di ricerca
        BSTNode<T> * recursiveSearch(BSTNode<T> * mynode, T element){
            if(mynode == nullptr || element == mynode->getKey()){
                return mynode; 
            }
            if(element < mynode->getKey()){
                return search(mynode->getLeft(), element); 
            }
            if(element > mynode->getKey()){
                return search(mynode->getRight(), element); 
            }
        }

        BSTNode<T> * iterativeSearch(BSTNode<T> * mynode, T element){
            while((mynode != nullptr)&&(mynode->getKey()!=element)){
                if(element < mynode->getKey()){
                    mynode = mynode->getLeft(); 
                }else{
                    mynode = mynode->getRight(); 
                }
                return mynode; 
            }
        }

        /*deleting a node!! 
        1) node has no child nodes
        2) node has 1 child node
        3) node has 2 child nodes (hardest)
        */
       void deleteNode(BSTNode<T> * mynode){
            //no children
            if(mynode->getLeft() == nullptr && mynode->getRight() == nullptr){ 
                BSTNode<T> * temp = mynode; 
                if((mynode->getParent() != nullptr) && (mynode->getLeft() == mynode)){
                    mynode->getParent()->getLeft() = nullptr; 
                }else if((mynode->getParent() != nullptr && (mynode->getParent->getRight() == mynode)){
                    mynode->getParent->getRight() = nullptr; 
                }
                delete mynode; 
            }
            //one child
            if(((mynode->getLeft() == nullptr) && (mynode->getRight()==nullptr))||((mynode->getLeft() == nullptr) && (mynode->getRight()==nullptr))){
                if(mynode->getLeft()!=nullptr){ //if the node i'm removing has a left child
                    if(mynode->getParent()->getLeft()==mynode){ //if the node i'm removing WAS a left child
                        mynode->getParent()->getLeft() = mynode->getLeft(); 
                    }else{  //if the node i am removing was a right child
                        mynode->getParent()->getRight() = mynode->getLeft()
                    }
                }else{      //if the node i'm removing has a right child
                    if(mynode->getParent()->getLeft()==mynode){ 
                        mynode->getParent()->getLeft() = mynode->getRight(); 
                    }else{  
                        mynode->getParent()->getRight() = mynode->getRight()
                    }
                }
            }
       }
}; 

int main(){
    BST<int> myTree; 

    myTree.treeInsert(13); 
     
    myTree.treeInsert(2); 
    myTree.treeInsert(32); 
    myTree.treeInsert(40); 
    myTree.treeInsert(15);
    myTree.treeInsert(1); 

    cout << "In-order woods walk: "<<endl;
    myTree.inorderTreeWalkPrint(myTree.getRoot());

    cout <<endl<< "Pre-order woods walk: "<<endl;
    myTree.preOrder(myTree.getRoot()); 
    
    cout <<endl<< "Post-order woods walk: "<<endl;
    myTree.postOrder(myTree.getRoot());

    cout << endl <<endl<< "My tree's root: "<< myTree.getRoot()->getKey()<<endl;
    cout << "My tree's min: "<<(myTree.getMin(myTree.getRoot()))->getKey() << endl; 
    cout << "My tree's max: "<<(myTree.getMax(myTree.getRoot()))->getKey()<<endl; 
}