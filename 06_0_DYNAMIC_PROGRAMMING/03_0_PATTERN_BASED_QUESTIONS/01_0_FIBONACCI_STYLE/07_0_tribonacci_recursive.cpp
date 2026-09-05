#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0 || n == 1)
            return n;

        if (n == 2)
            return 1;

        return tribonacci(n - 1)
             + tribonacci(n - 2)
             + tribonacci(n - 3);
    }
};

int main() {
    int n = 4;   // default value

    Solution obj;

    cout << obj.tribonacci(n) << endl;

    return 0;
}