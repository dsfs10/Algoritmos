#include <stdio.h>
#define n 11

int main() {
    int a[] = {10, 5, 7, 2, 8, 1, 9, 3, 4, 6, 0};
    int min = 0, aux = 0;

    for(int i = 0; i <= n-2; i++) {
        min = i;
        for(int j = i+1; j <= n-1; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        // Swap
        aux = a[i];
        a[i] = a[min];
        a[min] = aux;
    }

    // Printando
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
