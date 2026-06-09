#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> dist(
            n,
            vector<int>(m, INT_MAX)
        );

        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while (!pq.empty()) {

            auto pr = pq.top();
            pq.pop();

            int dist_of_par = pr[0];
            int x = pr[1];
            int y = pr[2];

            for (int k = 0; k < 4; k++) {

                int ii = x + dx[k];
                int jj = y + dy[k];

                if (ii < 0 || jj < 0 || ii >= n || jj >= m)
                    continue;

                int new_dist_of_nbr =
                    max(
                        dist_of_par,
                        abs(heights[x][y] - heights[ii][jj])
                    );

                if (new_dist_of_nbr < dist[ii][jj]) {

                    dist[ii][jj] = new_dist_of_nbr;

                    pq.push({
                        dist[ii][jj],
                        ii,
                        jj
                    });
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};

int main() {

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    Solution obj;

    cout << obj.minimumEffortPath(heights);

    return 0;
}