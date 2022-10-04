#include <iostream>
using namespace std; 

enum Colore {ROSSO, GIALLO, VERDE, BLU}; // !!!!!!! NUOVA COSA

class Cerchio {
    double raggio; 
    Colore col; 
public:
    
    Cerchio(){ raggio = 1; col = ROSSO; cout << "constr default"<<endl; };
    Cerchio(double r, Colore c): raggio(r){ cout << "constr 2"<<endl; };
    Cerchio(double r) : Cerchio(r, ROSSO) {cout << "constr 3"<<endl;}; //costruttore con delega

    double circonferenza() const{ return 2*raggio*3.14; }
    double getRaggio() const { return raggio; }
    double areaCerchio(Cerchio); 
    double area(Cerchio&); 
};

//bisogna porre dei limiti affinchè non siano violati da eventuali programmatori successivi i limiti della classe superiore

/*class SubCerchio : public Cerchio{
    public:
        double circonferenza(){this.raggio = 0; return 100; }
};  */

//top level function: fuori dalla classe
double areaCerchio(Cerchio c){
    return c.getRaggio()*c.getRaggio()*3.14; 
}
double area(Cerchio& c){
    cout << "area() senza const"<<endl; 
    return c.getRaggio()*c.getRaggio()*3.14;
}
double area(const Cerchio& c){
    cout << "area() con const"<<endl; 
    return c.getRaggio()*c.getRaggio()*3.14;
}
//perché il secondo funziona se inseriamo un valore numerico ad esempio area(2.3)? 
//reference che è una alias di un oggetto che non si riferisce a nessun oggetto. ?? 
//Il secondo metodo è uguale, solo che nella firma della funzione specifichiamo che sia impossibile modificare gli
//attributi della istanza c all'interno del corpo del metodo. Non posso modificare l'oggetto a cui si riferisce c.
//Il compilatore non permette di fare un cast implicito nel primo caso, ma lo permette nel secondo.

int main(){

    
    //chiamare costruttore tramite functional form
    //un po' pericoloso -> ricordarsi di mettere lo spazio, altrimenti viene interpretata come una funzione 
    //di tipo Cerchio 
    Cerchio c1 (10.0);      // functional form
    Cerchio c2 = 20.0;      // assignment initialization
    Cerchio c3{30.0};       // uniform initialization
    Cerchio c4 = {40.0};    // sempre assignment init. ma in altra forma

    Cerchio cc1; 
    Cerchio cc2;
    Cerchio cc3{}; 
    
    cout << "Circonferenza cc1:"<<cc1.circonferenza()<<endl; 
    cout << "Circonferenza cc2:"<<cc2.circonferenza()<<endl; 
    cout << "Circonferenza cc3:"<<cc3.circonferenza()<<endl; 

    cout << endl << "Calcolo di aree: " << endl; 

    Cerchio c_d(2.4); 
    Cerchio c_f(3.1f); 
    Cerchio c_i(10); 

    cout << "metodo areaCerchio: "<<endl; 
    cout << "Area di c_d: "<< areaCerchio(c_d)<<endl; 
    cout << "Area: \t"<<areaCerchio(2.3)<<endl; 

    cout << "metodo area: " <<endl; 
    cout << "Area: \t"<<area(2.3)<<endl; //non funziona col primo metodo non const perché ha bisogno di un oggetto già creato, si aspetta una reference
    cout << "Area: \t"<<area(c_d)<<endl; //chiama con successoil metodo non const!
    //proviamo facendo overloading della funzione mettendo "const Cerchio &c" al posto di "Cerchio &c"
    return 0; 
}