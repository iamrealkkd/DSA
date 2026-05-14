#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string &x, string &y)
    {
        int m = x.size();
        int n = y.size();

        // DP table for LCS
        vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));

        // Initialization
        for (int i = 0; i <= m; i++)
            t[i][0] = 0;

        for (int j = 0; j <= n; j++)
            t[0][j] = 0;

        // Filling DP table
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // If characters match
                if (x[i - 1] == y[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];

                // If characters do not match
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }

        // Length of LCS
        int k = t[m][n];

        // Operations
        int deletion = m - k;
        int insertion = n - k;

        return deletion + insertion;
    }
};

int main()
{

    string s1 = "geeksforgeeks";
    string s2 = "geeks";

    Solution obj;

    cout << obj.minOperations(s1, s2);

    return 0;
}