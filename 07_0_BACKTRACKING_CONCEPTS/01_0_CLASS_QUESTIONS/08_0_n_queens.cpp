#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

bool check(int rowIdx, int colIdx, int n, vector<vector<int>>& board) {
    // Check same row (left side)
    for (int j = 0; j < colIdx; j++)
        if (board[rowIdx][j] == 1) return false;

    // Check upper-left diagonal
    for (int i = rowIdx, j = colIdx; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    // Check lower-left diagonal
    for (int i = rowIdx, j = colIdx; i < n && j >= 0; i++, j--)
        if (board[i][j] == 1) return false;

    return true;
}

void helper(int colIdx, vector<vector<int>>& board, int n, vector<int>& temp) {
    if (colIdx == n) {
        ans.push_back(temp);
        return;
    }

    // col-wise traversal
    // for colIdx, trying all rowIdx
    for (int rowIdx = 0; rowIdx < n; rowIdx++) {
        // try placing at this cell
        if (check(rowIdx, colIdx, n, board)) {
            // some changes
            temp.push_back(rowIdx + 1);
            board[rowIdx][colIdx] = 1;

            helper(colIdx + 1, board, n, temp);

            // undo those changes
            temp.pop_back();
            board[rowIdx][colIdx] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> temp;
    helper(0, board, n, temp);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> result = nQueen(n);
    for (auto& sol : result) {
        for (int pos : sol)
            cout << pos << " ";
        cout << endl;
    }
    return 0;
}