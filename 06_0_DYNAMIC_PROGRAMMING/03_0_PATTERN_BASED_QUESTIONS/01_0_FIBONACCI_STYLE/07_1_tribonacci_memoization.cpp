#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& t) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        if (t[n] != -1)
            return t[n];

        return t[n] = solve(n - 1, t)
                    + solve(n - 2, t)
                    + solve(n - 3, t);
    }

    int tribonacci(int n) {
        vector<int> t(n + 1, -1);
        return solve(n, t);
    }
};

int main() {
    int n = 4;  // default value

    Solution obj;

    cout << obj.tribonacci(n) << endl;

    return 0;
}