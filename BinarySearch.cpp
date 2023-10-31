#include <stdio.h>
#include <cmath>
#define n 5

int BinarySearch(int *A, int l, int r, int K);


int main() {
    int A[] = {5, 4, 7, 2, 1};
    int l, r, K;
    l = 0;
    r = n-1;
    K = 7;

    BinarySearch(A, l, r, K);


    return 0;
}


int BinarySearch(int *A, int l, int r, int K) {
    if(r >= l) {
        int m = floor((l+r)/2);
        if(K = A[m]) {
            return m;
        }
        else if(K < A[m]) {
            return BinarySearch(A, l, m-1, K);
        }
        else {
            return BinarySearch(A, m+1, r, K);
        }
    }
    else {
        return -1;
    }
}
