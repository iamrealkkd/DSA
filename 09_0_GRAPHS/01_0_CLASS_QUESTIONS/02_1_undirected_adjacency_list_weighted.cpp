#include <bits/stdc++.h>
using namespace std;

void print_graph(unordered_map<int, vector<pair<int, int>>> &graph) {
  for (auto x : graph) {
    cout << "Node: " << x.first << ", Neighbors: ";
    for (auto p : x.second) {
      cout << p.first << "(w=" << p.second << ") ";
    }
    cout << endl;
  }
}

int main() {
  // {node1, node2, weight}
  vector<vector<int>> edgeList = {
      {1, 2, 5}, {2, 3, 3}, {3, 4, 7}, {4, 2, 2}, {1, 3, 4}};

  unordered_map<int, vector<pair<int, int>>> graph;
  for (int i = 0; i < edgeList.size(); i++) {
    int a = edgeList[i][0], b = edgeList[i][1], w = edgeList[i][2];
    graph[a].push_back({b, w}); // a -> b
    graph[b].push_back({a, w}); // b -> a (undirected)

    // DIRECTED banana hai to:
    // "graph[b].push_back({a, w});" hata do, aur uski jagah
    // sirf "graph[b];" likho. Isse b ka key ban jayega (khali list ke saath),
    // warna jis node ka koi outgoing edge nahi hai woh print hi nahi hoga.
  }

  print_graph(graph);
}