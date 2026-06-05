#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        int n = adj.size();
        vector<int> indegree(n, 0);
        vector<int> ans;

        // getting nodes' indegree
        for (int i = 0; i < n; i++) {
            for (int &x : adj[i]) {
                indegree[x] += 1;
            }
        }

        // getting the start points
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // bfs loop
        while (!q.empty()) {
            int f = q.front();
            q.pop();

            ans.push_back(f);

            for (int x : adj[f]) {
                indegree[x]--;

                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }

        return ans;
    }
};

int main() {
    int V = 6;

    vector<vector<int>> adj(V);

    // DAG:
    // 5 -> 2, 0
    // 4 -> 0, 1
    // 2 -> 3
    // 3 -> 1

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