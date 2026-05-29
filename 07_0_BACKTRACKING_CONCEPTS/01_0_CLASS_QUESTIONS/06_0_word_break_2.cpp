#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<string> ans;

    void helper(string &s, int idx, vector<string> &temp, unordered_set<string> &dict_set) {

        // Base Case
        if(idx == s.size()) {

            string sentence = "";

            for(int j = 0; j < temp.size(); j++) {

                sentence += temp[j];

                if(j != temp.size() - 1) {
                    sentence += " ";
                }
            }

            ans.push_back(sentence);
            return;
        }

        string word = "";

        // Generate all substrings from idx
        for(int i = idx; i < s.size(); i++) {

            word += s[i];

            // Word found in dictionary
            if(dict_set.find(word) != dict_set.end()) {

                // Choose
                temp.push_back(word);

                // Explore
                helper(s, i + 1, temp, dict_set);

                // Backtrack
                temp.pop_back();
            }
        }
    }

    vector<string> wordBreak(vector<string>& dict, string &s) {

        vector<string> temp;

        unordered_set<string> dict_set;

        // Store dictionary words in set
        for(int i = 0; i < dict.size(); i++) {
            dict_set.insert(dict[i]);
        }

        helper(s, 0, temp, dict_set);

        return ans;
    }
};

int main() {

    // Given Input
    string s = "likegfg";

    vector<string> dict = {
        "lik",
        "like",
        "egfg",
        "gfg"
    };

    Solution obj;

    vector<string> result = obj.wordBreak(dict, s);

    for(string sentence : result) {
        cout << "\"" << sentence << "\"" << endl;
    }

    return 0;
}