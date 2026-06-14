#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string S) {
        string ans  = "";
        string temp = "";

        for (int i = S.length() - 1; i >= 0; i--) {
            if (S[i] == '.') {
                reverse(temp.begin(), temp.end());
                if (ans != "") ans = ans + '.';  // dot only between words
                ans  = ans + temp;
                temp = "";
            } else {
                temp.push_back(S[i]);
            }
        }

        // last word
        reverse(temp.begin(), temp.end());
        if (ans != "") ans = ans + '.';
        ans = ans + temp;

        return ans;
    }
};

int main() {
    Solution obj;

    cout << obj.reverseWords("i.like.this.program.very.much") << endl;
    // Expected: much.very.program.this.like.i

    cout << obj.reverseWords("pqr.mno") << endl;
    // Expected: mno.pqr

    return 0;
}