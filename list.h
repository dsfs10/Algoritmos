#ifndef _LIST_H
#define _LIST_H

//#include <iostream>

typedef struct link Link;
typedef struct list List;
List* create_list(); // Creates a new list // Lembrar do 'int size' como parametro para array list
void clear(List* l);
void insert(List* l, int item);
void remove(List* l);
void moveToStart(List* l);
void moveToEnd(List* l);
void prev(List* l);
void next(List* l);
void printList(List* l);
Link* create_link(int it, Link* nextval);
Link* create_link(Link* nextval);

// ...
#endif
