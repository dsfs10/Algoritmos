#include <iostream>
#define endl "\n"
using namespace std;



//void insert(Heap* hp, int k, int e);
int remove(int* hp, int n);
void HeapBottomUp(int* array, int n);
void Heapsort(int* hp, int n);
void PrintHeap(int* hp, int n);


int main(void) {
    int c;
    cin >> c;

    for(int i = 0; i < c; i++) {
        int n, k;
        cin >> n;
        int hp[n+1];
        for(int j = 1; j <= n; j++) {
            cin >> hp[j];
        }
        HeapBottomUp(hp, n);
        PrintHeap(hp, n);
        Heapsort(hp, n);
    }
    
    
    return 0;
}

// void insert(Heap* hp, int k, int e) {
//     hp->root = inserthelp(hp->root, k, e);
//     hp->nodecount++;
// }

int remove(int* hp, int n) {
    if(n > 0 && hp != NULL) {    
        int tmp;
        tmp = hp[1];
        hp[1] = hp[n];
        hp[n] = tmp;
        n--;
        HeapBottomUp(hp, n);

        return tmp;
    }

    return -1;    
}

void HeapBottomUp(int* array, int n) {
    for(int i = (n / 2); i >= 1; i--) {
        int k = i; // current position of the i-th internal node
        int v = array[k]; // value of the i-th internal node
        bool heap = false;
        // finding the proper place for the i-th internal node
        while(heap == false && 2*k <= n) {
            int j = 2*k; // position of the first child
            
            if(j < n) { // has two children | finds the shortest child 
                if(array[j] > array[j+1]) {
                    j = j + 1;
                }
            }
            if(v < array[j]) { // is a heap if v is < than the shortest child
                heap = true;
            }
            else { // places the shortest child in H[k] | updates k
                array[k] = array[j];
                k = j;
            }
        }
        array[k] = v;
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
