#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007LL
vector<vector<int>> compatible(21, vector<int>(21));
vector<vector<ll>> dp(21, vector<ll>(1 << 21, -1));
int n;
ll f(int i, int mask) {
  if (mask == (1 << n) - 1)
    return 1;
  if (dp[i][mask] != -1)
    return dp[i][mask];

  dp[i][mask] = 0;
  for (int j = 0; j < n; j++) {
    if ((mask & (1 << j)) || (!compatible[i][j]))
      continue;
    dp[i][mask] += f(i + 1, mask | (1 << j));
  }
  dp[i][mask] %= MOD;
  return dp[i][mask];
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> compatible[i][j];
    }
  }
  cout << f(0, 0) << endl;
}
int main() {
  solve();
  return 0;
}