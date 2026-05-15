#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int LongestRepeatingSubsequence(string &x)
    {

        string y = x;

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

                // If characters match and indexes are different
                if (x[i - 1] == y[j - 1] && i != j)
                    t[i][j] = 1 + t[i - 1][j - 1];

                // If characters do not match
                else
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }

        return t[m][n];
    }
};

int main()
{

    string str = "axxzxy";

    Solution obj;

    cout << obj.LongestRepeatingSubsequence(str);

    return 0;
}