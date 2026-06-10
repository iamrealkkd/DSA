#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // Graph Creation
        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < flights.size(); i++) {
            int from = flights[i][0];
            int to = flights[i][1];
            int wt = flights[i][2];

            graph[from].push_back({to, wt});
        }

        // Distance Array
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // {stops, node, cost}
        queue<vector<int>> q;
        q.push({0, src, 0});

        while (!q.empty()) {

            auto pr = q.front();
            q.pop();

            int stops_taken = pr[0];
            int node = pr[1];
            int dist_of_par = pr[2];

            if (stops_taken > k)
                continue;

            for (auto &nbr_info : graph[node]) {

                int nbr = nbr_info.first;
                int wt = nbr_info.second;

                int new_dist_of_nbr = dist_of_par + wt;

                if (new_dist_of_nbr < dist[nbr]) {

                    dist[nbr] = new_dist_of_nbr;

                    q.push({
                        stops_taken + 1,
                        nbr,
                        new_dist_of_nbr
                    });
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {

    int n = 4;

    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 3, 500}
    };

    int src = 0;
    int dst = 3;
    int k = 2;

    Solution obj;

    int ans = obj.findCheapestPrice(n, flights, src, dst, k);

    cout << ans << endl;

    return 0;
}