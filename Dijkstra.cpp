#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <stack>
#define endl "\n"
#define UNVISITED 0
#define VISITED 1
#define INFINITE 10000
using namespace std;

typedef struct g{
    list<int> *l; // adjacency list
    int numEdge; // number of edges
    int n; // number of vertices
    int *Mark; // auxiliary marking array
} G;


G* create_graph(const int n);
int n(G* g);
int e(G* g);
int first(G* g, int v);
int next(G* g, int v, int w);
void graphTraverse(G* g, string traverse, stack<int> &s);
void DFS(G* g, int v);
void BFS(G* g, int start);
void Dijkstra(G* g, int s, int* D);
void setEdge(G* g, int i, int j);
void delEdge(G* g, int i, int j);
bool isEdge(G* g, int i, int j);
void setMark(G* g, int v, int val);
int getMark(G* g, int v);
void toposort(G* g, int v, stack<int> &s);
void printStack(stack<int> s, G* g); 


int main(void) {
    

    return 0;
}


G* create_graph(int n) {
    G* g = new G;
    g->n = n;
    g->Mark = new int[n];
    g->l = new list<int>[n];
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
    if(g->l[v].empty()) {
        return n(g);
    }

    return g->l[v].front();
}

int next(G* g, int v, int w) {
    list<int>::iterator it;
    if(!(g->l[v].empty())) {
        for(it = g->l[v].begin(); it != g->l[v].end(); it++) {  
            if(*it == w && *it != g->l[v].back()) {
                it++;
                return *it;
            }
        }
    }

    return n(g);
}

void graphTraverse(G* g, string traverse, stack<int> &s) {
    for(int v = 0; v <= (n(g)-1); v++) {
        setMark(g, v, UNVISITED);
    }
    // int c;
    // cin >> c;
    for(int v = 0; v <= (n(g)-1); v++) {
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
    queue<int> Q;
    Q.push(start);
    setMark(g, start, VISITED);
    while(Q.size() > 0) {
        int v = Q.front();
        Q.pop();
        //preVisit(g, v); do something before visiting the vertex
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

void Dijkstra(G* g, int s, int* D) {
    int P[g->n];
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> H;
    for(int i = 0; i <= (n(g)-1); i++) {
        D[i] = INFINITE;
        P[i] = -1;
    }
    H.push(make_pair(0, make_pair(s, s)));
    D[s] = 0;
    
    for(int i = 0; i <= (n(g)-1); i++) {
        do {
            pair<int, pair<int,int>> tmp = H.pop();
        } while(!(getMark(g, v) = UNVISITED));
    }
}

void setEdge(G* g, int i, int j) {
    g->numEdge++;

    g->l[i].push_back(j);
    //g->l[j].push_back(i); // only for undirected graphs
}

void delEdge(G* g, int i, int j) {
    g->numEdge--;

    g->l[i].remove(j);
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
