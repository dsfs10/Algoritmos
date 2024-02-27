#include <iostream>
#include <list>
#include <limits>
#include <iterator>
#include <queue>
#include <stack>
#define endl "\n"
#define UNVISITED 0
#define VISITED 1
using namespace std;

typedef struct g{
    vector<pair<int, int>> *l; // adjacency list
    int numEdge; // number of edges
    int n; // number of vertices
    int *Mark; // auxiliary marking array
    int *D; // distance from a vertex to all the others
    int **Dm; // matrix of distances
} G;


G* create_graph(const int n);
int n(G* g);
int e(G* g);
int first(G* g, int v);
int next(G* g, int v, vector<pair<int, int>>::iterator &it);
int weight(G* g, vector<pair<int, int>>::iterator it);
int weight(G* g, int i, int j);
void graphTraverse(G* g, int v);
void DFS(G* g, int v);
void BFS(G* g, int start);
void Dijkstra(G* g, int s);
void Floyd(G* g);
void BellmanFord(G* g, int s);
void setEdge(G* g, int i, int j, int w);
void delEdge(G* g, int i, int j);
void setMark(G* g, int v, int val);
int getMark(G* g, int v);
void toposort(G* g, int v, stack<int> &s);
void printStack(stack<int> s); 


int main(void) {
    

    return 0;
}


G* create_graph(int n) {
    G* g = new G;
    g->n = n;
    g->Mark = new int[n];
    g->D = new int[n];
    g->Dm = new int*[n];
    g->l = new vector<pair<int, int>>[n];
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

    return g->l[v].front().first;
}

int next(G* g, int v, vector<pair<int, int>>::iterator &it) {
    it++;
    if(it == g->l[v].end()) {
        return n(g);
    }
    else {
        return (*it).first;
    }
}

int weight(G* g, vector<pair<int, int>>::iterator it) {
    return (*it).second;
}

int weight(G* g, int i, int j) {
    vector<pair<int, int>>::iterator it;
    if(!(g->l[i].empty())) {
        for(it = g->l[i].begin(); it != g->l[i].end(); it++) {  
            if((*it).first == j) {
                return (*it).second;
            }
        }
    }

    return 0;
}

void graphTraverse(G* g, int v) {
    for(int i = 0; i <= (n(g)-1); i++) {
        setMark(g, i, UNVISITED);
    }
    
    if(getMark(g, v) == UNVISITED) {
        Dijkstra(g, v);
    }
}

void DFS(G* g, int v) {
    //preVisit(g, v); do something before visiting the node
    vector<pair<int, int>>::iterator it;
    setMark(g, v, VISITED);
    int w = first(g, v);
    it = g->l[v].begin();
    while(w < n(g)) {
        if(getMark(g, w) == UNVISITED) {
            DFS(g, w);
        }
        w = next(g, v, it);
    }
    //posVisit(g, v); do something after visiting the vertex
}

void BFS(G* g, int start) {
    queue<int> Q;
    vector<pair<int, int>>::iterator it;
    Q.push(start);
    setMark(g, start, VISITED);
    while(Q.size() > 0) {
        int v = Q.front();
        Q.pop();
        //preVisit(g, v); do something before visiting the vertex
        int w = first(g, v);
        it = g->l[v].begin();
        while(w < n(g)) {
            if(getMark(g, w) == UNVISITED) {
                setMark(g, w, VISITED);
                Q.push(w);
            }
            w = next(g, v, it);
        }
        //posVisit(g, v); do something after visiting the vertex
    }
}

void Dijkstra(G* g, int s) {
    int *P = new int[g->n];
    int p, v;
    vector<pair<int, int>>::iterator it;
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> H;
    for(int i = 0; i <= (n(g)-1); i++) {
        g->D[i] = numeric_limits<int>::max();
        P[i] = -1;
    }
    H.push(make_pair(0, make_pair(s, s)));
    g->D[s] = 0;
    
    for(int i = 0; i <= (n(g)-1); i++) {
        do {
            if(H.empty()) {
                return;
            }
            pair<int, pair<int,int>> tmp = H.top();
            H.pop();
            p = tmp.second.first;
            v = tmp.second.second;
        } while(!(g->Mark[v] == UNVISITED));
        setMark(g, v, VISITED);
        P[v] = p;
        int w = first(g, v);
        it = g->l[v].begin();
        while(w < n(g)) {
            if(getMark(g, w) != VISITED && g->D[w] > g->D[v] + weight(g, it)) {
                g->D[w] = g->D[v] + weight(g, it);
                H.push(make_pair(g->D[w], make_pair(v, w)));    
            }
            w = next(g, v, it);
        }
    }
}

void Floyd(G* g) {
    for(int i = 0; i <= (n(g)-1); i++) {
        for(int j = 0; j <= (n(g)-1); j++) {
            if(i == j) {
                g->Dm[i][j] = 0;
            }
            else if(weight(g, i, j) != 0) {
                g->Dm[i][j] = weight(g, i, j);
            }
            else {
                g->Dm[i][j] = numeric_limits<int>::max();
            }
        }
    }

    for(int k = 0; k <= (n(g)-1); k++) {
        for(int i = 0; i <= (n(g)-1); i++) {
            for(int j = 0; j <= (n(g)-1); j++) {
                if(g->Dm[i][k] != numeric_limits<int>::max() && g->Dm[k][j] != numeric_limits<int>::max() && g->Dm[i][j] > g->Dm[i][k] + g->Dm[k][j]) {
                    g->Dm[i][j] = g->Dm[i][k] + g->Dm[k][j];
                }
            }
        }
    }
}

void BellmanFord(G* g, int s) {
    for(int i = 0; i <= (n(g)-1); i++) {
        g->D[i] = numeric_limits<int>::max();
    }
    g->D[s] = 0;
    vector<pair<int, int>>::iterator it;

    for(int k = 0; k <= (n(g)-2); k++) {
        for(int i = 0; i <= (n(g)-1); i++) {
            int j = first(g, i);
            it = g->l[i].begin();
            while(j < n(g)) {
                if(g->D[j] > g->D[i] + weight(g, i, j)) {
                    g->D[j] = g->D[i] + weight(g, i, j);
                }
                j = next(g, i, it);
            }
        }
    }

    for(int i = 0; i <= (n(g)-1); i++) {
        int j = first(g, i);
        it = g->l[i].begin();
        while(j < n(g)) {
            if(g->D[j] > g->D[i] + weight(g, i, j)) {
                return; // negative cycle detected
            }
            j = next(g, i, it);
        }
    }
}

void setEdge(G* g, int i, int j, int w) {
    g->numEdge++;

    g->l[i].push_back(make_pair(j, w));
    g->l[j].push_back(make_pair(i, w)); // only for undirected graphs
}

void delEdge(G* g, int i, int j) {
    g->numEdge--;
    //int w = weight(g, i, j);
    //g->l[i].remove(make_pair(j, w));
}

void setMark(G* g, int v, int val) {
    g->Mark[v] = val;
}

int getMark(G* g, int v) {
    return g->Mark[v];
}

void toposort(G* g, int v, stack<int> &s) {
    vector<pair<int, int>>::iterator it;
    setMark(g, v, VISITED);
    int w = first(g, v);
    it = g->l[v].begin();
    while(w < n(g)) {
        if(getMark(g, w) == UNVISITED) {
            toposort(g, w, s);
        }
        w = next(g, v, it);
    }
    s.push(v);
}

void printStack(stack<int> s) {
    while(!(s.empty())) {
        cout << s.top() << " ";
        s.pop();
    }
}
