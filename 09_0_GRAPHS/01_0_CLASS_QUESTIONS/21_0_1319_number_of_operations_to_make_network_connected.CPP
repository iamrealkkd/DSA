#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>> &adj,
             vector<bool> &visited,
             int src) {

        visited[src] = true;

        for (int i : adj[src]) {
            if (!visited[i]) {
                dfs(adj, visited, i);
            }
        }
    }

public:
    int makeConnected(int n,
                      vector<vector<int>>& connections) {

        // Not enough cables to connect all computers
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<vector<int>> adj(n);

        for (auto &v : connections) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vector<bool> visited(n, false);

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adj, visited, i);
                components++;
            }
        }

        return components - 1;
    }
};

int main() {
    Solution obj;

    int n = 6;

    vector<vector<int>> connections = {
        {0,1},
        {0,2},
        {0,3},
        {1,2},
        {1,3}
    };

    cout << obj.makeConnected(n, connections) << endl;

    return 0;
}