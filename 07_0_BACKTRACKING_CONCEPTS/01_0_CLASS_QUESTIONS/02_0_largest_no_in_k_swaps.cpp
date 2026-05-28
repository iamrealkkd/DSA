#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void solve(string s, int k, string &res, int start) {
        
        // Base case
        if(k == 0 || start == s.size())
            return;

        // Try all positions after start
        for(int i = start + 1; i < s.size(); i++) {

            // If bigger digit found
            if(s[i] > s[start]) {

                // Swap
                swap(s[start], s[i]);

                // Update answer if current string is bigger
                if(s.compare(res) > 0) {
                    res = s;
                }

                // Recursive call
                solve(s, k - 1, res, start + 1);

                // Backtrack
                swap(s[start], s[i]);
            }
        }

        // Also move forward without swap
        solve(s, k, res, start + 1);
    }

    string findMaximumNum(string s, int k) {

        string res = s;

        solve(s, k, res, 0);

        return res;
    }
};

int main() {

    string s = "1234567";
    int k = 4;

    Solution obj;

    cout << obj.findMaximumNum(s, k);

    return 0;
}