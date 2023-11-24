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


int main() {
    List* l = create_list();
    int comando = 0;

    do { // MENU
        cout << "=============MENU=============\n";
        cout << "1) Insert\n2) Remove\n3) Move to Start\n4) Move to End\n5) Previous\n6) Next\n7) Print List\n8) Clear\n9) Leave\n.: ";
        cin >> comando;

        switch(comando) {
            case 1:
                int it;
                cout << "Digite o elemento a ser inserido na lista: ";
                cin >> it;
                insert(l, it);
                break;
            case 2:
                remove(l);
                break;
            case 3:
                moveToStart(l);
                break;
            case 4:
                moveToEnd(l);
                break;
            case 5:
                prev(l);
                break;
            case 6:
                next(l);
                break;
            case 7:
                printList(l);
                break;
            case 8:
                clear(l);
                break;
            case 9:
                cout << "Leaving..." << endl;
                break;
            default:
                cout << "Opcao Invalida" << endl;
                break;        
        }
    } while(comando != 9);

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
    cout << l->tail->element << endl;
}
