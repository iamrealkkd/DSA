#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool dfs(int source, vector<vector<int>> &rooms, int n) {

    queue<int> q;
    vector<int> visited(n, 0);

    q.push(source);
    visited[source] = 1;

    while (!q.empty()) {

      int f = q.front();
      q.pop();

      for (int nbr : rooms[f]) {

        if (!visited[nbr]) {
          visited[nbr] = 1;
          q.push(nbr);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (visited[i] != 1)
        return false;
    }

    return true;
  }

  bool canVisitAllRooms(vector<vector<int>> &rooms) {

    int n = rooms.size();

    return dfs(0, rooms, n);
  }
};

int main() {

  vector<vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};

  Solution sol;

  cout << boolalpha << sol.canVisitAllRooms(rooms) << endl;

  return 0;
}

