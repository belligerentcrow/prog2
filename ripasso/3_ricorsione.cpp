
//this lets you insert a number and choose whether you want to calculate its factorial or its Collatz sequence (Cfr: Collatz Conjecture). 

#include <iostream>
#include <cmath>
using namespace std; 

int fattoriale(int n){ // n! --> (n * n-1 * n-2 * ... * 2 * 1) 
    if (n==0){
        return 1; 
    } else {
        return n * fattoriale(n-1);  
    }
}

int collatz(int numb){ //collatz conjecture. if even, num/2. if odd, 3*n +1. it has to reach 1, sooner or later. 
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

bool isItPrime(int num){  //checks if prime.   
    for(int i = 2; i <= sqrt(num); i++){
        if(num%i==0){
            return false; 
        }
    }
    return true; 
}

int getValidNumber(int num){
    bool validNum = 0; 
    int dive = 1;
        while(validNum==0){
            cout << "Insert a number lesser than "<< num <<": "; 
            cin >> dive; 
                if(dive >0 && dive <= num){
                    validNum = 1; 
                }
        } 
    return dive; 
}

bool divByNumber(int num, bool inChoice){ //the choice thing is in case i wanna use this anywhere else. which is kinda dumb since the % operator exists 

    int div = getValidNumber(num);  

        if(num%div==0){
                    if(inChoice){cout << num << " is dividable by "<< div <<"."<<endl; }
                    return true; 
                } else {
                    if(inChoice){cout << num << " is not dividable by "<< div <<"."<<endl;}
                    return false; 
                }
}

int fibonacci(int num){
   if(num < 0){ 
    return 0; 
   }

   if(num == 0||num ==1){
    return num; 
   } 

   if (num >=2){
    return fibonacci(num-1) + fibonacci(num-2); 
   }
} 

int mcd(int num1, int numb2){
    if(numb2 == 0){
        return num1; 
    }
    if(num1 == numb2){
        return num1; 
    }else{
        return mcd(numb2, num1%numb2); 
    }

}

int sumOfFirsts(int num){
    if(num <= 1){
        return 1; 
    }
    if(num > 1){
        return num + sumOfFirsts(num-1);
    }
}


int main(){
    int num = -1; 
    
    while(num < 0){
        cout << "Insert a number greater than 0."<<endl;
        cin >> num;
        if(num == 42){
            cout << "That's the answer!!!"<<endl; 
        }else if(num == 69){
            cout << "nice"<<endl; 
        }else if(num == 420){
            cout << "blaze it"<<endl; 
        }
    } 

    short int choice = -1;
    bool validChoice = 0;  

    while(validChoice==0){
        cout << "1) Evaluate "<<num<< "'s factorial number."<<endl;
        cout << "2) Evaluate "<<num<<"'s Collatz sequence."<<endl; 
        cout << "3) Evaluate if "<<num<< " is a prime number."<<endl;
        cout << "4) Check if "<< num <<" can be divided by a number of your choosing."<<endl; 
        cout << "5) Print the "<< num << "st/nd/rd/th step/s of the Fibonacci sequence."<<endl; 
        cout << "6) Evaluate the GCD between "<< num << " and a number of your choosing."<<endl; 
        cout << "7) Evaluate the sum of the first "<< num <<" numbers."<<endl; 

        cin >> choice;
        int num2 = 0; 

        switch(choice){
            case 1:
                cout << "Its factorial is " << fattoriale(num) <<"."<<endl;
                validChoice = 1; 
                break; 
            case 2: 
                cout << "Evaluating its Collatz sequence. . ."<<endl; 
                cout << collatz(num);
                validChoice =1;  
                break; 
            case 3: 
                    if(isItPrime(num)){
                        cout << num << " is a prime number."<<endl; 
                    }else{
                        cout << num << " is not a prime number."<<endl; 
                    }
                validChoice = 1; 
                break; 
            case 4: 
                
                divByNumber(num, 1); 
                
                validChoice = 1; 
                break; 
            case 5: 
                cout << "Prova numero 3"<<endl;
                
                cout << fibonacci(num)<< endl;
                
                validChoice = 1; 
                break;  
            case 6: 
                num2 = getValidNumber(num); 
                cout << "The GCD between "<< num << " and " << num2 << " is " << mcd(num, num2)<<endl; 
                validChoice = 1; 
                break; 
            case 7:
                cout << sumOfFirsts(num); 
                validChoice = 1; 
                break;
            case 69:
                cout <<endl<< "Nice, but try again"<<endl; 
                break; 
            case 420:
                cout <<endl << "Blaze it, but try again"<<endl; 
                break; 
            default: 
                cout <<endl << "Please insert a valid number."<<endl<<endl;

        }

    }

}