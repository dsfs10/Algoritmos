#include <stdio.h>
#define n 5

void swap(int *A, int pos1, int pos2);

void Quicksort(int *A, int l, int r);

int Partition(int *A, int l, int r);



int main() {
    int A[] = {5, 2, 1, 7, 0};
    int l = 0, r = n-1;

    Quicksort(A, l, r);

    // Printando o array ordenado
    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}


void swap(int *A, int pos1, int pos2) {
    int aux = 0;

    aux = A[pos1];
    A[pos1] = A[pos2];
    A[pos2] = aux;
}

void Quicksort(int *A, int l, int r) {
    int s = 0;
    if(l < r) {
        s = Partition(A, l, r); // s = split position
        Quicksort(A, l, s-1);
        Quicksort(A, s+1, r);
    }
}

int Partition(int *A, int l, int r) {
    int j, p, i;
    p = A[l];
    i = l; // incrementa
    j = r+1; // decrementa

    do {
        do {
            i = i+1;
        } while(!(A[i] >= p || i >= r));
        do {
            j = j-1;
        } while(!(A[j] <= p));
        
        swap(A, i, j);
    } while(!(i >= j));
    
    // Undo last swap when i >= j
    swap(A, i, j);
    swap(A ,l, j);
    
    return j;
}
