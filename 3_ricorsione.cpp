
//this lets you insert a number and choose whether you want to calculate its factorial or its Collatz sequence (Cfr: Collatz Conjecture). 

#include <iostream>
#include <cmath>
using namespace std; 

int fattoriale(int n){
    if (n==0){
        return 1; 
    } else {
        return n * fattoriale(n-1);  
    }
}

int collatz(int numb){
    if(numb == 1){
        cout << "Reached 1. "<<endl; 
        return 1; 
    } else if(numb%2==0){
        cout << numb << " --> "; 
        return collatz(numb/2); 
    }else {
        cout << numb << " --> "; 
        return collatz(numb*3+1);
    }
}

bool isItPrime(int num){                    // <-- make it recursive!
    for(int i = 2; i <= sqrt(num); i++){
        if(num%i==0){
            return false; 
        }
    }
    return true; 
}

int main(){
    int num = -1; 
    
    while(num < 0){
        cout << "Insert a number greater than 0."<<endl;
        cin >> num;
    } 

    short int choice = -1; 

    while(choice!=1 && choice !=2 && choice!=3){
        cout << "1) Evaluate "<<num<< "'s factorial number."<<endl;
        cout << "2) Evaluate "<<num<<"'s Collatz sequence."<<endl; 
        cout << "3) Evaluate if "<<num<< " is a prime number."<<endl; 
        cin >> choice;

        if(choice == 1){
            cout << "Its factorial is " << fattoriale(num) <<"."<<endl;
        }else if(choice == 2){
            cout << "Evaluating its Collatz sequence. . ."<<endl; 
            cout << collatz(num); 
        }else if(choice == 3){
            bool prime = isItPrime(num); 
            if(prime){
                cout << num << " is a prime number."<<endl; 
            }else{
                cout << num << " is not a prime number."<<endl; 
            }
        }else{
            cout <<endl << "Please insert a valid number."<<endl<<endl; 
        }
    }

}