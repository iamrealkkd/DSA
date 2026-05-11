#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive LCS Function
    int longestCommonSubsequence(string x, string y, int m, int n)
    {
        vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));

        // Base Case
        if (m == 0 || n == 0)
            return 0;
        if (t[m][n] != -1)
            return t[m][n];
        // If characters match
        if (x[m - 1] == y[n - 1])
            return t[m][n] = 1 + longestCommonSubsequence(x, y, n - 1, m - 1);

        // If characters do not match
        return t[m][n] = max(
                   longestCommonSubsequence(x, y, n, m - 1),
                   longestCommonSubsequence(x, y, n - 1, m));
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