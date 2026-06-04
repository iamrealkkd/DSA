#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> coordinates = {
        {-1, -2},
        {-1,  2},
        { 1, -2},
        { 1,  2},
        {-2, -1},
        {-2,  1},
        { 2, -1},
        { 2,  1}
    };

    int helper(int src_x,
               int src_y,
               int target_x,
               int target_y,
               int n) {

        vector<vector<int>> visited(n, vector<int>(n, 0));

        queue<pair<int, int>> q;

        q.push({src_x, src_y});
        visited[src_x][src_y] = 1;

        int steps = 0;

        while (!q.empty()) {

            int qSize = q.size();

            while (qSize > 0) {

                pair<int, int> p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;

                if (x == target_x && y == target_y) {
                    return steps;
                }

                for (int k = 0; k < coordinates.size(); k++) {

                    int new_x = x + coordinates[k][0];
                    int new_y = y + coordinates[k][1];

                    if (new_x >= 0 &&
                        new_y >= 0 &&
                        new_x < n &&
                        new_y < n &&
                        visited[new_x][new_y] == 0) {

                        visited[new_x][new_y] = 1;
                        q.push({new_x, new_y});
                    }
                }

                qSize--;
            }

            steps++;
        }

        return -1;
    }

    int minStepToReachTarget(vector<int>& KnightPos,
                             vector<int>& TargetPos,
                             int n) {

        int src_x = KnightPos[0] - 1;
        int src_y = KnightPos[1] - 1;

        int target_x = TargetPos[0] - 1;
        int target_y = TargetPos[1] - 1;

        return helper(src_x,
                      src_y,
                      target_x,
                      target_y,
                      n);
    }
};

int main() {

    int N = 6;

    vector<int> KnightPos = {4, 5};
    vector<int> TargetPos = {1, 1};

    Solution obj;

    cout << obj.minStepToReachTarget(KnightPos,
                                     TargetPos,
                                     N);

    return 0;
}