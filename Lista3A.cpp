#include <iostream>
using namespace std;
#define endl "\n"

typedef struct {
    string Key;
    int index;
} Entry;

typedef struct {
    int m; // size of the hash tables
    int cnt; // number of elements in the dictionary
    Entry* H; // hash table as an array of Entry
} Dictionary;


int h(string K, int m);
int Find(Dictionary* d, string k);
Dictionary* create_dict(int size);
Entry create_entry(string key, int index);
void insert(Dictionary* d, string key); // E type (string)
string remove(Dictionary* d, string key);


int main(void) {
    int t, n;
    string comando;
    cin >> t;

    for(int i = 0; i < t; i++) {
        Dictionary* d = create_dict(101);
        n = 0;
        cin >> n;

        for(int j = 0; j < n; j++) {
            cin >> comando;
            if(comando.substr(0, 4) == "ADD:") {
                insert(d, comando.substr(4, comando.size() - 4));
            }
            else if(comando.substr(0, 4) == "DEL:") {
                remove(d, comando.substr(4, comando.size() - 4));
            }
        }
        
        cout << d->cnt << endl;
        for(int i = 0; i < d->m; i++) {
            if(d->H[i].index != -1 && d->H[i].Key != "deleted") {
                cout << d->H[i].index << ":" << d->H[i].Key << endl;
            }
        }
        
    }
    
    
    return 0;
}


int h(string K, int m) {
    int s = K.size();
    int sum = 0;

    for(int i = 0; i <= s-1; i++) {
        sum = sum + K[i]*(i+1);
    }

    return abs(19*sum) % m; // abs = overflow and % 
}

int Find(Dictionary* d, string key) {
    int i = h(key, d->m);
    if(d->H[i].index != -1 && d->H[i].Key == key) {
        return i;
    }
    int tmp = i;

    for(int j = 1; j <= 19; j++) {
        tmp = (h(key, d->m) + (j*j) + 23*j) % 101;
        if(d->H[tmp].index != -1 && d->H[tmp].Key == key) {
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
    for(int i = 0; i < size; i++) {
        d->H[i].index = -1; // empty
    }
    return d;
}

Entry create_entry(string key, int index) {
    Entry ent;
    ent.index = index;
    ent.Key = key;
    return ent;
}

void insert(Dictionary* d, string key) {
    if(d->cnt < d->m && Find(d, key) == -1) {
        int pos = h(key, d->m); // h is the hash function
        int i = 0;
        if(d->H[pos].index != -1 && d->H[pos].Key != "deleted") {
            int newPos;
            do {
                i = i + 1;
                if(i == 20) {
                    return;
                }
                newPos = (h(key, d->m) + (i*i) + 23*i) % 101;
            } while(!(d->H[newPos].index == -1 || d->H[newPos].Key == "deleted"));
            pos = newPos;
        }
        Entry entry = create_entry(key, pos);
        d->H[pos] = entry;
        d->cnt++;      
    }
}

string remove(Dictionary* d, string key) {
    int i = Find(d, key);

    if(i != -1) {
        string tmp = d->H[i].Key;
        d->H[i].Key = "deleted";
        d->cnt--;
        return tmp;
    }
    
    return "/0";
}
