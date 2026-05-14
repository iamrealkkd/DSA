#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string x, string y)
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

        int k = t[m][n];
        int deletion = m - k;
        int insertion = n - k;
        int tot = deletion + insertion;
        return tot;
    }
};

int main()
{

    // Default Input
    string text1 = "geeksforgeeks";
    string text2 = "geeks";

    Solution obj;

    cout << obj.longestCommonSubsequence(text1, text2);

    return 0;
}