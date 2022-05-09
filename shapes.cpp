// vedi slides per UML 
#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
using namespace std; 

#define N 20

enum color {red, green, blue}; 

class Shape {
protected:
    color Color = red; 
public: 
    Shape(color _c){
        this->Color = _c; 
    };
    
    string getColor(){
        switch(Color){
            case 0:
                return "red"; 
                break; 
            case 1:
                return "green"; 
                break; 
            case 2: 
                return "blue"; 
                break; 
        }
    }
    void setColor(color newC){
        Color = newC; 
    }
    void print(const char *); 
    virtual double getArea() = 0; 
};

class Rectangle : public Shape{
private: 
    double height = 1; 
    double width = 1; 
public:
    Rectangle(double _h, double _w) : Shape(red){
        this->height = _h; 
        this->width = _w; 
    }
    Rectangle(double _h, double _w, color _c) : Shape(_c){
        this->height = _h; 
        this->width = _w; 
        this->Color = _c; 
    }
    
    double getHeight(){
        return height; 
    }
    void setHeight(double h){
        height = h; 
    }
    double getWidth(){
        return width; 
    }
    void setWidth(double w){
        width = w; 
    }
    bool isASquare(){
        if(height == width){
            return true; 
        } else{
            return false; 
        }
    }
    double getArea(){
        return ((height * width)/2);
        }
};

class Circle : public Shape {
private:
    double radius = 1; 
    double xc = 0; 
    double yc = 0; 
public:
    Circle(double _r, double _xc, double _yc): Shape(blue){
        this->radius = _r; 
        this->xc = _xc; 
        this->yc = _yc; 
    }
    Circle(double _r, double _xc, double _yc, color _col) : Shape(_col){
        this->radius = _r; 
        this->xc = _xc; 
        this->yc = _yc; 
        this->Color = _col; 
    }
    double getXc(){
        return xc; 
    }
    double getYc(){
        return yc; 
    }
    void setXc(double newxc){
        xc = newxc; 
    }
    void setYc(double newyc){
        yc = newyc; 
    }
    double getRadius(){
        return radius; 
    }
    void setRadius(double rad){
        radius = rad; 
    }
    double getCircumference(){
        return (2*3.14*radius); 
    }
    bool isGoniometric(){
        if((radius == 1)&&(xc == 0)&&(yc==0)){
            return true; 
        }else{
            return false; 
        }
    }
    double getArea(){
        return (3.14*(radius*radius)); 
    }
};

class Triangle : public Shape{
private: 
    double base = 1; 
    double height = 1; 
public:
    Triangle(double _b, double _h) : Shape(green){
        this->base = _b; 
        this-> height = _h; 
    }
    Triangle(double _b, double _h, color _col) : Shape(_col){
        this->base = _b; 
        this->height = _h; 
        this->Color = _col; 
    }
    double getHeight(){
        return height; 
    }
    double getBase(){
        return base; 
    }
    void setHeight(double newh){
        height = newh; 
    }
    void setBase(double newb){
        base = newb; 
    }
    double getArea(){
        return (double)((base*height)/2); 
    }
};

void Shape::print(const char * myp){
        string myshape; 
        
        if(myp == typeid(Rectangle).name()){
            myshape = "Rectangle";
        }else if(myp == typeid(Circle).name()){
            myshape = "Circle"; 
        }else {
            myshape = "Triangle";
        }
        cout << "This " << myshape <<" is "<< getColor() << " and has an area of "<< getArea()<<endl; 
         
    }

int main(){
    Shape * array[N];
    srand(time(0));
    for(short i = 0; i < N; i++){
        short rando = rand()%3; 
        switch(rando){
            case 0:
                array[i] = new Rectangle((rand()%100+1)*1.0,(rand()%100+1)*1.0);
                break; 
            case 1:
                array[i] = new Circle((rand()%100+1)*1.0,(rand()%100+1)*1.0,(rand()%100+1)*1.0);
                break; 
            case 2: 
                array[i] = new Triangle((rand()%100+1)*1.0,(rand()%100+1)*1.0);
                break; 
            
        }
    }
    double middle = 0.0;
    for(short i = 0; i < N; i++){
        
        array[i]->print(typeid(*array[i]).name()); 
        middle += array[i]->getArea(); 
    }

    cout << endl <<"L'area media delle figure inserite e' "<< (middle / N) <<endl; 

    
}