#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std; 

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

void printIndexFind(int indexx){
    if(indexx>=0){
            cout << "Your number was found in the array. Index: " <<indexx << "."<<endl<<endl; 
            }else{
                cout << "Your number is not inside the array."<<endl<<endl;
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

    bool validChoice1 = 0; 

    cout << "Insert a number between 1 and "<< arrSize <<": "; 
    while(!validChoice1){
        cin >> num; 
        if(num > 0 && num <(arrSize+1)){
            validChoice1 = true; 
        }else{
            cout << "Try again. "<<endl; 
        }
    }

    bool validChoice2 = 0; 
    short int algChoice = 0; 
    while(!validChoice2){
        cout << "which searching algorithm do you want to use?"<<endl; 

        cout << "1) Linear Search"<<endl; 
        cout << "2) Binary Search"<<endl; 

        cin >> algChoice; 

        if(algChoice < 1 || algChoice >=3){
            cout << "Enter a valid option. "<<endl;
        }else{
            validChoice2 =1; 
        }
    }
    switch(algChoice){
        case 1: 
            cout <<endl<< "Ricerca sequenziale was selected."<<endl<<endl; 
            printIndexFind(linSearch(myArrayNotOrdered, arrSize, num)); 
            break; 
        case 2: 
            cout <<endl<< "Binary Search was selected." <<endl<<endl; 
            printIndexFind(binarySearch(myArrayOrdered, 0, arrSize, num)); 
            break;
    }

}