#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSuperSeq(string &x, string &y)
    {

        int m = x.size();
        int n = y.size();

        // Length of merged strings
        int msize = m + n;

        // DP table for LCS
        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));

        // Filling DP table
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                // If characters match
                if (x[i - 1] == y[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }

                // If characters do not match
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        // Shortest Common Supersequence Length
        return msize - t[m][n];
    }
};

int main()
{

    Solution obj;

    string x = "geek";
    string y = "eke";

    cout << obj.minSuperSeq(x, y);

    return 0;
}