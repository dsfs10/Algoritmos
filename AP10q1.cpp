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
} G;


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
void toposort(G* g, int v, stack<int> s);


int main(void) {
    int n, q;
    cin >> n;
    cin >> q;
    G* g = create_graph(n);

    for(int i = 0; i < q; i++) {
        string comando;
        cin >> comando;

        if(comando == "add") {
            int x, y;
            cin >> x;
            cin >> y;
            setEdge(g, x, y, 1);
        }
        else if(comando == "BFS") {
            graphTraverse(g, "BFS");
            cout << endl;
        }
        else if(comando == "DFS") {
            graphTraverse(g, "DFS");
            cout << endl;
        }
    }

    return 0;
}


G* create_graph(int n) {
    G* g = new G;
    g->n = n;
    g->Mark = new int[n];
    g->matrix = new int*[n];
    for(int i = 0; i < n; i++) {
        g->matrix[i] = new int;
    }
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
    int c;
    cin >> c;
    for(int v = c; v <= (n(g)-1); v++) {
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
    cout << v << " "; //preVisit(g, v); do something before visiting the node
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
    queue<int> Q;
    Q.push(start);
    setMark(g, start, VISITED);
    while(Q.size() > 0) {
        int v = Q.front();
        Q.pop();
        cout << v << " "; //preVisit(g, v); do something before visiting the vertex
        int w = first(g, v);
        while(w < n(g)) {
            if(getMark(g, w) == UNVISITED) {
                setMark(g, w, VISITED);
                Q.push(w);
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
    g->matrix[j][i] = wt;
}

void delEdge(G* g, int i, int j) {
    if(g->matrix[i][j] != 0) {
        g->numEdge--;
    }

    g->matrix[i][j] = 0;
}

bool isEdge(G* g, int i, int j) {
    return true;
}

int weight(G* g, int i, int j) {
    return g->matrix[i][j];
}

void setMark(G* g, int v, int val) {
    g->Mark[v] = val;
}

int getMark(G* g, int v) {
    return g->Mark[v];
}

void toposort(G* g, int v, stack<int> s) {
    setMark(g, v, VISITED);
    int w = first(g, v);
    while(w < n(g)) {
        if(getMark(g, w) == UNVISITED) {
            toposort(g, w, s);
        }
        w = next(g, v, w);
    }
    s.push(v);
}
