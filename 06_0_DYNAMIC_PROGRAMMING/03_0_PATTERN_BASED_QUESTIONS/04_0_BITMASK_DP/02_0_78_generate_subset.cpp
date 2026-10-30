#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> nums = {1, 2, 3};

  int n = nums.size();
  int p = 1 << n;

  vector<vector<int>> ans;

  for (int mask = 0; mask < p; mask++) {
    vector<int> s;

    for (int bit = 0; bit < n; bit++) {
      if (mask & (1 << bit)) {
        s.push_back(nums[bit]);
      }
    }

    ans.push_back(s);
  }

  // Print all subsets
  for (auto subset : ans) {
    cout << "[ ";

    for (int x : subset) {
      cout << x << " ";
    }

    cout << "]" << endl;
  }

  return 0;
}