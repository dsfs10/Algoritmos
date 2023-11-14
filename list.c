#include "list.h"

typedef struct list {
    int maxSize; int listSize; int curr; int* listArray;
} List;

List* create_list(int size) {
    List* l = (List*) malloc(sizeof(List));
    l->maxSize = size;
    l->listSize = l->curr = 0;
    l->listArray = (int*) malloc(size * sizeof(int));
    return l; 
}
