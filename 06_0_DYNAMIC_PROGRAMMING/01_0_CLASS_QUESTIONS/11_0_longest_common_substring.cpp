#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longCommSubstr(string &x, string &y)
    {
        int m = x.size();
        int n = y.size();

        vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));
        int ans = 0;

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
                {

                    t[i][j] = 1 + t[i - 1][j - 1];
                    ans = max(ans, 1 + t[i - 1][j - 1]);
                }
                // If characters do not match
                else
                    t[i][j] = 0;
            }
        }

        return ans;
    }
};

int main()
{

    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    Solution obj;

    cout << obj.longCommSubstr(s1, s2);

    return 0;
}