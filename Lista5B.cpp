#include <iostream>
#include <map>
#include <iterator>
#include <queue>
#include <stack>
#define endl "\n"
#define UNVISITED 0
#define VISITED 1
using namespace std;

typedef struct g{
    int **matrix; // adjacency matrix
    map<string, int> mp;
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
void graphTraverseBFS(G* g);
void DFS(G* g, int v);
void BFS(G* g, int start);
void setEdge(G* g, int i, int j, int wt);
void delEdge(G* g, int i, int j);
bool isEdge(G* g, int i, int j);
int weight(G* g, int i, int j);
void setMark(G* g, int v, int val);
int getMark(G* g, int v);
void toposort(G* g, int v, stack<int> &s); 


int main(void) {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n, index = 0;
        cin >> n;
        G* g = create_graph(n*3);
        for(int j = 0; j < n; j++) {
            string x, y, z;
            cin >> x >> y >> z;
            if(g->mp.find(x) == g->mp.end())  {  
                g->mp[x] = index;
                index++;
            }
            if(g->mp.find(y) == g->mp.end())  {  
                g->mp[y] = index;
                index++;
            }
            if(g->mp.find(z) == g->mp.end())  {  
                g->mp[z] = index;
                index++;
            }

            setEdge(g, g->mp[x], g->mp[y], 1);
            setEdge(g, g->mp[x], g->mp[z], 1);
            setEdge(g, g->mp[y], g->mp[z], 1);
        }
    
        graphTraverseBFS(g);
        map<string, int>::iterator it = g->mp.begin();
        cout << g->mp.size() << endl;
        for(int i = 0; i < g->mp.size(); i++) {
            cout << g->distance[i] << " ";
        }
        cout << endl;
        while (it != g->mp.end()) {
            cout << it->first << " " << it->second << " ";
            cout << g->distance[it->second] << endl;
            ++it;
        }
    }

    return 0;
}


G* create_graph(int n) {
    G* g = new G;
    g->n = n;
    g->Mark = new int[n];
    g->distance = new int[n];
    g->matrix = new int*[n];
    for(int i = 0; i < n; i++) {
        g->matrix[i] = new int;
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

void graphTraverseBFS(G* g) {
    for(int v = 0; v <= (n(g)-1); v++) {
        setMark(g, v, UNVISITED);
    }

    //for(int v = 0; v <= (n(g)-1); v++) {
        //if(getMark(g, v) == UNVISITED) {
            BFS(g, g->mp["Ahmad"]);   
        //}    
    //}
}

void DFS(G* g, int v) {
    cout << v << " "; //preVisit(g, v); do something before visiting the vertex
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
