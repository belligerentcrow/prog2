/*

Dato un file contenente un elenco di utenti nel seguente formato 
ID;COGNOME;NOME;POPOLARITA 
ID;COGNOME;NOME;POPOLARITA 
... 
ID;COGNOME;NOME;POPOLARITA 
 
Dove COGNOME e NOME sono stringhe e POPOLARITA è un double, implementare almeno due algoritmi 
di ordinamento tra quelli visti a lezione. Inoltre, sfruttando le librerie standard, valutarne la complessità 
temporale stimando il tempo di esecuzione.

*/

//definire oggetto utente -> definire ordinamento -> poi ordinare

#include <iostream>
#include <fstream> //allows us to read, write, open files
#include <string>
#include <vector> 
#include <iterator>
#include <algorithm>

#define utentiTotali 2000
using namespace std; 

class Utente{
private: 
    string ID; 
    string cognome; 
    string nome; 
    double popolarita; 
public:
    Utente(){
        
    }; 
    Utente(string id1, string cogn1, string nom1, double pop){
        ID = id1;
        cognome = cogn1; 
        nome = nom1; 
        popolarita = pop; 

    }
    string getID(){
        return ID; 
    }
    string getcognome(){
        return cognome; 
    }
    string getnome(){
        return nome; 
    }
    double getpopo(){
        return popolarita; 
    }

    void printUser(){
   cout << endl<<endl<<"Specifiche utente: "<<endl; 
   cout << this->getID() << " "<< this->getcognome() << " "<<this->getnome() << " "<<this->getpopo()<<endl; 
}

};

/*
    void printUser(Utente user){
    cout << endl<<endl<<"Specifiche utente: "<<endl; 
    cout << user.getID() << " "<< user.getcognome() << " "<<user.getnome() << " "<<user.getpopo()<<endl; 
    }
*/
void riempireArray(ifstream & mylist, int number, Utente * utentiTot){
    string mystring;
    string id1;
    string cognome1; 
    string nome1; 
    string pop1; 
    short i = 0; 
    int nextPers = 0; 
    while(mylist){
        getline(mylist, mystring);
        short len = mystring.length(); 
       // cout << mystring <<endl;
       // cout << len<<endl; 
        

        vector<string> data{}; 
        char spaceDelimiter = ';'; 
        size_t pos = 0; 
        while ((pos = mystring.find(spaceDelimiter)) != string::npos) {
        data.push_back(mystring.substr(0, pos));
        mystring.erase(0, pos + 1);
    }   
        data.push_back(mystring.substr(0, EOF));
        mystring.erase(0, pos+1);
        // cout << data[0]<<data[1]<<data[2]<<data[3]; 
        id1 = data[0];
        cognome1 = data[1];
        nome1 = data[2];
        double pop1 = stod(data[3]); 

            utentiTot[nextPers] = Utente(id1, cognome1, nome1, pop1); 
            utentiTot[nextPers].printUser(); 
            if(utentiTot[nextPers].getID()!="1999")nextPers++;              //PROBLEMI QUI -- risolvere con file.is_open()
        }
        cout << "end funzione1"<<endl; 
}

Utente * algoritmo1_Bubble(Utente * listaUtenti, int n){
    Utente * nuovaLista =new Utente[utentiTotali];
    nuovaLista = listaUtenti; 
    Utente appoggio; 
    bool scambio; 
    scambio = true; 
    while(scambio){
        scambio = false;  
        for(unsigned i = 0; i<n-2; i++){
            if (nuovaLista[i].getpopo()>nuovaLista[i+1].getpopo()){
                appoggio = nuovaLista[i]; 
                cout << nuovaLista[i].getpopo()<<endl;
                nuovaLista[i] = nuovaLista[i+1]; 
                nuovaLista[i+1] = appoggio; 
                scambio = true; 
            }
        }
    }
    return nuovaLista;
}; 

int main(){
    ifstream lista; 

    Utente * utentiTot = new Utente[utentiTotali];

    lista.open("utenti.txt", ios::in);
    cout << "Algoritmo di ordinamento 1:"<<endl; 
    riempireArray(lista, utentiTotali, utentiTot); 

    cout <<endl<<endl; 

   cout << "Algoritmo di ordinamento 1: Bubblesort"<<endl; 
   Utente * listaOrdinata = algoritmo1_Bubble(utentiTot, utentiTotali);
   for(int i = 0; i<50; i++){
      cout << "Posto numero "<< i << ": "<<endl; 
        listaOrdinata[i].printUser(); 
   } 
 lista.close();

}