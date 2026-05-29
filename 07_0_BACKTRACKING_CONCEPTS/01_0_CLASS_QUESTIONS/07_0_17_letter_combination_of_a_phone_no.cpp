#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Global Answer Vector
    vector<string> ans;

    void helper(int idx,
                string &digits,
                map<char,string> &mapping,
                string &curr_str) {

        // BASE CASE
        if(idx == digits.size()) {

            ans.push_back(curr_str);
            return;
        }

        // Current digit
        char ch = digits[idx];

        // Traverse mapped characters
        for(char letter : mapping[ch]) {

            // CHOOSE
            curr_str += letter;

            // EXPLORE
            helper(idx + 1, digits, mapping, curr_str);

            // BACKTRACK
            curr_str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.size() == 0)
            return ans;

        // Mapping
        map<char,string> mapping;

        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";

        string curr_str = "";

        helper(0, digits, mapping, curr_str);

        return ans;
    }
};

int main() {

    Solution obj;

    string digits = "23";

    vector<string> result = obj.letterCombinations(digits);

    for(string str : result) {
        cout << str << " ";
    }

    return 0;
}