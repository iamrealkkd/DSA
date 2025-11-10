#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int n = chars.size();

        for(int i = 0; i < n; i++){
            char ch = chars[i];
            int count = 0;

            while(i < n && chars[i] == ch){
                count++;
                i++;
            }

            // Add character
            chars[idx++] = ch;

            // Add count digits if >1
            if(count > 1){
                string str = to_string(count);
                for(char dig : str){
                    chars[idx++] = dig;
                }
            }

            i--; // adjust
        }

        chars.resize(idx);
        return idx;
    }
};

int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};

    Solution s;
    int newLen = s.compress(chars);

    cout << "Compressed Length = " << newLen << endl;
    cout << "Compressed Array = ";

    for(char c : chars) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
