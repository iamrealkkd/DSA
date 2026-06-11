#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

        vector<int> dist(V, INT_MAX);

        dist[src] = 0;

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++) {

            for (vector<int>& edge : edges) {

                int node = edge[0];
                int nbr  = edge[1];
                int wt   = edge[2];

                if (dist[node] == INT_MAX)
                    continue;

                int new_dist_of_nbr = dist[node] + wt;

                if (new_dist_of_nbr < dist[nbr]) {
                    dist[nbr] = new_dist_of_nbr;
                }
            }
        }

        // Check for Negative Weight Cycle
        for (vector<int>& edge : edges) {

            int node = edge[0];
            int nbr  = edge[1];
            int wt   = edge[2];

            if (dist[node] == INT_MAX)
                continue;

            int new_dist_of_nbr = dist[node] + wt;

            if (new_dist_of_nbr < dist[nbr]) {
                return {-1};
            }
        }

        // Replace unreachable nodes with 1e8
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = 1e8;
        }

        return dist;
    }
};

int main() {

    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int src = 0;

    Solution obj;
    vector<int> ans = obj.bellmanFord(V, edges, src);

    if (ans.size() == 1 && ans[0] == -1) {
        cout << "Negative Weight Cycle Found\n";
    } else {
        cout << "Shortest distances from source:\n";
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}