#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    deque<int> dq;

    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, adj);
            }
        }

        dq.push_front(node);
    }

    vector<int> topologicalSort(vector<vector<int>>& adj) {

        int n = adj.size();
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj);
            }
        }

        vector<int> ans;

        for (int x : dq) {
            ans.push_back(x);
        }

        return ans;
    }
};

int main() {

    int V = 6;

    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;

    vector<int> topo = obj.topologicalSort(adj);

    cout << "Topological Order: ";

    for (int x : topo) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}