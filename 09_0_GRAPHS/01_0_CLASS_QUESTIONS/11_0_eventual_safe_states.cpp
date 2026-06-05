#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& visited,
             vector<int>& current_path) {

        visited[node] = 1;
        current_path[node] = 1;

        for (int nbr : graph[node]) {

            if (!visited[nbr]) {

                bool isCycleFound =
                    dfs(nbr, graph, visited, current_path);

                if (isCycleFound)
                    return true;
            }
            else {

                if (current_path[nbr] == 1) {
                    return true;
                }
            }
        }

        current_path[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<int> visited(V, 0);
        vector<int> current_path(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, current_path);
            }
        }

        vector<int> res;

        for (int i = 0; i < V; i++) {
            if (current_path[i] == 0) {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main() {

    vector<vector<int>> graph = {
        {1, 2}, // 0 -> 1,2
        {2, 3}, // 1 -> 2,3
        {5},    // 2 -> 5
        {0},    // 3 -> 0
        {5},    // 4 -> 5
        {},     // 5
        {}      // 6
    };

    Solution obj;

    vector<int> ans = obj.eventualSafeNodes(graph);

    for (int node : ans) {
        cout << node << " ";
    }

    return 0;
}