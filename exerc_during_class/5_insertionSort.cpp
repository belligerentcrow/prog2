

/* Ordinamento per inserimento */

#include <iostream>
using namespace std;

int binarySearch(int a[], int chiave,
                 int l, int h);

void insertionSort(int A[], int n){
    /*
     [   |   |  |   |    ]
         ^
         i
     A[0...i] : sottoarray ordinato
    */
    int chiave, i, j;
    for(i=1;i<n;i++){
        chiave = A[i]; //elemento da posizionare
        /*      <-- j
            [ ..... | ....... ]
                    ^
                    i        */
        j = i-1;
        while(j>=0 && A[j]>chiave){
            A[j+1]=A[j];
            j--;
        }
        A[j+1] = chiave;
    }

}

/*Migliorare l’algoritmo precedente
sfruttando la ricerca binaria
*/
void insertionSortBinario(int a[], int n){
    int i,j,chiave,pos;
    for(i=1;i<n;++i){
        chiave = a[i];
        j = i-1;
        // trova la posizione dove inserire la chiave
        pos = binarySearch(a, chiave, 0,j);
        //sposto gli elementi a dx di 1 posizione
        //per fare spazio alla chiave
        while(j>=pos){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=chiave;
    }
}

/*Ricerca binaria per trovare la posizione
dove inserire l'elemento 'chiave'
all'interno di a[l...h] */
int binarySearch(int a[], int chiave,
                 int l, int h){
        //quando ci riduciamo ad un solo elemento
        if(h<=l){
            if(chiave>a[l])
                return l+1;
            else
                return l;
        }
        int m = (l+h)/2;
        if(chiave == a[m])
            return m+1;
        if(chiave > a[m])
            // chiamata ricorsiva in a[m+1....h]
            return binarySearch(a,chiave,m+1,h);
        return binarySearch(a,chiave,l,m-1);
 }


void stampaVettore(int v[], int n){
    for(int i=0;i<n;i++)
        cout << v[i] << " ";
    cout << endl;
}

int main(){
    int vettore[20] = {12,3,6,7,130,
                        4, 120, 11, 9,1,
                        0,16,71,89,15,
                        24, 10, 21,2,13};

    cout << "Vettore iniziale:\t";
    stampaVettore(vettore,20);
    insertionSort(vettore,20);
    cout << "Vettore ordinato:\t";
    stampaVettore(vettore,20);


    int vettore2[20] = {12,3,6,7,130,
                        4, 120, 11, 9,1,
                        0,16,71,89,15,
                        24, 10, 21,2,13};

    cout << "Vettore iniziale:\t";
    stampaVettore(vettore2,20);
    insertionSortBinario(vettore2,20);
    cout << "Vettore ordinato:\t";
    stampaVettore(vettore2,20);

    return 0;
}
