#include <iostream>
#define endl "\n"
using namespace std;

typedef struct {
    int n; // size
    int m; // max size
    char* hp;
} Heap;

Heap* create_heap(int m);
void insert(Heap* H, char k);
char remove(Heap* H);
void Heapify(Heap* H);
void Heapsort(int* hp, int n);
void PrintHeap(int* hp, int n);


int main(void) {
    int m;
    cin >> m;
    Heap* heap = create_heap(m);

    
    
    return 0;
}


Heap* create_heap(int m) {
    Heap* h = (Heap *) new int;
    h->hp = (char *) new char[m+1];
    h->m = m;
    h->n = 0;
}

void insert(Heap* H, char k) {
    if(H->n <= H->m) {    
        H->hp[H->n + 1] = k;
        H->n++;
    }
    else {
        cout << "Tamanho máximo atingido!" << endl;
    }    
}

char remove(Heap* H) {
    if(H->n > 0 && H->hp != NULL) {    
        char tmp;
        tmp = H->hp[1];
        H->hp[1] = H->hp[H->n];
        H->hp[H->n] = tmp;
        H->n--;

        return tmp;
    }
    else {
        cout << "Heap vazia!" << endl;
        return '/0';
    }    
}

void Heapify(Heap* H) {
    if(H->hp[H->n] > H->hp[H->n/2]) {
        swap(H->hp[H->n], H->hp[H->n/2]);
        
    }
}

void Heapsort(int* hp, int n) { // for min heap
    int aux[n];
    int tam = n;
    for(int i = 0; i < n; i++) {
        aux[i] = remove(hp, tam);
        tam--;
        if(tam > 0) {
            PrintHeap(hp, tam);
        }    
    }

    for(int i = 0; i < n; i++) {
        cout << aux[i] << " ";
    }
    cout << endl;
}

void PrintHeap(int* hp, int n) {
    for(int i = 1; i <= n; i++) {
        cout << hp[i] << " "; 
    }
    cout << endl;
}
