#include <iostream>
using namespace std; 

class NoConstruct{
public:
    float f; char c; int i; 
    void printAll(){cout << f << " "<< c << " "<< i <<endl; }

};

class A{
public:
    int uno =1; 
    void printAll() const { //se non prende valori e non modifica è meglio dichiararla const
        cout << endl<<"Dati membro: "<<endl; 
        cout << uno<<endl;
        cout << due<<endl;
        cout << tre<<endl;
    }
    void setDataMember(short memb, int val){
      switch(memb){
        case 1:
            uno = val; 
            break; 
        case 2:
            due = val; 
            break; 
        case 3: 
          //  tre = val; 
            break; 
      }  
    };
    A(); 
    A(int, int); 
    A(int, int, int); 
private: 
    int due; 
    int const tre; 

};

A::A(): uno(), due(), tre(){

};

A::A(int un, int dos, int tres): uno(un), due(dos), tre(tres){}; //il tre dobbiamo mettere per forza in lista di inizializzazione perché è const, non possiamo riassegnare dopo 
A::A(int un, int dos): tre(){
    uno = un+un; 
    due = dos+dos+1; 
}; 

int main(){
    NoConstruct noc1{4.5};
    NoConstruct noc2{4.5, 'S'};
    NoConstruct noc3{4.5, 'S', 10};
    NoConstruct noc4{'X', 2, 2.0};
    noc4.printAll();

    A obj_A; 
    obj_A.printAll(); 

    obj_A.uno = 11; 
    //obj_a.due = 11;
    //obj_a.tre = 11;

    obj_A.setDataMember(2, 22); 
   obj_A.printAll(); 

    A obj_b{101, 102, 103}; 
    A obj_c{5,5}; 

    A a{1, 2,3}; //oggetto ordinario, istanza di una classe
    a.printAll(); 

    A* ptA = &a; //puntatore

    ptA->printAll(); 

    A& rA = a;   //reference: alias di a
    rA.setDataMember(1, 100); 
    rA.printAll(); 

    A* ptrA = new A(100, 200, 300); 
    ptrA->printAll(); 
    delete ptrA; 

    //array di oggetti di tipo A
    cout << endl<<endl; 
    A arrA[2];
    for(int i = 0; i < 2; i++){
        cout << "arrA["<< i << "]:"; 
        arrA[i].printAll(); 
        cout <<endl; 
    }

    A arrA2[2] = {A(10, 20, 30), A(2, 2)}; 
    for(int i = 0; i < 2; i++){
        cout << "arrA2["<< i << "]:"; 
        arrA2[i].printAll(); 
        cout <<endl; 
    }

    A* ptrArr3 = new A[2]; //dinamica, utilizzando costruttore di default
    ptrArr3[0].printAll(); 
    delete[] ptrArr3;

    A* ptrArr4 = new A[2] {A(30, 40, 50), A(1,1)};
    ptrArr4->printAll(); //primo elemento di ptrArr4
    (ptrArr4+1)->printAll(); 

    //deallocazione
    delete[] ptrArr3; 
    delete[] ptrArr4; 
    

    return 0; 
}