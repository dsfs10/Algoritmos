#include <iostream>

using namespace std;

typedef struct link {
    int element; // E type, value stored in this link/node
    struct link* next; // Reference to the next link/node
} Link;

typedef struct queue {
    Link* front;
    Link* rear;
    int size; // queue size
} Queue;

Queue* create_queue();
void clear(Queue* q);
void enqueue(Queue* q, int it);
int dequeue(Queue* q);
int frontValue(Queue* q);
int length(Queue* q);
Link* create_link(int it, Link* nextval);
Link* create_link(Link* nextval);


int main(void) {
    Queue* q = create_queue();
    int comando = 0;

    do { // MENU
        cout << "=============MENU=============\n";
        cout << "1) Enqueue\n2) Dequeue\n3) Front Value\n4) Length\n5) Clear\n6) Leave\n.: ";
        cin >> comando;

        switch(comando) {
            case 1:
                int it;
                cout << "Digite o elemento a ser inserido na fila: ";
                cin >> it;
                enqueue(q, it);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                frontValue(q); 
                break;
            case 4:
                length(q);
                break;
            case 5:
                clear(q);
                break;
            case 6:
                cout << "Leaving..." << endl;
                break;
            default:
                cout << "Opcao Invalida" << endl;
                break;        
        }
    } while(comando != 6);

    clear(q);

    return 0;
}

Queue* create_queue() {
    Queue* q = (Queue *) new int;
    q->front = q->rear = create_link(NULL); //header node
    q->size = 0;
    return q;
}

void clear(Queue* q) {
       Link *temp = q->front;
       Link *next = temp->next;

       while(temp->next != NULL) {
        next = temp->next;
        delete temp;
        temp = next;
       }
       delete temp;
       delete q;
}

void enqueue(Queue* q, int it) {
    q->rear->next = create_link(it, NULL);
    q->rear = q->rear->next;
    if(q->size == 0) {
        q->front = q->rear;
    }
    q->size++;
}

int dequeue(Queue* q) {
    if(q->size == 0) {
        return -1; // Error
    }
    int it = q->front->next->element;
    q->front->next = q->front->next->next;

    if(q->front->next == NULL) {
        q->rear = q->front;
    }
    q->size--;

    return it;
}

int frontValue(Queue* q) {
    cout << q->front->element << endl;
    return q->front->element;
}

int length(Queue* q) {
    cout << q->size << endl;
    return q->size;
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
