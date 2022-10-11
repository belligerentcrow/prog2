#include <iostream>
using namespace std; 

template <typename T>
void swap(T a, T b){
    T temp = a; 
    a = b; 
    b = temp; 
}


class Rectangle{
    int base; 
    int height; 
    public:
    int getBase(){
        return this->base; 
    }
    int getHeight(){
        return this->height;
    }
    Rectangle(int b, int h){
        this->base = b; 
        this->height = h; 
    }
    Rectangle(){
        this->base = (rand()%100)+1; 
        this->height = (rand()%100)+1; 
    }

    void setBase(int b){
        this->base = b; 
    }
    
    void setHeight(int h){
        this->height = h; 
    }

    int getArea(){
        return (getBase()*getHeight()); 
    }

    friend
    ostream & operator<< (ostream & out, const Rectangle & r);
};

class Node {
    private: 
        Rectangle value; 
        Node * left; 
        Node * right; 
        Node * parent; 
    public:
        Node * getLeft(){
            return left; 
        }
        Node * getRight(){
            return right; 
        }
        Node(): value(){

        }
        Node(int b, int h): value(b, h){
            
        }

        void modifyValue(Rectangle re){
            this->value = re; 
        }

        void modifyValue(bool ch, int i){
            switch(ch){
                case 0:
                    value.setBase(i); 
            }
        }

};

class Heap{
    private:
        Rectangle * heapArray; 
        int lenght; 
        int heapsize; 
    public: 
        
        int left(int i){
            return 2*i; 
        }
        int right(int i){
            return 2*i+1;
        }
        int parent(int i){
            return i/2; 
        }
        void increaseKey(int i, int b, int h){
            if (b < heapArray[i].getBase() && h < heapArray[i].getHeight()){
                cout << "key too small"<<endl; 
                break; 
            }else{
            heapArray[i].setBase(b); 
            heapArray[i].setHeight(h); 
            while((i>1)&&((heapArray[parent(i)].getArea())<(heapArray[i].getArea()))){
                swap(heapArray[i], heapArray[parent(i)]); 
                i = parent(i); 
            }
            }
        }

        void insert(Rectangle r){

        }

        int getLenght(){
            return this->lenght; 
        }
        int getHeapsize(){
            return this->heapsize; 
        }
        

};

ostream & operator<< (ostream & out, const Rectangle & r){
        out << "Base: " << r.getBase()<<endl; 
        out << "Height: "<<r.getHeight()<<endl; 
        out <<" Area: "<<r.getArea()<<endl; 
        return out; 
        
    }

template <typename T>
void printArray(T arr[], int n){
    cout << "Printing array . . ."<<endl; 
    if(T.typename()==Rectangle.typename()){
        for(int i = 0; i < n; i++){
            cout <<i+1<<") "<< arr[i]<<endl; 
        }
    }else{
    for(int i = 0; i < n; i++){
        cout <<i+1<<") "<< arr[i]<<" "; 
    }
    }
}

template <typename T>
void bubbleSort(T array[], int n){

}

template <typename T>
void insertSort(T array[], int n){

}

template <typename T>
void minHeapify(T arr[], int i){
    left = arr[i*2]; 
    right = arr[i*2+1]; 
    if (left <= )


}

template <typename T>
void buildMaxHeap(T arr[]){

}

template <typename T>
void heapSort(T array[], int n){

}

int main(){
    srand(time(0)); 

}