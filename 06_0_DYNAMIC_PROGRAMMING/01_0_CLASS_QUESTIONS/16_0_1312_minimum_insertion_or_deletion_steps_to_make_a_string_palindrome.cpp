#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minInsertionsorDeletions(string x)
    {

        // Copy original string
        string y = x;

        // Reverse x
        reverse(x.begin(), x.end());

        int m = x.size();
        int n = y.size();

        // DP table
        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));

        // LCS Logic
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                // Characters match
                if (x[i - 1] == y[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }

                // Characters do not match
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        int lps = t[m][n];

        // Minimum Insertions
        return m - lps;
    }
};

int main()
{

    Solution obj;

    string s1 = "leetcode";

    cout << obj.minInsertionsorDeletions(s1);

    return 0;
}