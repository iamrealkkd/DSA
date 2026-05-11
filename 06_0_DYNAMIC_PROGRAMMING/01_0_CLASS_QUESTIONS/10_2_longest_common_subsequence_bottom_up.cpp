#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive LCS Function
    int longestCommonSubsequence(string x, string y, int m, int n)
    {
        vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));

        // Initialization
        for (int i = 0; i <= m; i++)
            t[i][0] = 0;
        for (int j = 0; j <= n; j++)
            t[0][j] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // If characters match
                if (x[i - 1] == y[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];

                // If characters do not match
                else
                {
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
                }
            }
        }
        return t[m][n];
    }
};

int main()
{

    // Default values
    string text1 = "abcde";
    string text2 = "ace";

    int m = text1.size();
    int n = text2.size();

    Solution obj;

    cout << obj.longestCommonSubsequence(text1, text2, m, n);

    return 0;
}