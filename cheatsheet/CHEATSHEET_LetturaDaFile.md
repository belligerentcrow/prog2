# **Lettura da File**

Libreria per leggere da file: ```#include <fstream>```  
Libreria stringstream per la divisione dell'input: ```#include <sstream>```  
Libreria per le stringhe che è sempre utile: ```#include <string>```
  
***
  
## **Ricordarsi di implementare un metodo per poter confrontare le keys**  
  
O la comparazione tramite keys con metodi friends tipo così:  

```cpp
friend 
ostream & operator << (ostream & out, ID & ids); 

friend 
istream & operator >>(istream & in, ID & ids); 

// ...

// ...

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

```
  
Oppure un confronto tra chiavi private tramite opportuni metodi getters, ce piase comunque  

***

## **Creare classe relativa all'oggetto in questione**
  
Nell'esempio avevo creato **ID**:  
Ha un costruttore vuoto e un costruttore ```ID(string str, int k);```  
Perché nell'esercizio che avevo fatto, i dati in input erano della forma **STRINGAALFANUMERICA-CHIAVE**, con '-' come delimitatore.  

Ho messo i getters come metodi *public*, e **ID_string** e **key** come dati *private*, come al solito.  
  
***

## **Definire funzione di Split-string**
  
Questa funzione serve a estrarre i dati presenti all'interno del file in maniera tale da poter inserire i relativi dati all'interno degli attributi della classe corrispondente.  

```cpp
/*
string str = la riga di input a cui siamo (es: riga del textfile)
array di stringhe content[2] = dove metterò i dati estratti dall'input, che usciranno in formato STRINGA
*/
void splitString(string str, string content[2]){
    
    char delim = '-'; //il carattere tra un dato e l'altro
    
    string token; //la stringa dove sarà posto il dato
    
    stringstream ss(ss); //lo stringstream dove butto ogni linea
    
    int i = 0; //uno strumentopolo che ci servirà più tardi

    /*lo getline prende in input lo stream ss, lo legge fino a delim, 
        e mette quello che ha letto prima di "delim" in token*/
    while(getline(ss, token, delim)){

    content[i] = token; //metto il primo dato nell'indice 0 di content
    
    i++; //aumento il posto nell'array
    
    /*il "2" qui dipendeva dai DUE attributi: ID e Stringa. 
    Se ci fossero stati 3 attributi, sarebbe stato 3.
    Mi segnala quanti posti dell'array devo riempire, settare di conseguenza
    */
    if(i==2){
        break;  
    }
    }
}
```

***

## **Loadare dal file**

```cpp
/* --> nel main ho 
      n = loadStrings("readFromThis.txt", idList);

    filename è letteralmente il nome del file

    idList è un array del tipo userdefined ID (vedi sopra)  
    In idsArray finiranno TUTTE le righe di input, divise opportunamente da SplitString(), con i dati ordinati da LoadString()
    Fondamentalmente sarà un array con TUTTI gli IDS, uno per ogni riga di cui è composto l'input
    (Es: per un file di 300 righe, ci saranno 300 IDs, etc)
*/
int loadStrings(const string filename, ID idsArray[]){
    
    ifstream file; // oggetto file!! 

    string line; // what it says on the tin

    string buffer[2]; //dove metto i dati presi grazie a splitString();

    file.open(filename); //apre il file del nome filename nell'oggetto "file"

    int num = 0; //altro strumentopolo

    //controllo che il file sia aperto E che tutto vada 
    if(file.is_open()){
        
        //while che continua a girare finché ci siano righe da poter leggere nel file di input
        while(getline(file, line)){

            splitString(line, buffer); //chiamo la procedura di prima, che metterà nel buffer i dati che mi servono

            ID tempID;  //Creo oggetto di tipo ID (per ora vuoto)

            /* In realtà potevo (CREDO) anche semplicemente fare la riga qua sotto, (mettendo prima il tipo ID obv) la quale crea un oggetto ID chiamando il costruttore con i dati inseriti nel Buffer da splitString(); 
            */
            tempID = ID(buffer[0], stoi(buffer[1])); 
            
            //inserisco l'ID nell'array principale di IDs e aumento l'indice
            idsArray[num] = tempID; 
            num++; 

        }
        file.close();   //chiudo il file
    } else {
        cout << "Can't open file"<<endl; //error check di buona norma
    }
    return num; //ritorna (per qualche motivo) il numero di IDs caricati in idsArray, che viene contato grazie al while con getline, incrementato ad ogni riga
}

```

***

## **Extra**
  
Potrebbe chiedere di ordinare per chiavi:  
Questo si può fare O tramite confronto grazie ai getters, oppure implementando l'overloading degli operatori di confronto (più macchinoso ma tecnicamente più "elegante").  
Ordinare tramite uno degli algoritmi di ordinamento visti a lezione, gettando in un nuovo file. Ecco appunto mi stavo dimenticando della parte di come gettare in un nuovo file orcocan-  

* Bubblesort, Mergesort, InsertionSort, SelectionSort, Quicksort. CountingSort se proprio ti vuoi male (si scherza)

Se chiede di "valutare la complessità temporale stimando il tempo di esecuzione"(sic) inizia a pregare il signore di passare con sufficienza senza quel pezzo

***

## **Generare un file di output**

Utilizzo il file (aprendolo con il tipo ofstream) come, appunto, uno stream.  
Ci butto letteralmente dentro le cose con un ```<<``` di prepotenza e poi chiudo.  

Esempio:  

```cpp

    ofstream file3; //stream di tipo ofstream per aprire un file per output
    
    file3.open("donecountries.txt", ios_base::app); //apro il file corrispondente 
    
    file3 << chosen; //sparo la stringa dentro il file  
    
    file3 << "\n";  //sparo una newline dentro il file (IMPORTANTE!!!)
    
    file3.close(); //chiudo il file
    
    //poi ritorno ciò che devo ritornare etc
```
