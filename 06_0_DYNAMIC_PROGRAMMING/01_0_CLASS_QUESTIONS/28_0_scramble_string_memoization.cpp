#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<string, bool> mp;

    bool solve(string a, string b) {
        if (a == b)
            return true;

        if (a.length() <= 1)
            return false;

        if(a.length() && b.length() == 0)
            return true;

        string key = a + "_" + b;

        if (mp.find(key) != mp.end())
            return mp[key];

        int n = a.length();
        bool flag = false;

        for (int i = 1; i <= n - 1; i++) {
            bool cond1 =
                solve(a.substr(0, i), b.substr(0, i)) &&
                solve(a.substr(i, n - i), b.substr(i, n - i));

            bool cond2 =
                solve(a.substr(0, i), b.substr(n - i, i)) &&
                solve(a.substr(i, n - i), b.substr(0, n - i));

            if (cond1 || cond2) {
                flag = true;
                break;
            }
        }

        return mp[key] = flag;
    }

    bool isScramble(string s1, string s2) {
        mp.clear();
        return solve(s1, s2);
    }
};

int main() {
    Solution obj;

    cout << (obj.isScramble("great", "rgeat") ? "true" : "false");

    return 0;
}