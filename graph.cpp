#include <iostream>
#define endl "\n"
using namespace std;

typedef struct g{
    int **matrix; // adjacency matrix
    int numEdge; // number of edges
    int *Mark; // auxiliary marking array
} G;

G* create_graph(const int n);
int n(G* g);
int e(G* g);
int first(G* g, int v);
int next(G* g, int v, int w);
void setEdge(G* g, int i, int j, int wt);
void delEdge(G* g, int i, int j);
bool isEdge(G* g, int i, int j);
int weight(G* g, int i, int j);
void setMark(G* g, int v, int val);
int getMark(G* g, int v); 


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

}

int e(G* g) {

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

}

int getMark(G* g, int v) {

}
