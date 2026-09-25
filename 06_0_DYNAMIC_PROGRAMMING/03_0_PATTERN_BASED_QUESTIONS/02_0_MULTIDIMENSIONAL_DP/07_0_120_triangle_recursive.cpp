#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMinPath(int i, int j, int m, int n, vector<vector<int>> &tri) {

    if (i < 0 || i >= m || j < 0 || j > i)
      return INT_MAX;

    if (i == m - 1)
      return tri[i][j];

    return tri[i][j] + min(findMinPath(i + 1, j, m, n, tri),
                           findMinPath(i + 1, j + 1, m, n, tri));
  }

  int minimumTotal(vector<vector<int>> &tri) {

    int m = tri.size();
    int n = tri[0].size();

    return findMinPath(0, 0, m, n, tri);
  }
};

int main() {

  vector<vector<int>> tri = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

  Solution obj;

  cout << obj.minimumTotal(tri) << endl;

  return 0;
}