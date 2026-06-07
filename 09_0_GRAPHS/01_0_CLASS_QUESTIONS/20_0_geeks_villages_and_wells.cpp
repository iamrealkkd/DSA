#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> chefAndWells(int n, int m,
                                     vector<vector<char>>& c) {

        vector<vector<int>> direction = {
            {0, 1},
            {1, 0},
            {-1, 0},
            {0, -1}
        };

        vector<vector<int>> result(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        // Initialize queue with all wells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == 'W') {
                    q.push({i, j});
                }
            }
        }

        int counter = 1;

        // Multi-source BFS
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                pair<int, int> p = q.front();
                q.pop();

                int row = p.first;
                int col = p.second;

                for (auto &dir : direction) {
                    int new_row = row + dir[0];
                    int new_col = col + dir[1];

                    if (new_row >= 0 && new_row < n &&
                        new_col >= 0 && new_col < m &&
                        (c[new_row][new_col] == 'H' ||
                         c[new_row][new_col] == '.')) {

                        if (c[new_row][new_col] == 'H') {
                            result[new_row][new_col] = 2 * counter;
                        }

                        c[new_row][new_col] = 'X'; // visited
                        q.push({new_row, new_col});
                    }
                }
            }

            counter++;
        }

        // Houses not reached
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == 'H') {
                    result[i][j] = -1;
                }
            }
        }

        return result;
    }
};

int main() {
    int n = 5, m = 5;

    vector<vector<char>> grid = {
        {'H', 'H', 'W', 'H', 'H'},
        {'H', '.', '.', '.', 'H'},
        {'H', '.', 'N', '.', 'H'},
        {'H', '.', '.', '.', 'H'},
        {'H', 'H', 'H', 'H', 'H'}
    };

    Solution obj;

    vector<vector<int>> ans = obj.chefAndWells(n, m, grid);

    cout << "Result Matrix:\n";
    for (auto &row : ans) {
        for (auto &x : row) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}