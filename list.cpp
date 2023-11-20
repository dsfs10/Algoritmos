#include "list.h"

typedef struct list {
    int maxSize; int listSize; int curr; int* listArray;
} List;

List* create_list(int size) {
    List* l = (List*) new int[size]; // precisa??
    l->maxSize = size;
    l->listSize = l->curr = 0;
    l->listArray = new int[size];
    return l; 
}

void insert(List* l, int it) {
    if(l->listSize >= l->maxSize) {
        return; // Error
    }
    int i = l->listSize;

    while(i > l->curr) {
        l->listArray[i] = l->listArray[i - 1]; // shift right
        i--;
    }
    
    l->listArray[l->curr] = it;
    l->listSize++;
}

void remove(List* l) {
    if(l->curr < 0 || l->curr >= l->listSize) {
        return; // NULL??
    }
    int it = l->listArray[l->curr];
    int i = l->curr;

    while(i < ((l->listSize) - 1)) {
        l->listArray[i] = l->listArray[i + 1]; // shift left
        i++;
    }
    l->listSize--;
}

void moveToStart(List* l) {
    l->curr = 0;
}

void moveToEnd(List* l) {
    l->curr = l->listSize;
}

void prev(List* l) {
    if(l->curr != 0) {
        l->curr--;
    }
}

void next(List* l) {
    if(l->curr < l->listSize) {
        l->curr++;
    }
}
