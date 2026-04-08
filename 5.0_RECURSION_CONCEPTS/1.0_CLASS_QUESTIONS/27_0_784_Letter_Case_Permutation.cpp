#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string input, string output, vector<string>& v){
        if(input.size() == 0){      
            v.push_back(output);    
            return;
        }

        if(isalpha(input[0])){
            string op1 = output;
            string op2 = output;
            op1.push_back(tolower(input[0]));
            op2.push_back(toupper(input[0])); 
            input.erase(input.begin());       
            solve(input, op1, v);
            solve(input, op2, v);
        } else {
            string op1 = output;
            op1.push_back(input[0]);
            input.erase(input.begin());       
            solve(input, op1, v);
        }
    }

    vector<string> letterCasePermutation(string s) {
        string ip = s;
        string op = "";
        vector<string> v;
        solve(ip, op, v);
        return v;   // return the result vector
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> result = sol.letterCasePermutation(s);

    cout << "Letter case permutations:" << endl;
    for(auto str : result)
        cout << str << endl;

    return 0;
}