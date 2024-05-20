// Loris Matta
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 5 // Numero di righe
#define C 5 // Numero di colonne

void carica_random(int m[][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            m[i][j] = rand() % 100 + 1;
        }
    }
}

void carica(int m[][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("Inserisci il numero per la posizione [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

int conta(int m[][C]){
    int cont = 0, scelta = 0;
    printf("Inserisci il numero che vuoi controllare: ");
    scanf("%d", &scelta);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(m[i][j] == scelta)
                cont++;
        }
    }
    return cont;
}

void stampaMatrice(int m[][C]) {
    printf("La matrice è:\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

// Funzione per stampare la diagonale principale in modo visivo
void stampaDiagonale(int m[R][C]) {
    printf("Diagonale principale:\n");
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (i == j) {
                printf("%d\t", m[i][j]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}

// Funzione per stampare la diagonale secondaria in modo visivo
void stampaDiagonaleSecondaria(int m[R][C]) {
    printf("Diagonale secondaria:\n");
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (j == R - 1 - i) {
                printf("%d\t", m[i][j]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int a;
    int mat[R][C];
    
    printf("Come vuoi caricare la tua matrice?\n");
    printf("1. Caricare in modo manuale\n");
    printf("2. Caricare in modo randomico\n");
    scanf("%d", &a);
    
    switch(a) {
        case 1:
            carica(mat);
            break;
        case 2:
            carica_random(mat);
            break;
        default:
            printf("Il numero inserito non è valido\n");
            return 1; // Termina il programma se l'input non è valido
    }
    
    int scelta;
    do {
        printf("\nCosa vuoi fare?\n");
        printf("1. Stampare la matrice\n");
        printf("2. Contare le occorrenze di un numero\n");
        printf("3. Stampare la diagonale principale\n");
        printf("4. Stampare la diagonale secondaria\n");
        printf("5. Uscire\n");
        scanf("%d", &scelta);
        
        switch(scelta) {
            case 1:
                stampaMatrice(mat);
                break;
            case 2: {
                int count = conta(mat);
                printf("Il numero che hai inserito appare %d volte nella matrice.\n", count);
                break;
            }
            case 3:
                stampaDiagonale(mat);
                break;
            case 4:
                stampaDiagonaleSecondaria(mat);
                break;
            case 5:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 5);

    return 0;
}
