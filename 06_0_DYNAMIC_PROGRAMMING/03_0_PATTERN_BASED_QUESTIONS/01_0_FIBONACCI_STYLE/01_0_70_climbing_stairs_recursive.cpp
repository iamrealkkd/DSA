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
    int n = 3;

    Solution obj;

    cout << obj.climbStairs(n);

    return 0;
}