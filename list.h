#ifndef _LIST_H
#define _LIST_H

//#include <iostream>

typedef struct list List;
List* create_list(int size); // Creates a new list
void clear(List* l);
void insert(List* l, int item);
void remove(List* l);
void moveToStart(List* l);
void moveToEnd(List* l);
void prev(List* l);
void next(List* l);
void printList(List* l);
void currentpos(List* l);

// ...
#endif
