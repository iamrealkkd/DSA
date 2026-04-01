#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        unordered_set<int> s;

        int repeated = -1;
        int actualSum = 0;

        // Traverse grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                actualSum += grid[i][j];

                if(s.count(grid[i][j])){
                    repeated = grid[i][j];
                }

                s.insert(grid[i][j]);
            }
        }

        // Expected sum from 1 to n^2
        int expectedSum = (n*n) * (n*n + 1) / 2;

        // Missing number formula
        int missing = expectedSum + repeated - actualSum;

        return {repeated, missing};
    }
};

int main() {

    // Default Test Case
    vector<vector<int>> grid = {
        {1,3},
        {2,2}
    };

    Solution obj;
    vector<int> ans = obj.findMissingAndRepeatedValues(grid);

    cout << "Output: [" << ans[0] << "," << ans[1] << "]" << endl;

    return 0;
}