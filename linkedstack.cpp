#include <iostream>

using namespace std;

typedef struct link {
    int element; // E type, value stored in this link/node
    struct link* next; // Reference to the next link/node
} Link;

typedef struct stack {
    Link* top; // reference to the first element
    int size; // number of elements
} Stack;


void clear(Stack* s);
void push(Stack* s);
int pop(Stack* s);
int topValue(Stack* s);
int length(Stack* s);
Stack* create_stack();
Link* create_link(int it, Link* nextval);


int main(void) {
    Stack* s = create_stack();
    int comando = 0;

    do {
        cout << "=============MENU=============\n";
        cout << "1) Push\n2) Pop\n3) Top Value\n4) Length\n5) Clear\n6) Leave\n.: ";
        cin >> comando;

        switch(comando) {
            case 1: 
                push(s);
                break;
            case 2:
                pop(s);
                cout << "element popped succefully\n";
                break;
            case 3:
                topValue(s);
                break;
            case 4:
                length(s);
                break;
            case 5:
                clear(s);
                break;
            case 6:
                cout << "Leaving...\n";
                break;
            default:
                cout << "Invalid opperation\n";
                break;
        }
    } while(comando != 6);

    for(int i = 0; i < s->size; i++) {
        delete [] s;
    }
    delete s; 

    return 0;
}


void clear(Stack* s) {
    for(int i = 0; i < s->size; i++) {
        delete [] s;
    }
    delete s;
}

void push(Stack* s) {
    int it = 0;
    cout << "Digite o elemento a ser inserido na pilha: ";
    cin >> it;
    s->top = create_link(it, s->top);
    s->size++;
}

int pop(Stack* s) {
    if(s->top == NULL) {
        cout << "A pilha esta vazia\n";
        return -1; // Error
    }
    int pop = s->top->element;
    s->top = s->top->next;
    s->size--;

    return pop;
}

int topValue(Stack* s) {
    cout << "The top value is: ";
    cout << s->top->element << endl;
    return s->top->element;
}

int length(Stack* s) {
    cout << "The size of the stack is: ";
    cout << s->size << endl;
    return s->size;
}

Stack* create_stack() {
    Stack* s = (Stack *) new int;
    s->top = NULL;
    s->size = 0;
    return s;
}

Link* create_link(int it, Link* nextval) {
    Link* n = (Link *) new int;
    n->element = it;
    n->next = nextval;
    return n;
}
