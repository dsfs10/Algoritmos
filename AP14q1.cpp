#include <iostream>
#include <climits>
#define endl "\n"
using namespace std;


int max(int a, int b);
int CoinRow(int* C, int n);
int ChangeMaking(int* D, int n, int m);


int main(void) {
    int c;
    cin >> c;

    for(int i = 0; i < c; i++) {
        int n, *C;
        cin >> n;
        C = new int[n+1];

        for(int j = 1; j <= n; j++) {
            cin >> C[j];
        }

        int tmp = CoinRow(C, n);
        cout << tmp << endl;
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

int CoinRow(int* C, int n) { // C[1..n]
    int *F = new int[n+1];
    F[0] = 0;
    F[1] = C[1];

    for(int i = 2; i <= n; i++) {
        F[i] = max(C[i] + F[i-2], F[i-1]);
    }

    return F[n];
}

int ChangeMaking(int* D, int n, int m) {
    int* F = new int[n+1];
    F[0] = 0;

    for(int i = 1; i <= n; i++) {
        int tmp = INT_MAX;//numeric_limits<int>::max();
        int j = 1;

        while(j <= m && i >= D[j]) {
            tmp = min(F[i-D[j]], tmp);
            j++;
        }
        F[i] = tmp + 1;
    }

    return F[n];
}

