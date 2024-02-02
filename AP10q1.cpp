#include <iostream>
#define endl "\n"
#define UNVISITED 0
#define VISITED 1
using namespace std;

typedef struct g{
    int **matrix; // adjacency matrix
    int numEdge; // number of edges
    int n; // number of vertices
    int *Mark; // auxiliary marking array
} G;

typedef struct link {
    int element; // E type, value stored in this link/node
    struct link* next; // Reference to the next link/node
} Link;

typedef struct queue {
    Link* front;
    Link* rear;
    int size; // queue size
} Queue;

G* create_graph(const int n);
int n(G* g);
int e(G* g);
int first(G* g, int v);
int next(G* g, int v, int w);
void graphTraverse(G* g, string traverse);
void DFS(G* g, int v);
void BFS(G* g, int start);
//void toposort(G* g, int v, Stack s);
void setEdge(G* g, int i, int j, int wt);
void delEdge(G* g, int i, int j);
bool isEdge(G* g, int i, int j);
int weight(G* g, int i, int j);
void setMark(G* g, int v, int val);
int getMark(G* g, int v);
Queue* create_queue();
void clear(Queue* q);
void enqueue(Queue* q, int it);
int dequeue(Queue* q);
int frontValue(Queue* q);
int length(Queue* q);
Link* create_link(int it, Link* nextval);
Link* create_link(Link* nextval); 


int main(void) {
    

    return 0;
}


G* create_graph(const int n) {
    G* g = new G;
    g->Mark = new int[n];
    g->matrix = new int[n][n];
    g->numEdge = 0;
    return g;
}

int n(G* g) {
    return g->n;
}

int e(G* g) {
    return g->numEdge;
}

int first(G* g, int v) {
    for(int i = 0; i <= (n(g)-1); i++) {
        if(g->matrix[v][i] != 0) {
            return i;
        }
    }

    return n(g);
}

int next(G* g, int v, int w) {
    for(int i = w + 1; i <= (n(g)-1); i++) {
        if(g->matrix[v][i] != 0) {
            return i;
        }
    }

    return n(g);
}

void graphTraverse(G* g, string traverse) {
    for(int v = 0; v <= (n(g)-1); v++) {
        setMark(g, v, UNVISITED);
    }
    for(int v = 0; v <= (n(g)-1); v++) {
        if(getMark(g, v) == UNVISITED) {
            if(traverse == "BFS") {
                BFS(g, v);
            }
            else if(traverse == "DFS") {
                DFS(g, v);
            }
        }
    }
}

void DFS(G* g, int v) {
    //preVisit(g, v); do something before visiting the node
    setMark(g, v, VISITED);
    int w = first(g, v);
    while(w < n(g)) {
        if(getMark(g, w) == UNVISITED) {
            DFS(g, w);
        }
        w = next(g, v, w);
    }
    //posVisit(g, v); do something after visiting the vertex
}

void BFS(G* g, int start) {
    Queue* Q = create_queue();
    enqueue(Q, start);
    setMark(g, start, VISITED);
    while(length(Q) > 0) {
        int v = dequeue(Q);
        //preVisit(g, v); do something before visiting the vertex
        int w = first(g, v);
        while(w < n(g)) {
            if(getMark(g, w) == UNVISITED) {
                setMark(g, w, VISITED);
                enqueue(Q, w);
            }
            w = next(g, v, w);
        }
        //posVisit(g, v); do something after visiting the vertex
    }
}

void setEdge(G* g, int i, int j, int wt) {
    if(wt == 0) {
        return;
    }
    if(g->matrix[i][j] == 0) {
        g->numEdge++;
    }

    g->matrix[i][j] = wt;
}

void delEdge(G* g, int i, int j) {
    if(g->matrix[i][j] != 0) {
        g->numEdge--;
    }

    g->matrix[i][j] = 0;
}

bool isEdge(G* g, int i, int j) {

}

int weight(G* g, int i, int j) {

}

void setMark(G* g, int v, int val) {
    g->Mark[v] = val;
}

int getMark(G* g, int v) {
    return g->Mark[v];
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
