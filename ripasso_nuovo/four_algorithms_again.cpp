#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <cmath>
#include <ctime>

using namespace std; 

template <typename T>
void InsertionSort(T arr[], int n){
    cout <<endl<< "----- Sorting algorithm: Insertion Sort -----"<<endl; 
    T aux; 
    for(int i = 1; i < n; i++){
        aux = arr[i];
        int j = i-1; 
        while((j>=0)&&(arr[j]>aux)){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = aux; 
    }
}

template <typename T>
void SelectionSort(T arr[], int n){
    cout <<endl<< "----- Sorting algorithm: Selection Sort -----"<<endl; 
    T aux; 
    int posmin; 
    for(int i = 0; i < n-1; i++){
        posmin = i; 
        int j = i+1; 
        while(j<n){
            if(arr[j]<arr[posmin]){
                posmin = j; 
            }
            j++; 
        }

        aux = arr[i]; 
        arr[i] = arr[posmin]; 
        arr[posmin] = aux; 

    }

}

template <typename T>
void BubbleSortFlag(T arr[], int n){
    cout <<endl<< "----- Sorting algorithm: Bubblesort -----"<<endl; 

    bool toSwitch = true; 
    T aux; 
    while(toSwitch){
        toSwitch = false; 
        for(int i = 0; i <= n-2; i++){
            if(arr[i]>arr[i+1]){
                toSwitch = true; 
                aux = arr[i];
                arr[i] = arr[i+1]; 
                arr[i+1] = aux; 
            }
        }
    }
}

template <typename T>
void Merge(T arr[], int low, int half, int high){
    int n1 = half - low +1; 
    int n2 = high - half;
    T Left[n1+2]; 
    T Right[n2+2]; 
    for(int i = 0; i <= n1; i++){
        Left[i] = arr[low+i-1]; 
    }
    for(int j = 0; j <= n2; j++){
        Right[j] = arr[half+j]; 
    }
    Left[n1+1] = INT_MAX;
    Right[n2+1] = INT_MAX; 

    int i = 0; 
    int j = 0; 
    for(int k = low; k < high; k++){
        if(Left[i]<=Right[j]){
            arr[k] = Left[i]; 
            i++; 
        }else{
            arr[k] = Right[j]; 
            j++; 
        }
    }
}

template <typename T>
void Mergesort(T arr[], int low, int high){
    if(low < high){
        int half = floor((high+low)/2); 
        Mergesort(arr, low, half); 
        Mergesort(arr, half+1, high); 
        Merge(arr, low, half, high); 
    }
}

template <typename T>
void printArray(T arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << "\t"; 
        if(((i!=0)&&(i%10==0))){ 
            cout << endl; 
        }
    }
}

template <typename T>
void scrambleArray(T arr[], int NUM){
    cout << endl << "+++++ Scrambling ++++"<<endl; 
    for(int i = 0; i < NUM; i++){
        arr[i] = (rand()%NUM)+1; 
    }
}

int main(){
    int N = 50; 
    srand(time(NULL)); 
    int myArray[N]; 

    scrambleArray(myArray, N); 
    printArray(myArray, N); 

    //InsertionSort(myArray, N);
    //printArray(myArray, N); 

    //scrambleArray(myArray, N); 

    //SelectionSort(myArray, N); 
    //printArray(myArray, N); 

    //scrambleArray(myArray, N);

    BubbleSortFlag(myArray, N); 
    printArray(myArray, N); 

    scrambleArray(myArray, N); 

    Mergesort(myArray, 0, N); 
    printArray(myArray, N); 


}