#include <bits/stdc++.h>
using namespace std;

class SolutionTopDown {
public:
  int minimumTotal(vector<vector<int>> &tri) {

    int m = tri.size();

    vector<vector<int>> t(m, vector<int>(m, INT_MAX));

    t[0][0] = tri[0][0];

    for (int i = 1; i < m; i++) {

      for (int j = 0; j <= i; j++) {

        if (j == 0) {
          t[i][j] = tri[i][j] + t[i - 1][j];
        }

        else if (j == i) {
          t[i][j] = tri[i][j] + t[i - 1][j - 1];
        }

        else {
          t[i][j] = tri[i][j] + min(t[i - 1][j], t[i - 1][j - 1]);
        }
      }
    }

    int ans = INT_MAX;

    for (int j = 0; j < m; j++) {
      ans = min(ans, t[m - 1][j]);
    }

    return ans;
  }
};

class SolutionBottomUp {
public:
  int minimumTotal(vector<vector<int>> &tri) {

    int m = tri.size();

    vector<vector<int>> t(m, vector<int>(m));

    for (int j = 0; j < m; j++) {
      t[m - 1][j] = tri[m - 1][j];
    }

    for (int i = m - 2; i >= 0; i--) {

      for (int j = 0; j <= i; j++) {

        t[i][j] = tri[i][j] + min(t[i + 1][j], t[i + 1][j + 1]);
      }
    }

    return t[0][0];
  }
};

int main() {

  vector<vector<int>> tri = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

  SolutionTopDown obj1;
  SolutionBottomUp obj2;

  cout << "Top Down: " << obj1.minimumTotal(tri) << endl;
  cout << "Bottom Up: " << obj2.minimumTotal(tri) << endl;

  return 0;
}