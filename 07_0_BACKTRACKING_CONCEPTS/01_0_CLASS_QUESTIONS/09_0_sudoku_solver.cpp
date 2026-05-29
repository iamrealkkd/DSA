#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool canNumBePlaced(char num, int ri, int ci,
                        vector<vector<char>>& board) {

        // row check
        for(int j = 0; j < 9; j++) {
            if(board[ri][j] == num)
                return false;
        }

        // column check
        for(int i = 0; i < 9; i++) {
            if(board[i][ci] == num)
                return false;
        }

        // subgrid check
        int sr = (ri / 3) * 3;
        int sc = (ci / 3) * 3;

        for(int i = sr; i < sr + 3; i++) {
            for(int j = sc; j < sc + 3; j++) {

                if(board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool helper(int rowIndex, int colIndex,
                vector<vector<char>>& board) {

        // base case
        if(rowIndex == 9) {
            return true;
        }

        // move to next row
        if(colIndex == 9) {
            return helper(rowIndex + 1, 0, board);
        }

        // pre-filled cell
        if(board[rowIndex][colIndex] != '.') {
            return helper(rowIndex, colIndex + 1, board);
        }

        // try numbers 1-9
        for(char num = '1'; num <= '9'; num++) {

            if(canNumBePlaced(num, rowIndex, colIndex, board)) {

                board[rowIndex][colIndex] = num;

                bool res = helper(rowIndex, colIndex + 1, board);

                if(res == true)
                    return true;

                // backtrack
                board[rowIndex][colIndex] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        helper(0, 0, board);
    }
};

int main() {

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution obj;

    obj.solveSudoku(board);

    for(int i = 0; i < 9; i++) {

        for(int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}