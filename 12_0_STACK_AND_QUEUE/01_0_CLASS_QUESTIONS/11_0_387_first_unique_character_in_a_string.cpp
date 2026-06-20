#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<int> Q;

        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                Q.push(i);
            }

            m[s[i]]++;

            while (Q.size() > 0 && m[s[Q.front()]] > 1) {
                Q.pop();
            }
        }

        return Q.empty() ? -1 : Q.front();
    }
};

int main() {
    Solution sol;

    cout << sol.firstUniqChar("leetcode") << endl;    // 0 ('l')
    cout << sol.firstUniqChar("loveleetcode") << endl; // 2 ('v')
    cout << sol.firstUniqChar("aabb") << endl;         // -1

    return 0;
}