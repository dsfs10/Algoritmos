#include <stdio.h>
#include <string.h>

int BinarySearch(char estudante[][], char k[], int e);

int main() {
    int e, q;
    scanf("%d", &e);
    char estudante[e][31];
    //char procura[31];

    for(int i = 0; i < e; i++) {
        scanf(" %s", estudante[i]);
    }
    scanf("%d", &q);

    for(int i = 0; i < q; i++) {
        char procura[31];
        scanf("%s", procura);

        BinarySearch(estudante, procura, e);
    }
    
    return 0;
}


int  BinarySearch(char estudante[][], char k[], int e) {
    int l = 0, r = e - 1;

    while(l <= r) {
        int m = (l + r) / 2;
        if(strcmp(k, estudante[m]) == 0) {
            return m;
        }
        else if()
    }
}
