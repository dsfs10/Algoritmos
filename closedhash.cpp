#include <iostream>
using namespace std;
#define endl "\n"

typedef struct {
    int Key; // N sei o tipo
    string E;// Value E, n sei como implementar ainda
} Entry;

typedef struct {
    int m; // size of the hash tables
    int cnt; // number of elements in the dictionary
    Entry* H; // hash table as an array of Entry
    int* Perm; // permutation of 1..m-1
    int (*h)(string K, int m);
} Dictionary;

typedef struct {
    
} Key;

int h(string K, int m);
int* create_perm(int size);
int Find(Dictionary* d, int k);
Dictionary* create_dict(int size, int h());
Entry create_entry(int key, string e);
void insert(Dictionary* d, int k, string e); // E type (string)


int main(void) {
    
    
    
    return 0;
}


int h(string K, int m) {
    int s = K.size();
    int sum = 0;

    for(int i = 0; i <= s-1; i++) {
        sum = sum + K[i];
    }

    return abs(sum) % m; // abs = overflow and % 
}

int* create_perm(int size) {
    int p[size];
    return p; 
}

int Find(Dictionary* d, int k) {

}

Dictionary* create_dict(int size, int h()) {
    Dictionary* d = (Dictionary *) new int;
    d->m = size;
    d->cnt = 0;
    d->H = (Entry *) new Entry[size];
    d->Perm = create_perm(size); // 1..size-1
    d->h = h(); // ?!
    return d;
}

Entry create_entry(int key, string e) {
    Entry ent;
    ent.E = e;
    ent.Key = key;
    return ent;
}

void insert(Dictionary* d, int k, string e) {
    if(d->cnt < d->m && Find(d, k) == NULL) {
        int pos = d->h(e, d->m); // h is the hash function
        if(!(d->H[pos].E.empty()) && d->H[pos].E != "deleted") {
            int i = 0;
            int offset; // deslocamento
            int newPos;
            do {
                i = i + 1;
                offset = d->Perm[i-1];
                newPos = (pos + offset) % d->m;
            } while(!(d->H[newPos].E.empty() || d->H[newPos].E == "deleted"));
            pos = newPos;
        }
        Entry entry = create_entry(k, e);
        d->H[pos] = entry;
        d->cnt++;   
    }
}
