#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a = -1, b = -1;
        int expectedSum = 0, actualSum = 0;

        // Calculate actual sum and detect repeated value
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                actualSum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];        // repeated value
                }

                s.insert(grid[i][j]);
            }
        }

        // Expected sum of numbers from 1 to n*n
        expectedSum = (n * n) * (n * n + 1) / 2;

        // Missing number formula:
        // missing = expectedSum + repeated - actualSum
        b = expectedSum + a - actualSum;

        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};

int main() {
    // Example input
    int n;
    cin >> n;  // size of grid

    vector<vector<int>> grid(n, vector<int>(n));

    // Input matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    Solution obj;
    vector<int> res = obj.findMissingAndRepeatedValues(grid);

    // Output result
    cout << res[0] << " " << res[1] << endl;

    return 0;
}
