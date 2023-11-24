#include <iostream>
#include <string>

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
void push(Stack* s, int it);
int pop(Stack* s);
int topValue(Stack* s);
int length(Stack* s);
Stack* create_stack();
Link* create_link(int it, Link* nextval);


int main(void) {
    string input;
    Stack* s = create_stack();

    do {
        cin >> input;
        if(input != "+" && input != "-" && input != "*" && input != "END" && input != "EOF") {
            int it = stoi(input);
            push(s, it);
        }    

        else if(input == "+") {
            int v1, v2;
            v2 = pop(s);
            v1 = pop(s);
            push(s, v1+v2);

        }
        else if(input == "*") {
            int v1, v2;
            v2 = pop(s);
            v1 = pop(s);
            push(s, v1*v2);
        }
        else if(input == "-") {
            int v1, v2;
            v2 = pop(s);
            v1 = pop(s);
            push(s, v1-v2);
        }
        else if(input == "END" && s->size > 0) {
            int r = topValue(s);
            cout << r << endl;
            pop(s);
        }
    } while(input != "EOF");


    return 0;
}


void clear(Stack* s) {
    while(s->size != 0) {
        pop(s);
    }
}

void push(Stack* s, int it) {
    s->top = create_link(it, s->top);
    s->size++;
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

Link* create_link(int it, Link* nextval) {
    Link* n = (Link *) new int;
    n->element = it;
    n->next = nextval;
    return n;
}
