#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {

        while (s.length() > 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    string s, part;
    
    // Input string s
    cout << "Enter string s: ";
    getline(cin, s);

    // Input part
    cout << "Enter part to remove: ";
    getline(cin, part);

    Solution obj;
    string result = obj.removeOccurrences(s, part);

    cout << "Output: " << result << endl;

    return 0;
}
