#include <iostream>
#include <queue>
#include <stack>
#define endl "\n"
#define UNVISITED 0
#define VISITED 1
using namespace std;

typedef struct g{
    int **matrix; // adjacency matrix
    int numEdge; // number of edges
    int n; // number of vertices
    int *Mark; // auxiliary marking array
    int *path;
    bool cyclic; // it is true if there is a cycle
} G;


G* create_graph(const int n);
int n(G* g);
int e(G* g);
int first(G* g, int v);
int next(G* g, int v, int w);
void graphTraverse(G* g, stack<int> &s);
void setEdge(G* g, int i, int j, int wt);
void delEdge(G* g, int i, int j);
void setMark(G* g, int v, int val);
int getMark(G* g, int v);
void toposort(G* g, int v, stack<int> &s);
void printStack(stack<int> s); 


int main(void) {
    int n, m;
    stack<int> s;
    cin >> n;
    cin >> m;
    G* g = create_graph(n);

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        setEdge(g, x, y, 1);
    }
   
    graphTraverse(g, s);

    if(g->cyclic == false) {
        printStack(s);
    }
    else {
        cout << "Sandro fails." << endl;
    }   

    return 0;
}


G* create_graph(int n) {
    G* g = new G;
    g->n = n+1;
    g->Mark = new int[n+1];
    g->path = new int[n+1];
    g->matrix = new int*[n+1];
    for(int i = 0; i <= n; i++) {
        g->matrix[i] = new int[n+1];
        for(int j = 0; j <= n; j++) {
            g->matrix[i][j] = 0;
        }
        g->path[i] = 0;
    }
    g->numEdge = 0;
    g->cyclic = false;
    return g;
}

int n(G* g) {
    return g->n;
}

int e(G* g) {
    return g->numEdge;
}

int first(G* g, int v) {
    for(int i = (n(g)-1); i >= 1; i--) {
        if(g->matrix[v][i] == 1) {
            return i;
        }
    }

    return n(g);
}

int next(G* g, int v, int w) {
    for(int i = w - 1; i >= 1; i--) {
        if(g->matrix[v][i] == 1) {
            return i;
        }
    }

    return n(g);
}

void graphTraverse(G* g, stack<int> &s) {
    for(int v = 0; v <= (n(g)-1); v++) {
        setMark(g, v, UNVISITED);
    }
    
    for(int v = (n(g)-1); v >= 1; v--) {
        if(getMark(g, v) == UNVISITED) {
            toposort(g, v, s);
        }
    }
}

void setEdge(G* g, int i, int j, int wt) {
    if(g->matrix[i][j] == 0) {
        g->numEdge++;
    }
    
    g->matrix[i][j] = wt;
    //g->matrix[j][i] = wt;
}

void delEdge(G* g, int i, int j) {
    if(g->matrix[i][j] != 0) {
        g->numEdge--;
    }

    g->matrix[i][j] = 0;
}

void setMark(G* g, int v, int val) {
    g->Mark[v] = val;
}

int getMark(G* g, int v) {
    return g->Mark[v];
}

void toposort(G* g, int v, stack<int> &s) {
    setMark(g, v, VISITED);
    g->path[v] = VISITED;
    int w = first(g, v);
    while(w < n(g) && g->cyclic == false) {
        if(getMark(g, w) == UNVISITED) {
            toposort(g, w, s);
        }
        if(g->cyclic == true) {
            return;
        }
        if(g->path[w] == VISITED) {
            g->cyclic = true;
            return;
        }
        w = next(g, v, w);
    }
    g->path[v] = UNVISITED;
    s.push(v);
}

void printStack(stack<int> s) {
    while(!(s.empty())) {
        cout << s.top() << " ";
        s.pop();
    }
}
