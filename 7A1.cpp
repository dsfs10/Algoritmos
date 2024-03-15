#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

bool KnightsTour(int**board, int row, int col, vector<int> r, vector<int> c, int numsquares, int move);
bool valid(int** board, int nrow, int ncol);


int main(void) {
    vector<int> r = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> c = {-1, 1, -2, 2, -2, 2, -1, 1};
    vector<vector<int>> board; 
    int n, numsquares; 
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        vector<int> tmp;
        tmp.assign(x+y, 0);
        cin >> x >> y;
        numsquares = numsquares + y;
        //board[i] = new int[x+y];
        board[i] = tmp;
        cout << "teste" << endl;
        for(int j = 0; j < x; j++) {
            board[i][j] = -1;
        }
        for(int k = 0; k < x+y; k++) {
            cout << board[i][k] << " ";
        }
        cout << endl;
    }
    board[0][0] = 1;

    //KnightsTour(board, 0, 0, r, c, numsquares, 1);

    return 0;
}


bool KnightsTour(int** board, int row, int col, vector<int> r, vector<int> c,int numsquares, int move) {
    if(move == numsquares) { // 8x8 chessboard
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        
        return true;
    }
    else {
        for(int i = 0; i < r.size(); i++) {
            int nrow = row + r[i];
            int ncol = col + c[i];
            if(valid(board, nrow, ncol)) {
                move++;
                board[nrow][ncol] = move;
                if(KnightsTour(board, nrow, ncol, r, c, numsquares, move)) {
                    return true;
                }
                move--;
                board[nrow][ncol] = 0;
            }
        }
    }

    return false;
}

bool valid(int** board, int nrow, int ncol) {
    if((nrow >= 0) && (nrow < 8) && (ncol >= 0) && (ncol < 8) && (board[nrow][ncol] == 0)) {
        return true;
    }
    
    return false;
}
