

//implementare il resto delle funzioni di ListaSemplice + controllare il distruttore e l'errore che da'
//ma prima implementare la ricerca

#include <iostream>
using namespace std; 

class Nodo{
public:
    int valore; //valore che contiene
    Nodo * succ; //il successore
};

class ListaSemplice{
private: 
    Nodo * testa; 
public:
    ListaSemplice(){ testa = nullptr; } //se la inizializziamo da solo crea una lista vuota
    
    // bisogna implementare pure distruttore, mi da' costruttore non valido 

    /* ~ListaSemplce(){
        Nodo * iter = this->testa; 
        while(iter!= nullptr){
            Nodo * tmp = iter->succ; 
            delete iter; 
            iter = tmp; 
        }
    } */ 
    Nodo * getTesta(){ return testa; }

    //inserimento in testa (prende solo valore da inserire in testa)
    void inserici(int val); 
    void inserisci(Nodo * precedente, int val);
    void inserisciInCoda(int val); 

    Nodo * ricerca(int val); 
    void rimuovi(int val); 

    friend 
        ostream& operator << (ostream & out, const ListaSemplice & ls);
};

ostream& operator<<(ostream & out, const ListaSemplice & ls){
    Nodo * iter = ls.testa; 
   while(iter!=nullptr){ //utilizzato spesso: modo veloce per iterare elementi liste
        out << iter->valore << " --> "; 
        iter = iter->succ; 
   } 
   cout << "NULL"; 
   return out; 
}

void ListaSemplice::inserici(int val){
    Nodo * nuovo = new Nodo; 
    nuovo->valore = val; 
    nuovo->succ = this->testa; 
    this->testa = nuovo; 
}

int main(){
    ListaSemplice lista; 
    lista.inserici(20); 
    lista.inserici(10);
    lista.inserici(5);
    lista.inserici(5);
    lista.inserici(5);
    lista.inserici(5);
    lista.inserici(5);
    lista.inserici(3);

    cout << lista; 
    return 0;  
}