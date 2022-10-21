/*read data from a file, sort the data, 
then print it back in the console.
BONUS: write it, SORTED, in an empty file.*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std; 

#define INTNUM 200

class ID{
    private:
        string ID_string; 
        int key; 
    public:
        ID(){}
        ID(string str, int k): ID_string(str), key(k){}
        string getID(){
            return ID_string; 
        }
        int getKey(){
            return key;
        }
        
        //implementare comparazione tramite keys con metodi friends?
        friend 
        ostream & operator << (ostream & out, ID & ids); 

        friend 
        istream & operator >>(istream & in, ID & ids); 
};

void splitString(string str, string content[2]){
    char delim = '-'; 
    string token; 
    stringstream ss(str); 
    int i = 0; 
    while(getline(ss, token, delim)){
        content[i]=token;
        i++; 
        if(i==2){
            break;
        }
    }
}

int loadStrings(const string filename, ID idsArray[]){
    ifstream file; 
    string line; 
    string buffer[2]; 
    file.open(filename); 
    int num = 0; 
    
    if(file.is_open()){
        while(getline(file, line)){
            splitString(line, buffer); 
            ID tempID; 
            tempID = ID(buffer[0], stoi(buffer[1]));
            idsArray[num] = tempID; 
            num++; 
        }
        file.close(); 
    }else{
        cout << "Can't open file"<<endl; 
    }
    return num; 
}

void printIDs(ID ids[], int n, int maxval=10){
    cout << "Array content: "<<endl; 
    if(n>maxval){
        for(int i = 0; i < maxval/2; i++){
            cout << ids[i]; 
        }
        cout<< " ... "<<endl; 
        for(int i = n-maxval/2; i<n; i++){
            cout << ids[i]; 
        }
    }else{
        for(int i = 0; i < n; i++){
            cout << ids[i]; 
        }
    }
}

int readIDSfromStream(const string filename, ID ids[]){
    int num = 0; 

    ifstream ifs(filename, ifstream::in); 
    while(ifs.good()){
        ID tempID; 
        ifs>>tempID;
        ids[num++] = tempID; 
    }
    return num; 
}

ostream & operator<< (ostream& out,  ID& ids){
    out << ids.getID() << " "<<ids.getKey()<<endl; 
    return out;
}

istream & operator >>(istream & in, ID & ids){
    string ID_key;  
    getline(in, ids.ID_string, '-'); 
    getline(in, ID_key, '-'); 
    ids.key = stoi(ID_key.c_str()); 
    return in; 
}

template <typename T>
void bubbleSortFlag(T arr[], int n){
    cout << endl<<"--- Sorting: Bubblesort ---"<<endl; 
    bool toSwitch; 
    T aux; 
    while(toSwitch){
        toSwitch = false; 
        for(int i = 0; i < n-1; i++){
            
            if((arr[i].getKey() < arr[i+1].getKey())){
                toSwitch = true; 
                aux = arr[i]; 
                arr[i] = arr[i+1]; 
                arr[i+1] = aux; 
            }
        }
    }
}



int main(){
    int n; 
    ID idList[INTNUM]; 

    n = loadStrings("readFromThis.txt", idList); 
    cout << n <<endl; 
    printIDs(idList, n); 
    
    bubbleSortFlag(idList, n); 
    
    printIDs(idList, n); 

    cout<<endl; 
}