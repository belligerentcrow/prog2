/* Definire più metodi per stampare i numeri 
primi <= n e valutare il loro tempo di esecuzione 
per valori di n crescenti 
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>
using namespace std; 

void printPrimesOne(int N){

//ungloriously snatched from the sieve code
 
short count = 0; 	
int p = 2;		  		
int radN = sqrt(N); 
int matrice[N]={}; 
for(int i = 0; i<N-1; i++){
	matrice[i] = i+2;	
}
  

while(p<=radN){		

for(int i=0; i<N-1; i++){
	if(matrice[i]%p==0&&matrice[i]!=p){	 
	matrice[i] = 0;			
	 
	}
	
}
count = p-1; 
while(count!=0){
	if(matrice[count]!=0){
		p= matrice[count];	
		count = -1; 
	}
	count++; 
}

short primi = 0; 
if(p>radN){
	//cout << "\nMassimo valore di P raggiunto. P =" << p <<endl; 
	cout << "Crivello ultimato: "<<endl; 

	for(int i =0; i<N-2; i++){
		if(matrice[i]!=0){	
		cout << matrice[i]<< ", "; 
		primi ++; 		
		}
	}
	cout << "I primi trovati sono: " << primi <<endl; 
}
}


}

int main(){

    int n = 0; 
    cout << "Insert n, an integer: "<<endl; 
    
    while(n<=0){
        cin >> n;
        if(n<=0){
            cout << "Insert a number greater than 0."<< endl; 
        }
    }

    printPrimesOne(n);

    cout << endl << endl << "fine"<<endl <<endl;

}