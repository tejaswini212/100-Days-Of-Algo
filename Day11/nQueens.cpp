#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    for (i = 0;i < col;i++)
        if (board[row][i])
            return false;

    for (i = row, j = col;i >= 0 && j >= 0;i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col;i < N && j >= 0;i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool nQueen(int board[N][N], int col) {
    if (col >= N)
        return true;
    for (int i = 0;i < N;i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (nQueen(board, i + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    int board[N][N] = { {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0} };
    if (nQueen(board, 0) == false)
        cout < "Queen's cannot be placed";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j];
        cout << "\n";
    }
    return 0;
}