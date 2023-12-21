#include <iostream>
#define endl "\n"
using namespace std;

typedef struct node {
    int key;
    int element;
    struct node* left; // left child
    struct node* right; // right child
} Node;

typedef struct {
    Node* root;
    int nodecount; // number of elements
    int capacity; // heap max size
} Heap;

Node* create_node(int k, int e);
Heap* create_heap(int capacity);
Heap* create_heap();
void insert(Heap* hp, int k, int e);
Node* inserthelp(Node* rt, int k, int e);
int remove(Heap* hp);
void preorder(Node* rt);
void inorder(Node* rt);
void posorder(Node* rt);
void HeapBottomUp(Heap* hp);
int* Heapsort(Heap* hp);
void PrintHeap(Heap* hp);


int main(void) {
    Heap* hp = create_heap();
    int c;
    cin >> c;

    for(int i = 0; i < c; i++) {
        int n, k;
        cin >> n;
        hp->nodecount = n;
        for(int j = 0; j < n; j++) {
            k = 0; 
            cin >> k;
            insert(hp, k, k);
        }
        HeapBottomUp(hp); // heapify
        PrintHeap(hp);
    }
    
    
    return 0;
}

Node* create_node(int k, int e) {
    Node* n = (Node *) new int;
    n->key = k;
    n->element = e;
    n->left = n->right = NULL;
    return n;
}

Heap* create_heap(int capacity) { // for top-down
    Heap* hp = (Heap *) new int;
    hp->root = NULL;
    hp->nodecount = 0;
    hp->capacity = capacity;
    return hp;
}

Heap* create_heap() { // for bottom-up
    Heap* hp = (Heap *) new int;
    hp->root = NULL;
    hp->nodecount = 0;
    return hp;
}

void insert(Heap* hp, int k, int e) {
    hp->root = inserthelp(hp->root, k, e);
    hp->nodecount++;
}

Node* inserthelp(Node* rt, int k, int e) {
    if(rt == NULL) {
        return create_node(k, e);
    }
    
    if(rt->key > k) {
        rt->left = inserthelp(rt->left, k, e);
        cout << "test" << endl;
    }
    else {
        rt->right = inserthelp(rt->right, k, e);
        cout << "test2" << endl;
    }
    
    return rt;
}

int remove(Heap* hp) {
    if(hp->nodecount > 0 && hp->root != NULL) {    
        int tmp;
        tmp = hp->root->key;
        hp->root->key = hp->root[hp->nodecount].key; // -1?
        hp->root[hp->nodecount].key = tmp;
        hp->nodecount--;
        HeapBottomUp(hp);

        return tmp;
    }

    return -1;    
}

void preorder(Node* rt) {
    if(rt != NULL) {
        // do something with rt
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(Node* rt) {
    if(rt != NULL) {
        inorder(rt->left);
        // do something with rt
        inorder(rt->right);
    }
}

void posorder(Node* rt) {
    if(rt != NULL) {
        posorder(rt->left);
        posorder(rt->right);
        // do something with rt
    }
}

void HeapBottomUp(Heap* hp) {
    for(int i = (hp->nodecount / 2); i >= 1; i--) {
        int k = i; // current position of the i-th internal node
        int v = hp->root[k].key; // value of the i-th internal node
        bool heap = false;
        // finding the proper place for the i-th internal node
        while(heap == false && 2*k <= hp->nodecount) {
            int j = 2*k; // position of the first child
            
            if(j < hp->nodecount) { // has two children | finds the largest child 
                if(hp->root[j].key < hp->root[j+1].key) {
                    j = j + 1;
                }
            }
            if(v >= hp->root[j].key) { // is a heap if v is ≥ than the largest child
                heap = true;
            }
            else { // places the largest child in H[k] | updates k
                hp->root[k] = hp->root[j];
                k = j;
            }
        }
        hp->root[k].key = v;
    }
}

int* Heapsort(Heap* hp) { // for min heap
    /*int aux[hp->nodecount];
    for(int i = 0; i < hp->nodecount; i++) {
        aux[i] = remove(hp);
    }

    return aux;*/
}

void PrintHeap(Heap* hp) {
    for(int i = 1; i <= hp->nodecount; i++) {
        cout << hp->root[i].key << " "; 
    }
    cout << endl;
}
