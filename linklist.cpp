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

Link* create_link(int it, Link* nextval) {
    Link* n;
    n->element = it;
    n->next = nextval;
    return n;
}

Link* create_link(Link* nextval) {
    Link* n;
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

}

void insert(List* l, int it) {
    l->curr->next = create_link(it, l->curr->next);
    
    if(l->tail == l->curr) {
        l->tail = l->curr->next;
    }
    l->cnt++;
}

int remove(List* l) {
    if(l->curr->next == NULL) {
        return -1;
    }
    int it = l->curr->next->element;

    if(l->tail == l->curr->next) {
        l->tail = l->curr;
    }
    l->curr->next = l->curr->next->next;
    l->cnt--;
    return it;
}

void moveToStart(List* l) {
    l->curr = l->head;
}

void moveToEnd(List* l) {
    l->curr = l->tail;
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

void printList(List* l) {
    
}
