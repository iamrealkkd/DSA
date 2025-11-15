#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int r = 0, c = n - 1;

        while (r < m && c >= 0) {
            if (target == mat[r][c]) {
                return true;
            } 
            else if (target < mat[r][c]) {
                c--;       // move left
            } 
            else {
                r++;       // move down
            }
        }
        return false;
    }
};

int main() {
    int m, n;
    cin >> m >> n;              // input rows and columns

    vector<vector<int>> mat(m, vector<int>(n));

    // input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int target;
    cin >> target;             // input target

    Solution obj;
    if (obj.searchMatrix(mat, target)) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;
}
