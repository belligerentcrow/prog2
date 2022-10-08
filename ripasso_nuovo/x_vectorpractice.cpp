#include <iostream>
using namespace std; 

class myVector {
    int size; 
    double * elem; 
    public:
        myVector(int s) : size{s}, elem{new double[s]}{
            for(int i =0; i<s; ++i){
                elem[i] = i; 
            }
        }
        int getSize() const {
            return size; 
        }
        ~myVector(){
            delete [] elem; 
        }
};

int main(){

}