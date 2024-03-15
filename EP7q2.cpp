#include <iostream>
#define endl "\n"
using namespace std;

int max(int a, int b);
int knapsack(int n, int W, int* w, int* v, int** F);
int MFKnapsack(int i, int j, int* w, int* v, int** F); 


int main(void) {
    int c;
    cin >> c;
    for(int k = 0; k < c; k++) {    
        int W, n, *w, *v, **F;
        cin >> W >> n;
        w = new int[n+1];
        v = new int[n+1];
        F = new int*[n+1];
        F[0] = new int[W+1];

        for(int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            w[i] = x;
            v[i] = y;

            F[i] = new int[W+1];
            for(int j = 1; j <= W; j++) {    
                F[i][j] = -1;
            }
        }

        int m = MFKnapsack(n, W, w, v, F); // top-down knapsack
        cout << m << endl;
    }    

    return 0;
}

int max(int a, int b) {
    if(a > b) {
        return a;
    }
    else {
        return b;
    }
}

int knapsack(int n, int W, int* w, int* v, int** F) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            if(i == 0 || j == 0) {
                F[i][j] = 0;
            }
            else if(w[i] <= j) {
                F[i][j] = max(F[i-1][j], v[i] + F[i-1][j-w[i]]);
            }
            else {
                F[i][j] = F[i-1][j];
            }
        }
    }

    return F[n][W];
}

int MFKnapsack(int i, int j, int* w, int* v, int** F) {
    int value;
    if(F[i][j] < 0) {
        if(j < w[i]) {
            value = MFKnapsack(i-1, j, w, v, F);
        }
        else {
            value = max(MFKnapsack(i-1, j, w, v, F), v[i] + MFKnapsack(i-1, j-w[i], w, v, F));
        }
        F[i][j] = value;
    }

    return F[i][j];
}
