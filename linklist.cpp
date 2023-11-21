#include <iostream>

using namespace std;

typedef struct link {
    int element; // E type, value stored in this link/node
    Link next; // Reference to the next link/node
} Link;

typedef struct list {
    Link head;
    Link tail;
    Link curr;
    int cnt; // list size
} List;

Link create_link(Link nextval) {
    Link n;
    n.next = nextval;
    return n;
}

List* create_list() {
    //List* l = (List *) new int;
    l->curr = l->tail = l->head = create_link(NULL); // header node
    l.cnt ← 0;
    return l;
}

void clear(List* l) {

}

void insert(List* l, int item) {

}

void remove(List* l) {

}

void moveToStart(List* l) {

}

void moveToEnd(List* l) {

}

void prev(List* l) {

}

void next(List* l) {

}

void printList(List* l) {

}
