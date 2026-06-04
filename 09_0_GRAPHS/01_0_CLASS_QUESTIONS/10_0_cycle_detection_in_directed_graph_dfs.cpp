#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to detect cycle in a directed graph
    bool dfs(int node,
             vector<int> adj[],
             vector<int>& visited,
             vector<int>& current_path) {

        visited[node] = 1;
        current_path[node] = 1;

        for(int nbr : adj[node]) {

            if(!visited[nbr]) {

                bool res = dfs(nbr, adj, visited, current_path);

                if(res)
                    return true;
            }
            else {

                // nbr already visited
                if(current_path[nbr] == 1) {
                    return true;
                }
            }
        }

        current_path[node] = 0;

        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {

        vector<int> visited(V, 0);
        vector<int> current_path(V, 0);

        for(int i = 0; i < V; i++) {

            if(!visited[i]) {

                bool ans =
                    dfs(i, adj, visited, current_path);

                if(ans == true)
                    return true;
            }
        }

        return false;
    }
};

int main() {

    int V = 4;

    vector<int> adj[V];

    // Directed Graph
    //
    // 0 -> 1
    //      |
    //      v
    // 3 <- 2
    //
    // Cycle:
    // 1 -> 2 -> 3 -> 1

    adj[0].push_back(1);

    adj[1].push_back(2);

    adj[2].push_back(3);

    adj[3].push_back(1);

    Solution obj;

    bool ans = obj.isCyclic(V, adj);

    if(ans)
        cout << "Cycle Found\n";
    else
        cout << "No Cycle Found\n";

    return 0;
}