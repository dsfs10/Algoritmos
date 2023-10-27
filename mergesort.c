#include <stdio.h>
#define n 6

void Mergesort(int a, int pos1, int r);

void Merge(int a, int l, int r);

int main() {
    int a[] = {4, 5, 2, 1, 3, 0};
    int l = 0, r = 0, m = 0;

    if(l < r) {
        Mergesort(a, l, m);
        Mergesort(a, m+1, r);
        Merge(a, l, r);
    }

    return 0;
}


void Mergesort(int a, int pos1, int r) {
    m =
}
