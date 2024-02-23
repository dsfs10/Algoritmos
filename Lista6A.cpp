#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <stack>
#include <limits>
#define endl "\n"
#define UNVISITED 0
#define VISITED 1
using namespace std;

typedef struct g{
    list<pair<int, int>> *l; // adjacency list
    int numEdge; // number of edges
    int n; // number of vertices
    int *Mark; // auxiliary marking array
    int *D;
} G;


G* create_graph(const int n);
int n(G* g);
int e(G* g);
int first(G* g, int v);
int next(G* g, int v, int w);
int weight(G* g, int i, int j);
void graphTraverse(G* g, int v);
void DFS(G* g, int v);
void BFS(G* g, int start);
void Dijkstra(G* g, int s);
void setEdge(G* g, int i, int j, int w);
void delEdge(G* g, int i, int j);
bool isEdge(G* g, int i, int j);
void setMark(G* g, int v, int val);
int getMark(G* g, int v);
void toposort(G* g, int v, stack<int> &s);
void printStack(stack<int> s); 


int main(void) {
    int c, n, m, s, t;
    cin >> c;

    for(int i = 0; i < c; i++) {
        cin >> n >> m >> s >> t;
        G* g = create_graph(n);
        for(int j = 0; j < m; j++) {
            int x, y, w;
            cin >> x >> y >> w;

            setEdge(g, x, y, w);
        }
        graphTraverse(g, s);
        if(g->D[t] < numeric_limits<int>::max()) {    
            cout << "Case #" << i+1 << ": " << g->D[t] << endl;
        }
        else {
            cout << "Case #" << i+1 << ": unreachable" << endl;
        }    
    }

    return 0;
}


G* create_graph(int n) {
    G* g = new G;
    g->n = n;
    g->Mark = new int[n];
    g->D = new int[n];
    g->l = new list<pair<int, int>>[n];
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

int next(G* g, int v, int w) {
    list<pair<int, int>>::iterator it;
    if(!(g->l[v].empty())) {
        for(it = g->l[v].begin(); it != g->l[v].end(); it++) {  
            if((*it).first == w && (*it).first != g->l[v].back().first) {
                it++;
                return (*it).first;
            }
        }
    }

    return n(g);
}

int weight(G* g, int i, int j) {
    list<pair<int, int>>::iterator it;
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

void Dijkstra(G* g, int s) {
    int *P = new int[g->n];
    int p, v;
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
        while(w < n(g)) {
            if(getMark(g, w) != VISITED && g->D[w] > g->D[v] + weight(g, v, w)) {
                g->D[w] = g->D[v] + weight(g, v, w);
                H.push(make_pair(g->D[w], make_pair(v, w)));    
            }
            w = next(g, v, w);
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
    int w = weight(g, i, j);
    g->l[i].remove(make_pair(j, w));
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

void printStack(stack<int> s) {
    while(!(s.empty())) {
        cout << s.top() << " ";
        s.pop();
    }
}
