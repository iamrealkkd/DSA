#include <bits/stdc++.h>
using namespace std;

bool solve(string a, string b)
{
    // Base cases
    if(a == b)
        return true;

    if(a.length() <= 1)
        return false;
    
    if(a.length() && b.length() == 0)
        return true;

    int n = a.length();

    for(int i = 1; i <= n - 1; i++)
    {
        // Swap case
        bool cond1 =
            solve(a.substr(0, i), b.substr(n - i, i)) &&
            solve(a.substr(i, n - i), b.substr(0, n - i));

        // No swap case
        bool cond2 =
            solve(a.substr(0, i), b.substr(0, i)) &&
            solve(a.substr(i, n - i), b.substr(i, n - i));

        if(cond1 || cond2)
            return true;
    }

    return false;
}

int main()
{
    string s1 = "great";
    string s2 = "rgeat";

    if(solve(s1, s2))
        cout << "true";
    else
        cout << "false";

    return 0;
}