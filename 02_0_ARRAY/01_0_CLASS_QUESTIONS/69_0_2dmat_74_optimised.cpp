#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row) {
        int n = matrix[0].size();
        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target == matrix[row][mid]) {
                return true;
            } 
            else if (target > matrix[row][mid]) {
                st = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int startRow = 0, endRow = m - 1;

        while (startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;

            // target may be inside this row
            if (target >= matrix[midRow][0] && target <= matrix[midRow][n - 1]) {
                return searchInRow(matrix, target, midRow);
            }
            // target is greater → move down
            else if (target > matrix[midRow][n - 1]) {
                startRow = midRow + 1;
            }
            // target is smaller → move up
            else {
                endRow = midRow - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution obj;

    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    // input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    if (obj.searchMatrix(matrix, target))
        cout << "FOUND\n";
    else
        cout << "NOT FOUND\n";

    return 0;
}
