#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {

    int n = cost.size();

    // dp[i] = Minimum cost to reach the top from index i
    vector<int> dp(n + 2, 0);

    // Fill the DP table from back to front
    for (int i = n - 1; i >= 0; i--) {

      dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
    }

    // Start from index 0 or index 1
    return min(dp[0], dp[1]);
  }
};

int main() {

  // LeetCode Example 1
  vector<int> cost = {10, 15, 20};

  Solution obj;

  cout << obj.minCostClimbingStairs(cost);

  return 0;
}