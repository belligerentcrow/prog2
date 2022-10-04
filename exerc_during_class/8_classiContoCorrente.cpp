#include <iostream>
using namespace std; 

class ContoCorrente{
private:
    int saldo = 100000; 
public:
    int const & getSaldoBuona()const{return saldo;} //la prima evita che ci siano modifiche dall'esterno, che la reference ritornata sia di tipo costante
                                            //la seconda dice che la funzione sia costante, ovvero non può modificare dati 
    int & getSaldo(){return saldo;}
    void printSaldo(){
        cout << "Il tuo saldo è: \t"<< saldo <<endl; 
        if(saldo < 0){
            cout << "Attenzione il conto è in passivo"<<endl; 
        }
    }
};

int main(){

ContoCorrente A, B; 
A.printSaldo(); 
int s = A.getSaldo(); 
cout << "saldo: "<<s<<endl; 

A.getSaldo() = -5000; 
A.printSaldo(); 
cout << endl; 
//B.setSaldoBuona() = -50000;

return 0; 

}