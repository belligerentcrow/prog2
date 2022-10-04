/*
Scrivere un programma che inizializza solo i primi due elementi di un vettore di 4 e
visualizzi il valore degli elementi non assegnati.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; 

void stampaSchifezze(int * vett){
    for(int i = 0; i < 4; i++){
        cout << vett[i] << "\t"; 
    }
}

void inizializza(int * vett){
    for(int i = 0; i<2; i++){
        vett[i] = 1 + rand()%(10); 
    }
    stampaSchifezze(vett); 
}

int main(){
    srand(time(0)); 
    int vettore[4]; 
    inizializza(vettore); 

    return 0; 
}