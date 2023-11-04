#include <stdio.h>
#define n 7

void Mergesort(int *a, int l, int r);

void Merge(int *a, int l, int r);

int main() {
    int a[] = {4, 5, 2, 1, 3, 0, 7};
    int l = 0, r = n - 1;

    Mergesort(a, l ,r);

    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}


void Mergesort(int *a, int l, int r) {
    if(l < r) {    
        int m = (l + r) / 2;
        Mergesort(a, l, m);
        Mergesort(a, m+1, r);
        Merge(a, l, r);
    }    
}

void Merge(int *a, int l, int r) {
    int temp[n];
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
        else if(temp[i1] <= temp[i2]) {
            a[curr] = temp[i1++];
        }
        else {
            a[curr] = temp[i2++];
        }
    }
}
