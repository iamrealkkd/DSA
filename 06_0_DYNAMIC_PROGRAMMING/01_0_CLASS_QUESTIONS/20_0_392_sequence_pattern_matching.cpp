#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string x, string y)
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

        if (k == x.length())
            return true;

        return false;
    }
};

int main()
{

    // Default values
    string s = "abc";
    string t = "ahbgdc";

    Solution obj;

    cout << obj.isSubsequence(s, t);

    return 0;
}