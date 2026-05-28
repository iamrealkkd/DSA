#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int n, int start, int num, vector<int> &ans) {

        // Base Case
        if(n == 0) {
            ans.push_back(num);
            return;
        }

        // Pick increasing digits
        for(int i = start; i <= 9; i++) {

            // Build number
            solve(n - 1, i + 1, num * 10 + i, ans);
        }
    }

    vector<int> increasingNumbers(int n) {

        vector<int> ans;

        // Special Case
        if(n == 1)
            ans.push_back(0);

        solve(n, 1, 0, ans);

        return ans;
    }
};

int main() {

    int n = 2;

    Solution obj;

    vector<int> ans = obj.increasingNumbers(n);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}