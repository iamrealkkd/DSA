#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<string, int> mp;

    int solve(string &s, int i, int j, bool isTrue)
    {
        // Base Case
        if(i > j)
            return 0;

        if(i == j)
        {
            if(isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        // Making Key
        string temp = to_string(i);
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(isTrue));

        // Memoization Check
        if(mp.find(temp) != mp.end())
            return mp[temp];

        int ans = 0;

        for(int k = i + 1; k <= j - 1; k += 2)
        {
            int lt = solve(s, i, k - 1, true);
            int lf = solve(s, i, k - 1, false);

            int rt = solve(s, k + 1, j, true);
            int rf = solve(s, k + 1, j, false);

            // AND Operator
            if(s[k] == '&')
            {
                if(isTrue)
                    ans += (lt * rt);
                else
                    ans += (lt * rf) + (lf * rt) + (lf * rf);
            }

            // OR Operator
            else if(s[k] == '|')
            {
                if(isTrue)
                    ans += (lt * rt) + (lt * rf) + (lf * rt);
                else
                    ans += (lf * rf);
            }

            // XOR Operator
            else if(s[k] == '^')
            {
                if(isTrue)
                    ans += (lt * rf) + (lf * rt);
                else
                    ans += (lt * rt) + (lf * rf);
            }
        }

        // Store and Return
        return mp[temp] = ans;
    }

    int countWays(string &s)
    {
        int n = s.length();

        return solve(s, 0, n - 1, true);
    }
};

int main()
{
    Solution obj;

    string s = "T|T&F^T";

    cout << obj.countWays(s);

    return 0;
}