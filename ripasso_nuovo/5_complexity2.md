# **Complessità parte 2**

**Divide** 
: dividere il problema in sottoproblemi (istante più piccole *dello stesso problema*)

**Impera**
: risolvere i sottoproblemi ricorsivamente 

**Combina**
: combinare le soluzioni dei sottoproblemi ottenendo la soluzione del problema originale

## Relazioni di ricorrenza
Esse descrivono in maniera precisa le prestazioni degli algoritmi ricorsivi. 

***

***

## **SOMMATORIE**

--> Quando l'algoritmo contiene un ciclo, il suo tempo può essere espresso come **sommatoria** dei tempi impiegati in ogni esecuzione del corpo del ciclo. 

### **Sommatorie - Linearità**

Per qualsiasi reale **c** e due sequenze finite *a<sub>1</sub>, ..., a<sub>n</sub>* e *b<sub>1</sub>, ..., b<sub>n</sub>*, si ha: 
![sommatoria, per k che va da 1 a n, di (c ⋅ a<sub>k</sub> + b<sub>k</sub>) è uguale alla somma tra c ⋅ sommatoria, per k che va da 1 a n, di a<sub>k</sub>, e sommatoria, per k che va da 1 a n, di b<sub>k</sub>.](media/immagine11.jpg)

La linearità si applica anche alle sommatorie che includono termini asintotici: 
![sommatoria con termini asintotici](media/immagine12.jpg)

***

### **Sommatorie - Serie aritmetiche**

Serie *"gaussiana"*, sommatoria di k che va da 1 a n è uguale a n ⋅ (n+1)/2, che viene uguale a Theta ⋅ (n<sup>2</sup>).

![Sommatoria di k che va da 1 a n](media/immagine13.jpg)

***

### **Sommatorie - Quadrati e Cubi**

![Sommatorie di quadrati e cubi](media/immagine14.jpg)

***

### **Sommatorie - Serie Geometriche**

![Sommatorie di esponenziale/serie geometrica: x<sup>k</sup>](media/immagine15.jpg)

***

### **Sommatorie - Serie armoniche**

![Sommatorie di serie armoniche: 1\k --> ln n + O(1)](media/immagine15.jpg)

***

## ***Limitare le sommatorie***

Il metodo principale per calcolare il valore di una serie consiste nell’utilizzare l’induzione matematica.

![Dimostrazione della gaussiana](media/immagine17.jpg)

***

--> dalla slide 21 <--