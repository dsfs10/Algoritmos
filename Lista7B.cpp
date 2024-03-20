#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

bool MazePath(char** Maze, int** visited, int row, int col, int n, int m, vector<int> pathRow, vector<int> pathCol, int j, int numSpikes);
bool valid(char** Maze, int** visited, int row, int col, int n, int m);


int main(void) {
    int n, m, j;
    int startR, startC, numSpikes = 0;
    vector<int> pathRow = {1, -1, 0, 0};
    vector<int> pathCol = {0, 0, 1, -1};
    cin >> n >> m >> j;
    int** visited;
    char** Maze;
    Maze = new char*[n];
    visited = new int*[n];

    for(int i = 0; i < n; i++) {
        Maze[i] = new char[m];
        visited[i] = new int[m]();
        for(int k = 0; k < m; k++) {
            cin >> Maze[i][k];
            if(Maze[i][k] == '@') {
                startR = i;
                startC = k;
            }
        }
    }

    if(MazePath(Maze, visited, startR, startC, n, m, pathRow, pathCol, j, numSpikes)) {
        cout << "SUCCESS" << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}


bool MazePath(char** Maze, int** visited, int row, int col, int n, int m, vector<int> pathRow, vector<int> pathCol, int j, int numSpikes) {
    if(Maze[row][col] == 's') {
        numSpikes++;
    }
    if(Maze[row][col] == 'x' && j >= 2*numSpikes) {
        return true;
    }
    else {
        for(int i = 0; i < 4; i++) {
            int nrow = row + pathRow[i];
            int ncol = col + pathCol[i];
            if(valid(Maze, visited, nrow, ncol, n, m)) {
                visited[nrow][ncol] = 1;
                if(MazePath(Maze, visited, nrow, ncol, n, m, pathRow, pathCol, j, numSpikes)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool valid(char** Maze, int** visited, int row, int col, int n, int m) {
    if((row >= 0) && (row < n) && (col >= 0) && (col < m) && (visited[row][col] == 0) && (Maze[row][col] != '#')) {
        return true;
    }

    return false;
}
