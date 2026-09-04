#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = i + dp[i - 1];
    }

    cout << dp[n];

    return 0;
}