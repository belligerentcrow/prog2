#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
using namespace std; 

template <typename T>
void printArray(T myArr, int dim){
    for(short int i = 0; i < dim; i++){
        cout << myArr[i] << " "; 
    }
    cout << endl; 
}

template <typename T>
void merge(T A[], int p, int q, int r){
    cout << "MERGE"<<endl; 
    int n1 = q - p + 1; 
    int n2 = r - q; 
    T * Left = new T[n1+1]; 
    T * Right = new T[n2+1]; 
    //int i, j; 
    for(int i = 0; i < n1; i++){ //i = 1
        Left[i] = A[p + i];     //i +1
    }
    for(int j = 0; j < n2; j++){ //j = 1
        Right[j] = A[q+1+j];    //q+j
    }
    Left[n1] = INT_MAX; //n1+1
    Right[n2] = INT_MAX;  //n2+1
    int i = 0, j = 0, k=p;   // i = 1, j=1; 

    for(k = p; k <= r; k++){ // <
        if(Left[i]<Right[j]){ //<=
            A[k] = Left[i]; 
            i++; 
        }else{
            A[k] = Right[j]; 
            j++; 
        }
    }
    delete[] Left;
    delete[] Right;
}

template <typename T>
void mergeSort(T A[], int p, int r){
    cout << "MERGESORT"<<endl;
    printArray(A, r-p); 
    if(p < r){
        int q = (p+r)/2; 
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r); 
    }
}



int main(){
    int dimArr = 20; 
    srand(time(0)); 
    int myArray[dimArr]; 
    for(int i = 0; i < 20; i++){
        myArray[i] = (rand()%(dimArr))+1; 
    } 
    printArray(myArray, dimArr);
    
    mergeSort(myArray, 0, dimArr); 

    printArray(myArray, dimArr); 
    cout << "FINE"<<endl; 

    // CORREGGERE PRIMO ELEMENTO ARRAY CHE ARRIVA IN BLOCCO MEMORIA NON CONSENTITO
}