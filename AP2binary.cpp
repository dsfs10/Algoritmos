#include <stdio.h>

int BinarySearch(int *A, int v, int n);

int main() {
    int n, m, p;
    scanf("%d", &n);
    int A[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        int v = 0, s = 0;
        scanf("%d", &v);

        s = BinarySearch(A, v, n);

        if(s != -1) {
            printf("%d\n", s);
        }
        else {
            printf("x\n");
        }
    }


    return 0;
}


int BinarySearch(int *A, int v, int n) {
    int l = 0, r = n - 1;

    while(l <= r) {
        int m = (l + r) / 2;
        if(v == A[m]) {
            return m;
        }
        else if(v < A[m]) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return -1;
}
