/*
Scrivere un programma che legga una frase, sostituisca tutte le sequenze di uno o due
spazi con uno spazio singolo e visualizzi la frase risultante
*/

#include <iostream>

using namespace std; 

void stampa(string toprint){
    cout << toprint<<endl; 
}

void sostituzione(string mystr){
    string result; 
    for(int i = 0; i < mystr.length(); i++){
        if(!((mystr[i]==' ')&&(mystr[i+1]==' '))){
            result+=mystr[i]; 
        }
    }
   
    stampa(result); 
}

int main(){

string mystring;
cout << "Inserisci una frase "<<endl;  
getline(cin, mystring);  
sostituzione(mystring);
return 0; 
}