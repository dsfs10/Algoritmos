#include <iostream>

using namespace std;

void BinarySearch(string estudante[], string procura, int e);

int main(void) {
    int e, q;
    cin >> e;
    string estudante[e];

    for(int i = 0; i < e; i++) {
        cin >> estudante[i];
    }
    cin >> q;

    for(int i = 0; i < q; i++) {
        string procura;
        cin >> procura;

        BinarySearch(estudante, procura, e);
    }


    return 0;
}


void BinarySearch(string estudante[], string procura, int e) {
    int l = 0, r = e - 1;

    while(l <= r) {
        int m = (l + r) / 2;
        if(procura == estudante[m]) {
            cout << "+" << endl;
            return;
        }
        else if(procura < estudante[m]) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    cout << "-" << endl;
    return;
}
