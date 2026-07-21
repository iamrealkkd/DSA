#include <bits/stdc++.h>
using namespace std;

void print_graph(vector<vector<int>> &adjacencyList, int V) {

  for (int i = 1; i <= V; i++) {

    cout << "Node: " << i << ", Neighbors: ";

    for (int j = 0; j < adjacencyList[i].size(); j++) {
      cout << adjacencyList[i][j] << " ";
    }

    cout << endl;
  }
}

int main() {

  vector<vector<int>> edgeList = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}};

  int V = 4;

  // Har node ke liye neighbors ki ek list
  vector<vector<int>> adjacencyList(V + 1);

  for (int i = 0; i < edgeList.size(); i++) {

    int a = edgeList[i][0];
    int b = edgeList[i][1];

    // Undirected graph
    adjacencyList[a].push_back(b);
    adjacencyList[b].push_back(a);
  }

  print_graph(adjacencyList, V);

  return 0;
}