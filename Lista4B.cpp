#include <iostream>
#define endl "\n"
using namespace std;


int remove(int* hp, int n);
void HeapBottomUp(int* array, int n);
void Heapsort(int* hp, int n);
void PrintHeap(int* hp, int n);
int Sum(int* hp, int n);


int main(void) {
    int n;

    while(n != 0) {
        cin >> n;

        if(n == 0) {
            break;
        }
        int hp[n+1];
        
        for(int i = 1; i <= n; i++) {
            cin >> hp[i];
        }

        HeapBottomUp(hp, n);
        cout << Sum(hp, n) << endl;
    }
    
    
    
    return 0;
}

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

int Sum(int* hp, int n) {
    int sum = 0;
    int cost = 0;
    int final_cost = 0;
    int size = n;
    for(int i = 0; i < n; i++) {
        int min = remove(hp, size);
        size--;
        sum = min + sum;
        if(i > 0) {    
            cost = sum;
            final_cost = cost + final_cost;
        }    
    }
    
    return final_cost;
}

void PrintHeap(int* hp, int n) {
    for(int i = 1; i <= n; i++) {
        cout << hp[i] << " "; 
    }
    cout << endl;
}
