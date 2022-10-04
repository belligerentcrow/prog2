#include <iostream>
using namespace std;

class Nodo{
public:
    int valore;
    Nodo* succ;
};


class ListaSemplice{
public:
    ListaSemplice(){testa=nullptr;}
    ~ListaSemplice();
    Nodo* getTesta(){return testa;}
    // inserimento in testa
    void inserisci(int val);
    // inserimento dopo un nodo esistente
    void inserisci(Nodo* precedente, int val);
    void inserisciInCoda(int val);
    Nodo* ricerca(int val);
    void rimuovi(int val);

    friend
    ostream& operator<<(ostream& out, const ListaSemplice& ls);
private:
    Nodo* testa;

};

//  testa -> | 5 | -> | 6 | -> nullptr
//                      ^
//                     iter
ListaSemplice::~ListaSemplice(){
    Nodo* iter = this->testa;
    while(iter!=nullptr){
        Nodo* tmp = iter->succ;
        delete iter;
        iter = tmp;
    }
}

ostream& operator<<(ostream& out, const ListaSemplice& ls){
    Nodo* iter = ls.testa;
    while(iter!=nullptr){
        out << iter->valore << " --> ";
        iter = iter->succ;
    }
    cout << "NULL" << endl;
    return out;
}


void ListaSemplice::inserisci(int val){
    Nodo* nuovo = new Nodo;
    nuovo->valore = val;
    nuovo->succ = this->testa;
    this->testa = nuovo;
}


int main(){
    ListaSemplice lista;

    lista.inserisci(20);
    lista.inserisci(10);
    lista.inserisci(5);

    cout << lista;
    return 0;
}
