#include <iostream>
#include <math.h>
using namespace std;
#define endl "\n"

typedef struct {
    int key;
    int value;
} Entry;

typedef struct {
    int m; // size of the hash tables
    int cnt; // number of elements in the dictionary
    Entry* H; // hash table as an array of Entry
    int* Perm; // permutation of 1..m-1
    //int (*h)(string K, int m);
} Dictionary;


int h(int key, int mod);
int* create_perm(int size);
int Find(Dictionary* d, int k);
Dictionary* create_dict(int size);
Entry create_entry(Entry key);
void insert(Dictionary* d, Entry entry);
void clear(Dictionary* d);


int main(void) {
    int m = 1, op;
    string comando;

    while(m != 0) { 
        cin >> m;
        if(m == 0) {
            break;
        }
        int perm[m-1];
        Dictionary* d = create_dict(m);
        
        for(int i = 0; i < m-1; i++) {
            cin >> perm[i];
        }
        d->Perm = perm;
        cin >> op;
        Entry tmp[op];

        for(int i = 0; i < op; i++) {
            cin >> comando;

            if(comando == "add") {
                cin >> tmp[i].key;
                cin >> tmp[i].value;

                insert(d, tmp[i]);
            }
            else if(comando == "find") {
                int aux, aux2;
                cin >> aux;

                aux2 = Find(d, aux);
                if(aux2 != -1) {
                    cout << aux2 << " ";
                    cout << floor(d->H[aux2].key / 2) << endl;
                }
                else {
                    cout << aux2 << endl;
                }
            }
        }
        clear(d);
    }   

    return 0;
}


int h(int key, int mod) {
    int temp = (int) floor((((double) key) / ((double) mod)));
    return (key - (mod*temp));
}

int* create_perm(int size) {
    int p[size-1];
    return p; 
}

int Find(Dictionary* d, int key) {
    int i = h(key, d->m);
    if(d->H[i].key != NULL && d->H[i].key == key) {
        return i;
    }
    int tmp = i;

    for(int j = 0; j < ((d->m) - 1); j++) {
        tmp = (i + d->Perm[j]) % d->m;
        if(d->H[tmp].key != NULL && d->H[tmp].key == key) {
            return tmp;
        }
    }

    return -1;
}

Dictionary* create_dict(int size) {
    Dictionary* d = (Dictionary *) new int;
    d->m = size;
    d->cnt = 0;
    d->H = (Entry *) new Entry[size];
    d->Perm = create_perm(size); // 1..size-1
    //d->h = h(); // ?!
    return d;
}

Entry create_entry(Entry key) {
    Entry ent;
    ent = key;
    return ent;
}

void insert(Dictionary* d, Entry entry) {
    if(d->cnt < d->m && Find(d, entry.key) == -1) {
        int pos = h(entry.key, d->m); // h is the hash function
        if(d->H[pos].key != NULL) {
            int i = 0;
            int offset; // deslocamento
            int newPos;
            do {
                i = i + 1;
                offset = d->Perm[i-1];
                newPos = (pos + offset) % d->m;
            } while(!(d->H[newPos].key == NULL));
            pos = newPos;
        }
        Entry ent = create_entry(entry);
        d->H[pos] = ent;
        d->cnt++;   
    }
}

void clear(Dictionary* d) {
    // for(int i = 0; i < d->cnt; i++) {
    //     free(d->H[i]);
    // }
    delete d->H;
    delete d;
}
