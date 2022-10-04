/*
Scrivere una funzione di conversione che riceva come parametro una stringa
rappresentante una data in formato gg/mm/aa e la restituisca nel formato testuale, es:
17/11/91 --> 17 novembre 1991
*/

#include <iostream>
#include <sstream>
using namespace std; 

void stampa(string datafin){
    cout << "Oggi è... "<<datafin<<"."<<endl; 
}

string conversione(string datacode){
    string dataconv; 
    //day
    
    dataconv += datacode[0]; 
    dataconv += datacode[1]; 
    

    //month
    stringstream ss; 
    if(datacode[3]!=0){
     ss << datacode[3]; 
    }
    ss << datacode[4]; 
    int month; 
    ss >> month; 
    switch(month){
        case 1:
            dataconv += " gennaio "; 
            break; 
        case 2: 
            dataconv += " febbraio "; 
            break; 
        case 3:
            dataconv += " marzo "; 
            break;
        case 4:
            dataconv += " aprile "; 
            break;  
        case 5:
            dataconv += " maggio "; 
            break; 
        case 6:
            dataconv += " giugno "; 
            break; 
        case 7:
            dataconv += " luglio "; 
            break; 
        case 8:
            dataconv += " agosto "; 
            break;
        case 9:
            dataconv += " settembre "; 
            break; 
        case 10:
            dataconv += " ottobre "; 
            break; 
        case 11:
            dataconv += " novembre "; 
            break;
        case 12:
            dataconv += " dicembre "; 
            break;  
    }

    //year
    if(datacode[6]=='0'||datacode[6]=='1'||datacode[6]=='2'){   //check decade
        dataconv += "20"; 
    }else{
        dataconv += "19";
    }
    dataconv += datacode[6]; 
    dataconv += datacode[7]; 
    stampa(dataconv); 
    return dataconv; 
} 

int main(){

string data; 
cout << "Immetti una data in formato \"gg/mm/aa\" "<<endl; 
cin >> data; 
conversione(data); 

return 0; 
}