#include <iostream>

using namespace std;

typedef struct link {
    int element; // E type, value stored in this link/node
    struct link* next; // Reference to the next link/node
} Link;

typedef struct list {
    Link* head;
    Link* tail;
    Link* curr;
    int cnt; // list size
} List;

typedef struct {
    int m; // size of the hash table
    int cnt; // number of elements in the dictionary
    List* H; // hash table as an array of lists
    // hash function
} Dictionary;


int h(string K);
Link* create_link(Link* nextval);
List* create_list();
Dictionary create_dict(int size, ); // Não sei botar o segundo parâmetro


int main(void) {
    

    
    return 0;
}


int h(string K) {
    int intLength = str.size(K)/4; 
    int sum = 0;
}

List* create_list() {
    List* l = (List *) new int;
    l->curr = l->tail = l->head = create_link(NULL); // header node
    l->cnt = 0;
    return l;
}

Link* create_link(Link* nextval) {
    Link* n = (Link *) new int;
    n->next = nextval;
    return n;
}

Dictionary* create_dict(int size, ) {
    Dictionary* d;
    d->m = new List[size]; // ??
    for(int i = 0; i <= size-1; i++) {
        // a list of Entry, which combines Key and E
        d->H[i] = create_list();
    }
    d->m = h;
    return d;
}
