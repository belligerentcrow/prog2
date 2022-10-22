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
}; 

int main(){
    BST<int> myTree; 

    myTree.treeInsert(13); 
    //cout << (myTree.getRoot())->getKey()<<endl; 
    myTree.treeInsert(2); 
    myTree.treeInsert(32); 
    myTree.treeInsert(40); 
    myTree.treeInsert(15);
    myTree.treeInsert(1); 

    myTree.inorderTreeWalkPrint(myTree.getRoot()); 
    cout << "My tree's min: "<<(myTree.getMin(myTree.getRoot()))->getKey() << "\t and my tree's max: "<<(myTree.getMax(myTree.getRoot()))->getKey()<<endl; 
}