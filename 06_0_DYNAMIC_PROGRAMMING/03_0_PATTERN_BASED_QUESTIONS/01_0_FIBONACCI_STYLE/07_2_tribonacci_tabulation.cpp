#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {

        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        vector<int> t(n + 1, -1);

        t[0] = 0;
        t[1] = 1;
        t[2] = 1;

        for (int i = 3; i <= n; i++) {
            t[i] = t[i - 1] + t[i - 2] + t[i - 3];
        }

        return t[n];
    }
};

int main() {

    int n = 4;  // default value

    Solution obj;

    cout << obj.tribonacci(n) << endl;

    return 0;
}