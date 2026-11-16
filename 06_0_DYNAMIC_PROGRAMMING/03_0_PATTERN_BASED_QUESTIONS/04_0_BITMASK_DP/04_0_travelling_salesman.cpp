#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lld = long double;
const int INF = INT_MAX;

int n;
vector<vector<lld>> dp(1 << 15, vector<lld>(15, -1));
vector<pair<lld, lld>> points(15);
void takeInput() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> points[i].first >> points[i].second;
  }
}
lld dist (int i , int j){
    lld x = points[i].first - points[j].first;
    lld y = points[i].second - points[j].second;
    return sqrt(x * x + y * y);
}
lld f (int mask, int last){
       int i = __builtin_popcount(mask);
       if(mask == (1 << n) - 1)return 0;
       if(dp[mask][last] != -1){
        return dp[mask][last];
       }
       dp[mask][last] = INF;
       for(int j  = 0; j < n; j++){
        if(mask & (1 << j))continue;
        lld currAns = dist(last, j) + f(mask | (1 << j), j);
        dp[mask][last] = min(dp[mask][last], currAns);
       }
       return dp[mask][last];
    
}
void solve(){
    takeInput();
    lld ans = INF;
    for(int i = 0; i < n; i++){
        ans = min(ans, f(1 << i, i));
    }
    cout << ans;
}
int main() {
  solve();
  return 0;
}
// Traveling Salesman on 2D Plane
//
// Given a list of points on a 2D plane, rearrange these points in any way such
// that in the final permutation of points, the sum of distances of the adjacent
// elements is minimized.
//
// Constraints: [N <= 15], [-1e^9 <= X_i, Y_i <= 1e^9]
//
// Example: [{0, 0}, {2, 2}, {1, 2}, {0, 1}]
// Best permutation -> [P1, P4, P3, P2]
// Ans = Dist(P1, P4) + Dist(P4, P3) + Dist(P3, P2)
// 4 (n)
// 0 0 (coordinates)
// 2 2 
// 1 2 
// 0 1 
// 3.41421(ans)