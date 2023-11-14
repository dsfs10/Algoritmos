#include <stdio.h>

void swap(int *a, int pos1, int pos2);

void Quicksort(int *a, int l, int r);

int HoarePartition(int *a, int l, int r);

void BinarySearch(int *A, int K, int l, int r, int *s);


int main(void) {
    int n, k, s = 0;
    scanf("%d %d", &n, &k);
    int a[n], l = 0, r = n - 1;

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    Quicksort(a, l, r);

    for(int i = 0; i < n; i++) {
        if(a[i] > k) {    
            BinarySearch(a, (a[i]-k), l, r, &s);
        }    
    }

    printf("%d\n", s);

    return 0;
}


void swap(int *a, int pos1, int pos2) {
    int aux = 0;

    aux = a[pos1];
    a[pos1] = a[pos2];
    a[pos2] = aux;
}

void Quicksort(int *a, int l, int r) {
    int s = 0;
    if(l < r) {
        s = HoarePartition(a, l, r);
        Quicksort(a, l, s - 1);
        Quicksort(a, s + 1, r);
    }
}

int HoarePartition(int *a, int l, int r) {
    int j, p, i;
    p = a[l];
    i = l; // incrementa
    j = r+1; // decrementa

    do {
        do {
            i = i+1;
        } while(!(a[i] >= p || i >= r)); // para decrescente troca o >= pra <= no a[i] (o i deixa como ta)
        do {
            j = j-1;
        } while(!(a[j] <= p)); // pra decrescente troca o <= pra >=
        
        swap(a, i, j);
    } while(!(i >= j));
    
    // Undo last swap when i >= j
    swap(a, i, j);
    swap(a ,l, j);
    
    return j;
}


void BinarySearch(int *A, int K, int l, int r, int *s) {
    //int l = 0, r = n - 1;

    while(l <= r) {
        int m = (l + r) / 2;
        if(K == A[m]) {
            (*s)++;
            return;
        }
        else if(K < A[m]) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return;
}
