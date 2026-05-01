#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1)
            return 1;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    int ways = obj.climbStairs(n);
    cout << "Number of ways to climb stairs: " << ways << endl;

    return 0;
}
