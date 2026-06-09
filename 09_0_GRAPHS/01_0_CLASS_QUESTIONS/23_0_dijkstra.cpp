#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {

    int n = adj.size();

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> distances(n, INT_MAX);

    distances[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {

        auto pr = pq.top();
        pq.pop();

        int dist_of_node_from_src = pr.first;
        int node = pr.second;

        for (auto &nbr_info : adj[node]) {

            int nbr = nbr_info.first;
            int weight = nbr_info.second;

            int saved_dist_of_nbr_from_src = distances[nbr];
            int new_dist_of_nbr_from_src =
                dist_of_node_from_src + weight;

            if (new_dist_of_nbr_from_src <
                saved_dist_of_nbr_from_src) {

                distances[nbr] = new_dist_of_nbr_from_src;
                pq.push({new_dist_of_nbr_from_src, nbr});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (distances[i] == INT_MAX) {
            distances[i] = -1;
        }
    }

    return distances;
}

int main() {

    int n = 5; // nodes 0 to 4

    vector<vector<pair<int, int>>> adj(n);

    // {neighbor, weight}

    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});

    adj[2].push_back({1, 2});
    adj[2].push_back({3, 5});

    adj[1].push_back({3, 1});

    adj[3].push_back({4, 3});

    int src = 0;

    vector<int> ans = dijkstra(adj, src);

    cout << "Shortest distances from node " << src << ":\n";

    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> " << ans[i] << endl;
    }

    return 0;
}