#include <bits/stdc++.h>
using namespace std;

void dfs(int node,
         unordered_map<int, vector<int>>& graph,
         vector<int>& visited) {

    visited[node] = 1;

    for (int nbr : graph[node]) {
        if (!visited[nbr]) {
            dfs(nbr, graph, visited);
        }
    }
}

int main() {

    int n = 3;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0}
    };

    int source = 0;
    int destination = 2;

    unordered_map<int, vector<int>> graph;

    // Build graph
    for (auto &e : edges) {
        int a = e[0];
        int b = e[1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> visited(n, 0);

    dfs(source, graph, visited);

    bool ans = visited[destination];

    cout << "Path Exists: "
         << (ans ? "true" : "false")
         << endl;

    return 0;
}