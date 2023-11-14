#include <stdio.h>

void swap(long long int *a, int pos1, int pos2);

void Quicksort(long long int *a, int l, int r);

int Partition(long long int *a, int l, int r);



int main() {
    int n = 0, m = 0;
    scanf("%d", &n); // Definindo o numero de barras
    long long int a[n], soma = 0;
    int l = 0, r = n-1;

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]); // Definindo o preco de cada uma das n barras
        soma += a[i]; 
    }

    Quicksort(a, l, r); // Ordena o array a em ordem crescente

    scanf("%d", &m); // Definindo o numero de cupons
    long long int s[m];
    int q[m];

    for(int i = 0; i < m; i++) {
        scanf("%d", &q[i]); // Definindo o numero de barras que voce tem que comprar usando o ith cupom para que o mais barato deles seja de graca
        
        s[i] = (soma - a[n - q[i]]); 
        printf("%lld\n", s[i]);
    }
    

    return 0;
}



void swap(long long int *a, int pos1, int pos2) {
    int aux = 0;

    aux = a[pos1];
    a[pos1] = a[pos2];
    a[pos2] = aux;
}

void Quicksort(long long int *a, int l, int r) {
    int s = 0;
    if(l < r) {
        s = Partition(a, l, r); // s = split position
        Quicksort(a, l, s-1);
        Quicksort(a, s+1, r);
    }
}

int Partition(long long int *a, int l, int r) {
    int p, i, j;
    p = a[l];
    i = l; // incrementa
    j = r + 1; // decrementa

    do {
        do {
            i = i + 1;
        } while(!(a[i] >= p || i >= r));
        do {
            j = j - 1;
        } while(!(a[j] <= p));

        swap(a, i, j);
    } while(!(i >= j));
    // Undo last swap when i >= j
    swap(a, i, j);
    swap(a, l, j);

    return j;
}
