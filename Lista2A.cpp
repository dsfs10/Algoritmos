#include <iostream>

using namespace std;

typedef struct {
    int n;
} Case;

typedef struct link {
    string element; // E type, value stored in this link/node
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
void insert(List* l, string item);
void remove(List* l);
void prev(List* l);
void next(List* l);
void printList(List* l);
int count(List* l);
Link* create_link(string it, Link* nextval);
Link* create_link(Link* nextval);


int main(void) {
    List* l = create_list();
    string input;

    while(cin >> input) {
        
    }


    return 0;
}


Link* create_link(string it, Link* nextval) {
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
       Link *temp = l->head;
       Link *next = temp->next;

       while(temp->next != NULL) {
        next = temp->next;
        delete temp;
        temp = next;
       }
       delete temp;
       delete l;
}

void insert(List* l, string it) {
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
