#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};

        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windSize = s1.length();

        for (int i = 0; i < s2.length(); i++) {
            int windIdx = 0, idx = i;
            int windFreq[26] = {0};

            while (windIdx < windSize && idx < s2.length()) {
                windFreq[s2[idx] - 'a']++;
                windIdx++;
                idx++;
            }

            if (isFreqSame(freq, windFreq)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    string s1, s2;
    cin >> s1 >> s2;

    if (sol.checkInclusion(s1, s2)) {
        cout << "TRUE\n";
    } else {
        cout << "FALSE\n";
    }

    return 0;
}
