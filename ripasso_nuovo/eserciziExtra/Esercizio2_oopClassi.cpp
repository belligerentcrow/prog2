/*Definire una classe Punto2D e utilizzarla per definire una classe Rettangolo
simile a quella precedente. La nuova classe Rettangolo dovrà:
- avere due attributi top_left e bottom_right di tipo Punto2D
- prevedere i metodi: 
    -contiene (Punto2D p): restituisce vero se p si trova dentro l'area del
    rettangolo chiamante
    -contiene (Rettangolo r): restituisce vero se r è contenuto nel rettangolo
    chiamante
- definire le classi Punto2D e Rettangolo in modo che sia possibile istanziare
due oggetti, (punto2d e rettangolo) nel seguente modo: 
    Punto2D = {10, 20}; 
    Rettangolo B({10, 20}, {50, 10})
Dove {10, 20} rappresenta un Punto2D di coordinate x=10, y=20
{50, 10} un Punto2D di coordinate x=50, y=10*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std; 

class Point2D{
    private:
        int x; 
        int y; 
    public:
        int getX(){
            return this->x; 
        } 
        int getY(){
            return this->y; 
        }
        void setX(int xxx){
            this->x = xxx; 
        }
        void setY(int yyy){
            this->y = yyy; 
        }

        Point2D(int one, int two){
            this->x = one; 
            this->y = two; 
        }
};

class Rectangle{
    private: 
        int base; 
        int height; 
        Point2D top_left; 
        Point2D bottom_right;
    public: 
        int getHeight(){
            return this->height; 
        }
        int getBase(){
            return this->base; 
        }
        void setHeight(int h){
            this->height = h; 
        }
        void setBase(int b){
            this->base = b; 
        }

        Rectangle(int x1, int y1, int x2, int y2): top_left(x1, y1), bottom_right(x2, y2) {
        this->base = (rand()%100)+1; 
        this->height = (rand()%100)+1; 
        }

        Rectangle(int x1, int y1, int x2, int y2, int b, int h): top_left(x1, y1), bottom_right(x2, y2) {
            this->base = b; 
            this->height = h; 
        }

        bool contains(Point2D p){
            if((p.getX()<=this->base)&&(p.getY()<=this->height)){
                return true; 
            }else{
                return false; 
            }
        }

        bool contains(Rectangle r){
            if((r.getBase()<=this->base)&&(r.getHeight()<=this->height)){
                return true; 
            }else{
            return false;
            } 
        }

};

int main(){
    srand(time(0)); 
    Rectangle A(10, 39, 19, 18); 
    Rectangle B(20, 39, 10, 40); 
    Rectangle C(20, 13, 89, 32, 18, 38); 

    cout << A.contains(B)<<endl; 
    cout << B.contains(C)<<endl; 
    cout << C.contains(A)<<endl; 

    Point2D pD(1000, 2000); 
    Point2D pE(10, 20); 
    cout << "point 1: "<<A.contains(pD)<<endl;
    cout << "point 2: "<<A.contains(pE)<<endl;  

}