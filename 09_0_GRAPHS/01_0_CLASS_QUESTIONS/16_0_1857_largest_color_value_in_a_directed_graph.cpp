#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {

        int n = colors.size(), ans = 0;

        vector<vector<int>> graph(n);
        vector<vector<int>> cnt(n, vector<int>(26));

        // cnt[i][j] = maximum count of color j reaching node i

        vector<int> indegree(n);

        for (auto &v : edges) {
            graph[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int processed = 0;

        while (!q.empty()) {

            int f = q.front();
            q.pop();

            processed++;

            cnt[f][colors[f] - 'a']++;

            ans = max(ans, cnt[f][colors[f] - 'a']);

            for (auto nbr : graph[f]) {

                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }

                // Pass color counts to neighbor
                for (int j = 0; j < 26; j++) {
                    cnt[nbr][j] = max(cnt[nbr][j], cnt[f][j]);
                }
            }
        }

        return processed == n ? ans : -1;
    }
};

int main() {

    string colors = "abaca";

    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {2,3},
        {3,4}
    };

    Solution obj;

    cout << "Largest Color Value = "
         << obj.largestPathValue(colors, edges)
         << endl;

    return 0;
}