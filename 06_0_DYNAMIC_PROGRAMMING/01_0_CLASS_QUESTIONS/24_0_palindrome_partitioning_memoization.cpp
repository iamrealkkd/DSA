#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int t[1001][1001];

    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    int solve(string &s, int i, int j)
    {
        if (i >= j)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        if (isPalindrome(s, i, j))
            return 0;

        int mn = INT_MAX;

        for (int k = i; k <= j - 1; k++)
        {
            int left, right;

            if (t[i][k] != -1)
            {
                left = t[i][k];
            }
            else
            {
                left = solve(s, i, k);
                t[i][k] = left;
            }

            if (t[k + 1][j] != -1)
            {
                right = t[k + 1][j];
            }
            else
            {
                right = solve(s, k + 1, j);
                t[k + 1][j] = right;
            }

            int temp = 1 + left + right;

            mn = min(mn, temp);
        }

        return t[i][j] = mn;
    }

    int palPartition(string &str)
    {

        memset(t, -1, sizeof(t));
        return solve(str, 0, str.length() - 1);
    }
};

int Solution::t[1001][1001];

int main()
{
    Solution obj;

    string str = "geek";

    cout << obj.palPartition(str);

    return 0;
}