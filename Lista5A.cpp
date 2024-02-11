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
    int *distance;
} G;


G* create_graph(const int n);
int n(G* g);
int e(G* g);
int first(G* g, int v);
int next(G* g, int v, int w);
void graphTraverse(G* g, string traverse, stack<int> &s);
void DFS(G* g, int v);
void BFS(G* g, int start);
void setEdge(G* g, int i, int j, int wt);
void delEdge(G* g, int i, int j);
bool isEdge(G* g, int i, int j);
void setMark(G* g, int v, int val);
int getMark(G* g, int v);
void toposort(G* g, int v, stack<int> &s);
void printStack(stack<int> s, G* g); 


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

    graphTraverse(g, "toposort", s);
    printStack(s, g);


    return 0;
}


G* create_graph(int n) {
    G* g = new G;
    g->n = n+1;
    g->Mark = new int[n+1];
    g->distance = new int[n+1];
    g->matrix = new int*[n+1];
    for(int i = 0; i <= n; i++) {
        g->matrix[i] = new int[n+1];
        for(int j = 0; j <= n; j++) {
            g->matrix[i][j] = 0;
        }
        g->distance[i] = -1;
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
    for(int i = 1; i <= (n(g)-1); i++) {
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

void graphTraverse(G* g, string traverse, stack<int> &s) {
    for(int v = 0; v <= (n(g)-1); v++) {
        setMark(g, v, UNVISITED);
    }
    //int c;
    //cin >> c;
    for(int v = 1; v <= (n(g)-1); v++) {
        if(getMark(g, v) == UNVISITED) {
            if(traverse == "BFS") {
                BFS(g, v);
            }
            else if(traverse == "DFS") {
                DFS(g, v);
            }
            else if(traverse == "toposort") {
                toposort(g, v, s);
            }
        }
    }
}

void DFS(G* g, int v) {
    //cout << v << " "; //preVisit(g, v); do something before visiting the node
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
    g->distance[start] = 0;
    setMark(g, start, VISITED);
    while(Q.size() > 0) {
        int v = Q.front();
        Q.pop();
        //cout << v << " "; //preVisit(g, v); do something before visiting the vertex
        int w = first(g, v);
        while(w < n(g)) {
            if(getMark(g, w) == UNVISITED) {
                setMark(g, w, VISITED);
                Q.push(w);
                g->distance[w] = g->distance[v] + 1;
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
    //g->matrix[j][i] = wt;
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

void setMark(G* g, int v, int val) {
    g->Mark[v] = val;
}

int getMark(G* g, int v) {
    return g->Mark[v];
}

void toposort(G* g, int v, stack<int> &s) {
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

void printStack(stack<int> s, G* g) {
    while(!(s.empty())) {
        cout << s.top() << " ";
        s.pop();
    }
}
