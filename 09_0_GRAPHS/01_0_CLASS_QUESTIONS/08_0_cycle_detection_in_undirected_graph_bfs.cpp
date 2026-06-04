#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    // BFS function to detect cycle
    bool bfs(int node,
             vector<int> adj[],
             vector<int>& visited,
             vector<int>& parent) {

        queue<int> q;

        q.push(node);
        visited[node] = 1;

        while (!q.empty()) {

            int f = q.front();
            q.pop();

            for (int nbr : adj[f]) {

                if (!visited[nbr]) {

                    visited[nbr] = 1;
                    parent[nbr] = f;

                    q.push(nbr);
                }
                else { // nbr already visited

                    if (parent[f] != nbr) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {

        vector<int> visited(V, 0);
        vector<int> parent(V, -1);

        for (int i = 0; i < V; i++) {

            if (!visited[i]) {

                bool ans = bfs(i, adj, visited, parent);

                if (ans == true) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {

    int V = 5;

    vector<int> adj[V];

    // Graph:
    //
    // 0 ----- 1
    // |       |
    // |       |
    // 3 ----- 2
    //
    // 4 (isolated)
    //
    // Cycle: 0 -> 1 -> 2 -> 3 -> 0

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(0);
    adj[0].push_back(3);

    Solution obj;

    bool ans = obj.isCycle(V, adj);

    if (ans) {
        cout << "Cycle Found" << endl;
    }
    else {
        cout << "No Cycle Found" << endl;
    }

    return 0;
}