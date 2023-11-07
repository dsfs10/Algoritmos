#include <stdio.h>

void Mergesort(int *a, int l, int r, int n);

void Merge(int *a, int l, int r, int n);

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

        Mergesort(array, l, r, n[i]);

        for(int j = 0; j < n[i]; j++) {
            printf("%d ", array[j]);
        }
        printf("\n");
    }


    return 0;
}


void Mergesort(int *a, int l, int r, int n) {
    if(l < r) {
        int m = (l + r) / 2;
        Mergesort(a, l, m, n);
        Mergesort(a, m + 1, r, n);
        Merge(a, l, r, n);
    }
}

void Merge(int *a, int l, int r, int n) {
    int temp[n];
    
    for(int i = l; i <= r; i++) {
        temp[i] = a[i];
    }
    
    int m = (l + r) / 2;
    int i1 = l, i2 = m + 1;

    for(int curr = l; curr <= r; curr++) {
        if(i1 == m + 1) {
            a[curr] = temp[i2++];
        }
        else if(i2 > r) {
            a[curr] = temp[i1++];
        }
        else if(temp[i1] <= temp[i2]) {
            a[curr] = temp[i1++];
        }
        else {
            a[curr] = temp[i2++];
        }
    }
}
