#include <iostream>

using namespace std;

typedef struct {
    int n;
} Case;

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


List* create_list(); // Creates a new list // Lembrar do 'int size' como parametro para array list
void clear(List* l);
void insert(List* l, int item);
void remove(List* l);
void prev(List* l);
void next(List* l);
void printList(List* l);
Link* create_link(int it, Link* nextval);
Link* create_link(Link* nextval);


int main(void) {
    int c;
    cin >> c;
    Case caso[c];
    List* l = create_list();

    for(int i = 0; i < c; i++) {
        cin >> caso[i].n;
        for(int j = 0; j < caso[i].n; j++) {
            string input = NULL;
            getline(cin, input);

            if(input.substr(0, ' ') == "insert") {
                int it = input.substr(input.size);
                insert(l);
            }
        }
        clear();
    }


    return 0;
}


Link* create_link(int it, Link* nextval) {
    Link* n = (Link *) new int;
    n->element = it;
    n->next = nextval;
    return n;
}

Link* create_link(Link* nextval) {
    Link* n = (Link *) new int;
    n->next = nextval;
    return n;
}

List* create_list() {
    List* l = (List *) new int;
    l->curr = l->tail = l->head = create_link(NULL); // header node
    l->cnt = 0;
    return l;
}

void clear(List* l) {
    for(int i = 0; i < l->cnt; i++) {
        delete [] l;
    }
    l->cnt = 0;
    l->curr = l->tail = l->head = create_link(NULL);    
}

void insert(List* l, int it) {
    l->curr->next = create_link(it, l->curr->next);
    
    if(l->tail == l->curr) {
        l->tail = l->curr->next;
    }
    l->cnt++;
}

void remove(List* l) {
    if(l->curr->next == NULL) {
        return;
    }
    //int it = l->curr->next->element;

    if(l->tail == l->curr->next) {
        l->tail = l->curr;
    }
    l->curr->next = l->curr->next->next;
    l->cnt--;
    //return it;
}

void prev(List* l) {
    if(l->curr == l->head) {
        return;
    }

    Link* temp = l->head;

    while(temp->next != l->curr) {
        temp = temp->next;
    }
    l->curr = temp;
}

void next(List* l) {
    if(l->curr != l->tail) {
        l->curr = l->curr->next;
    }
}
