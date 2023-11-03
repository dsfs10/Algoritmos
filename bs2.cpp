#include <stdio.h>
#include <stdlib.h>
#define n 5

int BinarySearch(int *A, int K);

int main() {
    int A[] = {1, 2, 3, 5, 7};
    int K = 7, s = 0;

    s = BinarySearch(A, K);
    
    if(s != -1) {
        printf("%d\n", s);
    }
    else {
        printf("Nao encontrado");
    }

    return 0;
}


int BinarySearch(int *A, int K) {
    int l = 0, r = n - 1;
    int m = (l + r) / 2;

    while(l <= r) {
        if(K == A[m]) {
            return m;
        }
        else if(K < A[m]) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return -1;
}
