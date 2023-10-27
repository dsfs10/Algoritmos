#include <stdio.h>
#define n 10

int main() {
    int a[] = {5, 7, 2, 8, 1, 9, 3, 4, 6, 0};
    int v = 0, j = 0;

    for(int i = 1; i <= n-1; i++) {
        v = a[i];
        j = i-1;
        while(j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = v;
    }

    // Printando o array ordenado
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
