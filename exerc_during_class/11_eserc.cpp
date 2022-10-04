//problema del diamante

#include <iostream>
using namespace std; 

class A {
public: 
    int x = 5; 
    void meth() { //non necessariamente virtual
        cout << "A::meth()" << endl;
    }
}; 

class B : public A {
public: 
    
    void meth() {
        cout << "B::meth()" << endl; // se mettessi classe virtual e commentassi questa riga, e scrivessi d.B::meth(); nel main, il compilatore eseguirebbe il metodo di A (A::meth(); )
    } // ridefinisco metodo meth() in B
}; 


class C : public A {
public: 
    void meth() {
        cout << "C::meth()" << endl;
    } // ridefinisco metodo meth() in C
}; 

class D : public B, public C{

};

int main(){

    D d; 
    //d.meth(); //compilazione fallita: metodo ambiguo, 3 candidati possibili: A B C 
    //cout << d.x << endl; //compilazione fallita: metodo ambiguo, 2 candidati possibili, dalle due ereditarietà di percorso B e C 
    d.B::meth(); 
    d.C::meth(); 
    return 0; 
    
}