#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& forward_nbrs,
             vector<vector<int>>& backward_nbrs,
             int& ans,
             vector<int>& visited) {

        visited[node] = 1;

        // Forward edges
        for (int nbr : forward_nbrs[node]) {
            if (!visited[nbr]) {
                ans++;
                cout << "Forward Edge: "
                     << node << " -> " << nbr
                     << " (ans = " << ans << ")\n";

                dfs(nbr, forward_nbrs, backward_nbrs, ans, visited);
            }
        }

        // Backward edges
        for (int nbr : backward_nbrs[node]) {
            if (!visited[nbr]) {
                cout << "Backward Edge: "
                     << nbr << " -> " << node
                     << " (ans unchanged)\n";

                dfs(nbr, forward_nbrs, backward_nbrs, ans, visited);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<int>> forward_nbrs(n);
        vector<vector<int>> backward_nbrs(n);
        vector<int> visited(n, 0);

        for (auto& edge : connections) {

            int a = edge[0];
            int b = edge[1];

            forward_nbrs[a].push_back(b);
            backward_nbrs[b].push_back(a);
        }

        cout << "\nForward Graph:\n";
        for (int i = 0; i < n; i++) {
            cout << i << " : ";
            for (int x : forward_nbrs[i])
                cout << x << " ";
            cout << endl;
        }

        cout << "\nBackward Graph:\n";
        for (int i = 0; i < n; i++) {
            cout << i << " : ";
            for (int x : backward_nbrs[i])
                cout << x << " ";
            cout << endl;
        }

        int ans = 0;

        cout << "\nDFS Starts From Node 0\n\n";

        dfs(0, forward_nbrs, backward_nbrs, ans, visited);

        return ans;
    }
};

int main() {

    int n = 6;

    vector<vector<int>> connections = {
        {0,1},
        {1,3},
        {2,3},
        {4,0},
        {4,5}
    };

    Solution obj;

    int answer = obj.minReorder(n, connections);

    cout << "\nFinal Answer = "
         << answer << endl;

    return 0;
}