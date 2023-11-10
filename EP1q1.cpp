#include <stdio.h>

typedef struct {
    char nome[31];
    int tempo;
} Pessoa;

void swap(Pessoa *A, int pos1, int pos2);

void Mergesort(Pessoa *A, int l, int r, int c);

void Merge(Pessoa *A, int l, int r, int c);


int main() {
    int c;
    scanf("%d", &c);
    Pessoa pessoa[c];
    int l = 0, r = c - 1;
    
    for(int i = 0; i < c; i++) {
        scanf(" %s %d", pessoa[i].nome, &pessoa[i].tempo);
    }

    Mergesort(pessoa, l, r, c);

    for(int contador = 1; contador < c; contador++) {
        for(int i = 0; i < c-1; i++) {
            if(pessoa[i].tempo == pessoa[i+1].tempo) {
                if(pessoa[i].nome < pessoa[i+1].nome) {
                    swap(pessoa, i, i+1);
                }
            }
        }
    }

    for(int i = 0; i < c; i++) {
        printf("%s %d\n", pessoa[i].nome, pessoa[i].tempo);
    }

    return 0;
}


void swap(Pessoa *A, int pos1, int pos2) {
    Pessoa aux;
    aux = A[pos1];
    A[pos1] = A[pos2];
    A[pos2] = aux;    
}

void Mergesort(Pessoa *A, int l, int r, int c) {
    if(l < r) {
        int m = (l + r) / 2;
        Mergesort(A, l, m, c);
        Mergesort(A, m + 1, r, c);
        Merge(A, l, r, c); 
    }
}

void Merge(Pessoa *a, int l, int r, int c) {
    Pessoa temp[c];
    for(int i = l; i <= r; i++) {
        temp[i] = a[i];
    }

    int m = (l + r) / 2;
    int i1 = l, i2 = m + 1;
    for(int curr = l; curr <= r; curr++) {
        if(i1 == (m + 1)) {
            a[curr] = temp[i2++];
        }
        else if(i2 > r) {
            a[curr] = temp[i1++];
        }
        else if(temp[i1].tempo <= temp[i2].tempo) {
            a[curr] = temp[i1++];
        }
        else {
            a[curr] = temp[i2++];
        }
    }
}
