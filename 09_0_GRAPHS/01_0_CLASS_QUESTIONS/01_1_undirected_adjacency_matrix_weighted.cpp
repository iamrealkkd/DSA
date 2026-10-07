#include <bits/stdc++.h>
using namespace std;

void print_graph(vector<vector<int>> &adjacencyMatrix) {
  int n = adjacencyMatrix.size();
  for (int i = 1; i < n; i++) {
    cout << "Node: " << i << ", Neighbors: ";
    for (int j = 1; j < n; j++) {
      if (adjacencyMatrix[i][j] != 0)
        cout << j << "(w=" << adjacencyMatrix[i][j] << ") ";
    }
    cout << endl;
  }
}

int main() {
  // {node1, node2, weight}
  vector<vector<int>> edgeList = {
      {1, 2, 5}, {2, 3, 3}, {3, 4, 7}, {4, 2, 2}, {1, 3, 4}};

  int n = 5;
  vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));
  for (int i = 0; i < edgeList.size(); i++) {
    int a = edgeList[i][0], b = edgeList[i][1], w = edgeList[i][2];
    adjacencyMatrix[a][b] = w; // a -> b
    adjacencyMatrix[b][a] = w; // b -> a (undirected: dono taraf same weight)

    // DIRECTED banana hai to:
    // upar wali line "adjacencyMatrix[b][a] = w;" delete kar do
    // ya comment kar do. Sirf adjacencyMatrix[a][b] = w; rakho.
  }

  print_graph(adjacencyMatrix);
}