/* Definire una classe Rettangolo con attributi basi e altezza privati ma accessibili
tramite getters e setters, 
con construttore che prende in input base e altezza oppure imposta due valori
funzioni membro pubbliche per calcolo di area perimetro e diagonale
funzione booleana per verificare che sia un quadrato
instanziare in main alcuni rettangoli per testare
definire costruttore e qualificatore Const*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>
using namespace std; 

class Rectangle{
    private:
        double base; 
        double height; 
    public: 
        double getHeight(){
            return this->height; 
        }
        double getBase(){
            return this->base; 
        }
        void setHeight(double h){
            this->height = h; 
        }
        void setBase(double b){
            this->base = b; 
        }

        Rectangle(double b, double h){
            this->base = b; 
            this->height = h; 
        }
        Rectangle(){
             
            this->base = (rand()%100)+1;
            this->height = (rand()%100)+1;  
        }

        double area(){
            return (this->base*this->height); 
        }

        double perimeter(){
            return ((this->base*2)+(this->height*2)); 
        }

        double diagonal(){
            return sqrt(pow(this->base,2)+pow(this->height,2)); 
        }

        bool isItASquare(){
            if(this->getBase()==this->getHeight()){
                return true; 
            }else{
                return false; 
            }
        }
        
        void printRectangle(){
            cout <<"Base: "<< this->getBase()<< ", height: "<<this->getHeight()<< endl;
            cout <<"Area: "<< this->area()<<", perimeter: "<<this->perimeter()<< ", diagonal: "<<diagonal()<<endl; 
            if(isItASquare()){
                cout << "It's a square"<<endl; 
            }else{
                cout << "It's not a square"<<endl; 
            }
        }
};

int main(){
    srand(time(0));
    Rectangle A; 
    Rectangle B; 
    Rectangle C(50.0, 50.0); 

    A.printRectangle(); 
    B.printRectangle(); 
    C.printRectangle(); 
}