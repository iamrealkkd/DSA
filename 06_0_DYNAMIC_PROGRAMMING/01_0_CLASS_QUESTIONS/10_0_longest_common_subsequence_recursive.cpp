#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive LCS Function
    int longestCommonSubsequence(string x, string y, int n, int m)
    {

        // Base Case
        if (n == 0 || m == 0)
            return 0;

        // If characters match
        if (x[n - 1] == y[m - 1])
            return 1 + longestCommonSubsequence(x, y, n - 1, m - 1);

        // If characters do not match
        return max(
            longestCommonSubsequence(x, y, n, m - 1),
            longestCommonSubsequence(x, y, n - 1, m));
    }
};

int main()
{

    // Default values
    string text1 = "abcde";
    string text2 = "ace";

    int n = text1.size();
    int m = text2.size();

    Solution obj;

    cout << obj.longestCommonSubsequence(text1, text2, n, m);

    return 0;
}