#include <iostream>

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
void printStack();
int pop(Stack* s);
int topValue(Stack* s);
int length(Stack* s);
Stack* create_stack();
Link* create_link(char it, Link* nextval);


int main(void) {
    string input;
    Stack* s = create_stack();
    cin >> input;

    for(unsigned int i = 0; i < input.size(); i++) {
        if(input[i] == 'C' && input[i-1] == 'B' && input[i-2] == 'A') {
            for(int j = 0; j < 3; j++) {
                pop(s);
            }
        }
        else {
            push(s, input[i]);
        }
    }

    printStack();

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

void printStack(Stack* s) {
    Link *tmp = s->top;
    while(tmp->next != NULL){
        cout << tmp->next->element;
        tmp = tmp->next;
    }
}

int pop(Stack* s) {
    Link* t = s->top;
    if(s->top == NULL) {
        return -1; // Error
    }
    int pop = s->top->element;
    s->top = s->top->next;
    s->size--;
    delete t;

    return pop;
}

int topValue(Stack* s) {
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
    Link* n = (Link *) new int;
    n->element = it;
    n->next = nextval;
    return n;
}
