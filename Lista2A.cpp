#include <iostream>

using namespace std;

typedef struct link {
    char element; // E type, value stored in this link/node
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
void insert(List* l, char item);
void remove(List* l);
void prev(List* l);
void next(List* l);
void printList(List* l);
Link* create_link(char it, Link* nextval);
Link* create_link(Link* nextval);


int main(void) {
    List* l = create_list();
    string input;

    while(cin >> input) {
        for(unsigned int i = 0; i < input.size(); i++) {
            if(input[i] == '[') {
                l->curr = l->head;
            }
            else if(input[i] == ']') {
                l->curr = l->tail;
            }
            else {
                insert(l, input[i]);
                next(l);
            }    

        }
        printList(l);
        //l->curr = l->tail;
        clear(l); // O problema ta no remove
    }


    return 0;
}


Link* create_link(char it, Link* nextval) {
    Link* n = (Link *) new char;
    n->element = it;
    n->next = nextval;
    return n;
}

Link* create_link(Link* nextval) {
    Link* n = (Link *) new char;
    n->next = nextval;
    return n;
}

List* create_list() {
    List* l = (List *) new char;
    l->curr = l->tail = l->head = create_link(NULL); // header node
    l->cnt = 0;
    return l;
}

void clear(List* l) {
    while(l->cnt != 0) {
        remove(l);
    }
}

void insert(List* l, char item) {
    l->curr->next = create_link(item, l->curr->next);
    
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

void printList(List* l) {
    Link *tmp = l->head;
    while(tmp->next != NULL){
        cout << tmp->next->element;
        tmp = tmp->next;
    }
}
