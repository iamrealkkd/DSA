#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int ans = 0;

        queue<pair<int, int>> pq;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    // Iske adjacent become rotten in one go
                    pq.push({i, j});
                }
            }
        }

        while (!pq.empty()) {
            int sz = pq.size();
            int temp = 0;

            while (sz--) {
                auto p = pq.front();
                pq.pop();

                for (int k = 0; k < 4; k++) {
                    int i = p.first + dx[k];
                    int j = p.second + dy[k];

                    if (i >= 0 && j >= 0 && i < r && j < c &&
                        grid[i][j] == 1) {

                        grid[i][j] = 2;
                        temp = 1;
                        pq.push({i, j});
                    }
                }
            }

            ans += temp;
        }

        // Check if any fresh orange remains
        for (auto v : grid) {
            for (int x : v) {
                if (x == 1)
                    return -1;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    cout << "Minimum time = "
         << obj.orangesRotting(grid)
         << endl;

    return 0;
}