#include <stdio.h>
#define n 10

int main() {
    int a[] = {5, 7, 2, 8, 1, 9, 3, 4, 6, 0};
    int aux = 0;

    for(int i = 0; i <= n-2; i++) {
        for(int j = 0; j <= n-2-i; j++) {
            if(a[j+1] < a[j]) {
                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
    }

    // Printando
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
