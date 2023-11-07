#include <stdio.h>

void swap(int *a, int pos1, int pos2);

void Quicksort(int *a, int l, int r);

int HoarePartition(int *a, int l, int r);


int main() {
    int c;
    scanf("%d", &c);
    int n[c];

    for(int i = 0; i < c; i++) {
        scanf("%d", &n[i]);
        int array[n[i]];
        int l = 0, r = (n[i] - 1);

        for(int j = 0; j < n[i]; j++) {
            scanf("%d", &array[j]);
        }

        Quicksort(array, l, r);

        for(int j = 0; j < n[i]; j++) {
            printf("%d ", array[j]);
        }
        printf("\n");
    }

    
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
        } while(!(a[i] >= p || i >= r));
        do {
            j = j-1;
        } while(!(a[j] <= p));
        
        swap(a, i, j);
    } while(!(i >= j));
    
    // Undo last swap when i >= j
    swap(a, i, j);
    swap(a ,l, j);
    
    return j;
}
