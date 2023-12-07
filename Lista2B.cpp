#include <iostream>
#define endl "\n"

using namespace std;

typedef struct link {
    char element; // E type, value stored in this link/node
    struct link* next; // Reference to the next link/node
} Link;

typedef struct stack {
    Link* top; // reference to the first element
    int size; // number of elements
} Stack;


void clear(Stack* s);
void push(Stack* s, char it);
char pop(Stack* s);
char topValue(Stack* s);
int length(Stack* s);
Stack* create_stack();
Link* create_link(char it, Link* nextval);
void printStack(Stack* s);


int main(void) {
    string input;
    Stack* s = create_stack();
    cin >> input;

    for(unsigned int i = 0; i < input.size(); i++) {
        push(s, input[i]);

        if(s->size >= 3 && s->top->element == 'C' && s->top->next->element == 'B' && s->top->next->next->element == 'A') {
            for(int j = 0; j < 3; j++) {
                pop(s);
            }                
        }
    }

    printStack(s);
    

    return 0;
}


void clear(Stack* s) {
    while(s->size != 0) {
        pop(s);
    }
}

void push(Stack* s, char it) {
    s->top = create_link(it, s->top);
    s->size++;
}

char pop(Stack* s) {
    Link* t = s->top;
    if(s->top == NULL) {
        exit(1); // Error
    }
    char pop = s->top->element;
    s->top = s->top->next;
    s->size--;
    delete t;

    return pop;
}

char topValue(Stack* s) {
    return s->top->element;
}

int length(Stack* s) {
    return s->size;
}

Stack* create_stack() {
    Stack* s = (Stack *) new int;
    s->top = NULL;
    s->size = 0;
    return s;
}

Link* create_link(char it, Link* nextval) {
    Link* n = (Link *) new char;
    n->element = it;
    n->next = nextval;
    return n;
}

void printStack(Stack* s) {
    char aux[s->size];
    int i = (s->size - 1);
    int tam = s->size;

    while(s->size != 0) {
        aux[i] = s->top->element;
        pop(s);
        i--;
    }

    for(int j = 0; j < tam; j++) {    
        cout << aux[j];
    }
    cout << endl;    
}
