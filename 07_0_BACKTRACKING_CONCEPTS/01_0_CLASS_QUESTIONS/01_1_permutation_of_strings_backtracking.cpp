#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    void permute(string &s, int start, vector<string> &v) {

        // Base Case
        if(start == s.size()) {
            v.push_back(s);
            return;
        }

        unordered_set<char> mp;

        for(int i = start; i < s.size(); i++) {

            // Skip duplicates
            if(mp.find(s[i]) == mp.end()) {

                mp.insert(s[i]);

                // Swap
                swap(s[start], s[i]);

                // Recursive Call
                permute(s, start + 1, v);

                // Backtracking
                swap(s[start], s[i]);
            }
        }
    }

    vector<string> findPermutation(string &s) {

        vector<string> v;

        permute(s, 0, v);

        return v;
    }
};

int main() {

    Solution obj;

    string s = "ABC";

    vector<string> ans = obj.findPermutation(s);

    for(string x : ans) {
        cout << x << endl;
    }

    return 0;
}