# 1 - Arrays

```
tipoElementi nomeArray[numeroElementi]; [^1]
```

C++ non verifica che gli indici stiano dentro la dimensione definita. (non protegge automaticamente da buffer overflow)

come proteggere da buffer overflow?

```c++

double somma(double a[], int n){

    if(n* sizeof(double)>sizeof(a)){
        return 0;
    }

    double s = 0.0;
    for(int i = 0; i<n; i++){
        s += a[i];
    }
    return s;

}
```

***

## Inizializzazione Array + stringhe e array caratteri

```c++
int numeri[100] = {0};

// e' uguale a

int numeri[100];

for(int i = 0; i < 100; i++){
    numeri[i] = 0;
}
```




* una STRINGA ha un carattere in piu' rispetto a un array di caratteri con lo stesso numero di lettere: possiede il carattere ascii null.
* la funzione strcpy() automatizza l'assegnazione di una stringa ad un array.
```
strcpy(nome, "Ciao")
```

## Array multidimensionali




[^1]: numeroElementi dev'essere int


