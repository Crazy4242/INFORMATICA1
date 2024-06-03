#include <stdio.h>
#define N 100

 int n = 0; // Numero di elementi nel vettore
 
// Funzione per l'ordinamento del vettore
void ordinamento(int v[]) {
    int scambio, i, k;
    do {
        scambio = 0;
        for (i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                k = v[i + 1];
                v[i + 1] = v[i];
                v[i] = k;
                scambio = 1;
            }
        }
    } while (scambio == 1);
}

// Funzione per l'inserimento di un numero nel vettore ordinato
void inserisci(int v[], int numero) {
    int i, posizione = -1;
    for (i = 0; i < n; i++) {
        if (numero < v[i]) {
            posizione = i;
            break;
        }
    }
    if (posizione == -1) {
        v[n] = numero;
    } else {
        for (i = n; i > posizione; i--) {
            v[i] = v[i - 1];
        }
        v[posizione] = numero;
    }
    n++;
}

int main() {
    int v[N]; // Vettore di dimensione massima 100
   

    // Inserisci i numeri nel vettore
    printf("Inserisci i numeri nel vettore (termina con -1):\n");
    int numero;
    while (1) {
        scanf("%d", &numero);
        if (numero == -1) {
            break;
        }
        inserisci(v, numero);
    }

    // Ordina il vettore
    ordinamento(v);

    // Stampa il vettore ordinato
    printf("Vettore ordinato:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
