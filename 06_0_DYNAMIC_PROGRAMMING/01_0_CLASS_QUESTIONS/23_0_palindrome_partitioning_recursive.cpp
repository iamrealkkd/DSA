#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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

        if (isPalindrome(s, i, j))
            return 0;

        int mn = INT_MAX;

        for (int k = i; k <= j - 1; k++)
        {
            int temp =
                1 +
                solve(s, i, k) +
                solve(s, k + 1, j);

            mn = min(mn, temp);
        }

        return mn;
    }

    int palPartition(string str)
    {

        return solve(str, 0, str.length() - 1);
    }
};

int main()
{
    Solution obj;

    string str = "geek";

    cout << obj.palPartition(str);

    return 0;
}