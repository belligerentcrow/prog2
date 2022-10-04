#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std; 

//Search Algorithms
int linSearch(int vect[], int dim, int key){
    for(int i = 0; i < dim; i++){
        if(vect[i]==key){
            return i; 
        }
    }
    return -1; 
}

int binarySearch(int vect[], int lowest, int highest, int key){
    int centerIndex; 
    int centerValue; 
    while(lowest<=highest){
        centerIndex = (lowest + highest)/2; //index of central element
        centerValue = vect[centerIndex]; 
        if(key == centerValue){
            return centerIndex; 
        }else if(key>centerValue){
            lowest = centerValue+1; 
        }else{
            highest = centerValue-1; 
        }
    }
    return -1; 
}

//Sorting Algorithms
void insertionSort(int vect[], int num){
    int temp; 
    for(short int i = 1; i < num; i++){
        temp = vect[i]; 
        int j = i-1; 
        while((j>=0)&&(vect[j]>temp)){
            vect[j+1] = vect[j]; 
            j--; 
        }
        vect[j+1] = temp; 
    }
    cout << endl<< "The array was ordered."<<endl<<endl; 
}

void selectionSort(int vect[], int num){
    int temp; 
    int minIndex; 
    for(short int i = 0; i<num-1; i++){
        minIndex = i; 
        short int j = i+1; 
        while(j < num){
            if(vect[j]<vect[minIndex]){
                minIndex = j; 
            }
            j++;
        }
        temp = vect[i]; 
        vect[i] = vect[minIndex]; 
        vect[minIndex] = temp; 
    }
}

void printIndexFind(int indexx){
    if(indexx>=0){
            cout << "Your number was found in the array. Index: " <<indexx << "."<<endl<<endl; 
            }else{
                cout << "Your number is not inside the array."<<endl<<endl;
            }
}

void printArray(int arr[], int dim){
    cout << "Printing the array. . ." <<endl;  
    for(int i = 0; i < dim; i++){
        cout << arr[i]<< " ";
    }
}

int main(){
    srand(time(0)); 
    int arrSize = 20; 

    int myArrayNotOrdered[arrSize]; 
    int myArrayOrdered[arrSize];

    int num = 0; 

    for(int i = 0; i < arrSize; i++){
        myArrayNotOrdered[i] = (rand()%arrSize)+1;
        myArrayOrdered[i] = i; 
    }
    
    bool validChoice2 = 0; //checking the algorithm choice
    short int algChoice = 0; 
    while(!validChoice2){
        cout << "which searching or sorting algorithm do you want to use?"<<endl; 

        cout << "1) Linear Search"<<endl; 
        cout << "2) Binary Search"<<endl; 
        cout << "3) Insertion Sort"<<endl; 
        cout << "4) Selection Sort"<<endl; 

        cin >> algChoice; 

        if(algChoice < 1 || algChoice >=5){
            cout << "Enter a valid option. "<<endl;
        }else{
            validChoice2 =1; 
        }
    }
    bool validChoice1 = 0; //checking the searching number choice
    if((algChoice==1) || (algChoice==2)){
        cout << "Insert a number between 1 and "<< arrSize <<": "; 
        while(!validChoice1){
            cin >> num; 
            if(num > 0 && num <(arrSize+1)){
                validChoice1 = true; 
            }else{
                cout << "Try again. "<<endl; 
            }
        }
    }
    
    switch(algChoice){
        case 1: 
            cout <<endl<< "Linear Search was selected."<<endl<<endl; 
            printIndexFind(linSearch(myArrayNotOrdered, arrSize, num)); 
            break; 
        case 2: 
            cout <<endl<< "Binary Search was selected." <<endl<<endl; 
            printIndexFind(binarySearch(myArrayOrdered, 0, arrSize, num)); 
            break;
        case 3: 
            cout << endl << "Insertion sort was selected."<<endl<<endl;
            printArray(myArrayNotOrdered, arrSize);
            insertionSort(myArrayNotOrdered, arrSize); 
            printArray(myArrayNotOrdered, arrSize);
            break;  
        case 4: 
            cout << endl << "Selection sort was selected."<<endl<<endl; 
            printArray(myArrayNotOrdered, arrSize);
            selectionSort(myArrayNotOrdered, arrSize); 
            printArray(myArrayNotOrdered, arrSize);
            break; 
    }

}