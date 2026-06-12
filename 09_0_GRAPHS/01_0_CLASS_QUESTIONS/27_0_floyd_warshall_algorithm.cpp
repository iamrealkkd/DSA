#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;

class Solution {
public:
    void floydWarshall(vector<vector<int>>& dist) {

        int V = dist.size();

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {

                    if (dist[i][k] == INF || dist[k][j] == INF)
                        continue;

                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};

int main() {

    vector<vector<int>> dist = {
        {0, 25, INF},
        {1, 0, 43},
        {INF, 1, 0}
    };

    Solution obj;
    obj.floydWarshall(dist);

    for (auto row : dist) {
        for (auto x : row) {
            if (x == INF)
                cout << "INF ";
            else
                cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}