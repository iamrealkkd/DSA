#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    // Function to detect cycle in an undirected graph.
    bool dfs(int node, vector<int> adj[], vector<int>& visited, int parent) {
        
        visited[node] = 1;

        for (int nbr : adj[node]) {
            
            if (!visited[nbr]) {
                
                bool ans = dfs(nbr, adj, visited, node);
                
                if (ans)
                    return true; // found cycle in this subsequent dfs call
            }
            
            else if (visited[nbr] == true && nbr != parent) {
                
                return true; // point where cycle is found
            }
        }
        
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int> visited(V);
        
        for (int i = 0; i < V; i++) {
            
            if (!visited[i]) {
                
                bool ans = dfs(i, adj, visited, -1);
                
                if (ans == true)
                    return true;
            }
        }
        
        return false;
    }
};

int main() {

    int V = 5;

    vector<int> adj[V];

    // Undirected Graph
    // 0 -- 1
    // |    |
    // 3 -- 2
    // |
    // 4

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(0);
    adj[0].push_back(3);

    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution obj;

    bool ans = obj.isCycle(V, adj);

    if (ans)
        cout << "Cycle Found\n";
    else
        cout << "No Cycle Found\n";

    return 0;
}