#include <iostream>
#include <vector>
using namespace std;

int N;

void printSolution(vector<vector<int>>& board)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>>& board, int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return false;
    }
    return true;
}

bool solveNQUtilforward(vector<vector<int>>& board, int col)
{
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQUtilforward(board, col + 1))
                return true;
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

bool solveNQUtilbackward(vector<vector<int>>& board, int col)
{
    if (col >= N)
        return true;
    for (int i = N - 1; i >= 0; i--) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQUtilbackward(board, col + 1))
                return true;
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

bool solveNQ()
{
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (!solveNQUtilforward(board, 0)) {
        cout << "No solution found";
        return false;
    }
    cout << "S1:" << endl;
    printSolution(board);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    solveNQUtilbackward(board, 0);
    cout << "S2:" << endl;
    printSolution(board);

    return true;
}

int main()
{
    cin >> N;
    solveNQ();
    return 0;
}
