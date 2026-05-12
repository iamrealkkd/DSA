#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonSubsequence(string x, string y)
    {
        int m = x.size();
        int n = y.size();

        vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));

        // Initialization
        for (int i = 0; i <= m; i++)
            t[i][0] = 0;

        for (int j = 0; j <= n; j++)
            t[0][j] = 0;

        // DP Table Filling
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                // If characters match
                if (x[i - 1] == y[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];

                // If characters do not match
                else
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
        int i = m;
        int j = n;
        string s = "";
        while (i > 0 && j > 0)
        {
            if (x[i - 1] == y[j - 1])
            {
                s.push_back(x[i - 1]);
                ;
                i--;
                j--;
            }
            else
            {
                if (t[i][j - 1] > t[i - 1][j])
                {
                    j--;
                }
                else
                {
                    i--;
                }
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{

    // Default Input
    string text1 = "abcde";
    string text2 = "ace";

    Solution obj;

    cout << obj.longestCommonSubsequence(text1, text2);

    return 0;
}