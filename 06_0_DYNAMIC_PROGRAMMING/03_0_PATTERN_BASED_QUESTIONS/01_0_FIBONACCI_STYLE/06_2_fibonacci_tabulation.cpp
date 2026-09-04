#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long fib(int n) {

        // Base case
        if (n == 0) {
            return 0;
        }

        vector<long long> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;

    cout << obj.fib(n) << endl;

    return 0;
}