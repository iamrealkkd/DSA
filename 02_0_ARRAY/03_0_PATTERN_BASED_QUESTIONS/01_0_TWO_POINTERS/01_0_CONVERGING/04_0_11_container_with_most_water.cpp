#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int n = height.size();
    int mx = INT_MIN;
    int l = 0;
    int r = n - 1;

    while (l < r) {
      int area = min(height[l], height[r]) * (r - l);
      mx = max(mx, area);

      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }
    }

    return mx;
  }
};

int main() {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  Solution obj;
  cout << obj.maxArea(height) << endl;

  return 0;
}