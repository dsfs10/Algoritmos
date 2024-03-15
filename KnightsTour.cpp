#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

bool KnightsTour(int**visited, int row, int col, vector<int> pathRow, vector<int> pathCol, int move);
bool valid(int** visited, int nrow, int ncol);


int main(void) {
    vector<int> pathRow = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> pathCol = {-1, 1, -2, 2, -2, 2, -1, 1};
    int** visited = new int*[8];
    for(int i = 0; i < 8; i++) {
        visited[i] = new int[8];
    }
    visited[0][0] = 1;

    KnightsTour(visited, 0, 0, pathRow, pathCol, 1);

    return 0;
}


bool KnightsTour(int** visited, int row, int col, vector<int> pathRow, vector<int> pathCol, int move) {
    if(move == 64) { // 8x8 chessboard
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
        
        return true;
    }
    else {
        for(int i = 0; i < pathRow.size(); i++) {
            int nrow = row + pathRow[i];
            int ncol = col + pathCol[i];
            if(valid(visited, nrow, ncol)) {
                move++;
                visited[nrow][ncol] = move;
                if(KnightsTour(visited, nrow, ncol, pathRow, pathCol, move)) {
                    return true;
                }
                move--;
                visited[nrow][ncol] = 0;
            }
        }
    }

    return false;
}

bool valid(int** visited, int nrow, int ncol) {
    if((nrow >= 0) && (nrow < 8) && (ncol >= 0) && (ncol < 8) && (visited[nrow][ncol] == 0)) {
        return true;
    }
    
    return false;
}
