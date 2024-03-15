#include <iostream>
#include <vector>
#include <iterator>
#define endl "\n"
using namespace std;

bool KnightsTour(vector<vector<int>> board, int row, int col, vector<int> r, vector<int> c, int n, int numsquares, int move);
bool valid(vector<vector<int>> board, int nrow, int ncol, int n);


int main(void) {
    vector<int> r = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> c = {-1, 1, -2, 2, -2, 2, -1, 1};
    vector<vector<int>> board; 
    int n, numsquares; 
    cin >> n;
    //board = new vector<vector<int>>;
    vector<vector<int>>::iterator it;
    it = board.begin();
    for(it; it != board.end(); it++) {
        int x, y;
        cin >> x >> y;
        (*it).assign(x+y, 0);
        numsquares = numsquares + y;
        //board[i] = new int[x+y];
        cout << "teste" << endl;
        //board[i] = tmp;
        for(int j = 0; j < x; j++) {
            (*it)[j] = -1;
        }
        for(int k = 0; k < x+y; k++) {
            cout << (*it)[k] << " ";
        }
        cout << endl;
    }
    board[0][0] = 1;

    //KnightsTour(board, 0, 0, r, c, numsquares, 1);

    return 0;
}


bool KnightsTour(vector<vector<int>> board, int row, int col, vector<int> r, vector<int> c, int n, int numsquares, int move) {
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
            if(valid(board, nrow, ncol, n)) {
                move++;
                board[nrow][ncol] = move;
                if(KnightsTour(board, nrow, ncol, r, c, n, numsquares, move)) {
                    return true;
                }
                move--;
                board[nrow][ncol] = 0;
            }
        }
    }

    return false;
}

bool valid(vector<vector<int>> board, int nrow, int ncol, int n) {
    if((nrow >= 0) && (nrow < n) && (ncol >= 0) && (ncol < board[nrow].size()) && (board[nrow][ncol] == 0)) {
        return true;
    }
    
    return false;
}
