#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

bool KnightsTour(int**board, int row, int col, vector<int> r, vector<int> c, int numsquares, int move, int &best, int n, int* sizes);
bool valid(int** board, int nrow, int ncol, int n, int* sizes);


int main(void) {
    int n, C = 0;
    do {    
        vector<int> r = {-2, -2, -1, -1, 1, 1, 2, 2};
        vector<int> c = {-1, 1, -2, 2, -2, 2, -1, 1};
        int numsquares = 0, best = 0; 
        cin >> n;
        if(n == 0) {
            return 0;
        }
        C++;
        int* sizes = new int[n];
        int** board = new int*[n]; 

        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            sizes[i] = x + y;
            numsquares = numsquares + y;
            board[i] = new int[x+y]();

            for(int j = 0; j < x; j++) {
                board[i][j] = -1;
            }
        }
        board[0][0] = 1;

        if(KnightsTour(board, 0, 0, r, c, numsquares, 1, best, n, sizes)) {
            cout << "Case " << C << ", 0 squares can not be reached." << endl;
        }
        else {
            if((numsquares - best) == 1) {
                cout << "Case " << C << ", 1 square can not be reached." << endl;
            }
            else {
                cout << "Case " << C << ", " << numsquares - best << " squares can not be reached." << endl;
            }
        }
    } while(n != 0);

    return 0;
}


bool KnightsTour(int** board, int row, int col, vector<int> r, vector<int> c,int numsquares, int move, int &best, int n, int* sizes) {
    if(move == numsquares) { 
        return true;
    }
    else {
        for(int i = 0; i < r.size(); i++) {
            int nrow = row + r[i];
            int ncol = col + c[i];
            if(valid(board, nrow, ncol, n, sizes)) {
                move++;
                board[nrow][ncol] = move;
                if(KnightsTour(board, nrow, ncol, r, c, numsquares, move, best, n, sizes)) {
                    return true;
                }
                move--;
                board[nrow][ncol] = 0;
            }
        }
        if(move > best) {
            best = move;
        }
    }

    return false;
}

bool valid(int** board, int nrow, int ncol, int n, int* sizes) {
    if((nrow >= 0) && (nrow < n) && (ncol >= 0) && (ncol < sizes[nrow]) && (board[nrow][ncol] == 0)) {
        return true;
    }
    
    return false;
}
