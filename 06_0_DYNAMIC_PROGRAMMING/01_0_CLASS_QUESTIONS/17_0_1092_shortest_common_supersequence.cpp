#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string x, string y)
    {

        int m = x.size();
        int n = y.size();

        vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));

        // Initialization
        for (int i = 0; i <= m; i++)
            t[i][0] = 0;

        for (int j = 0; j <= n; j++)
            t[0][j] = 0;

        // DP Table Filling (LCS)
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

        string ans = "";

        int i = m;
        int j = n;

        // Backtracking
        while (i > 0 && j > 0)
        {

            // Same character
            if (x[i - 1] == y[j - 1])
            {

                ans.push_back(x[i - 1]);

                i--;
                j--;
            }

            // Move upward
            else if (t[i - 1][j] > t[i][j - 1])
            {

                ans.push_back(x[i - 1]);

                i--;
            }

            // Move left
            else
            {

                ans.push_back(y[j - 1]);

                j--;
            }
        }

        // Remaining characters of x
        while (i > 0)
        {

            ans.push_back(x[i - 1]);

            i--;
        }

        // Remaining characters of y
        while (j > 0)
        {

            ans.push_back(y[j - 1]);

            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    // Default values
    string str1 = "abac";
    string str2 = "cab";

    Solution obj;

    cout << obj.shortestCommonSupersequence(str1, str2);

    return 0;
}