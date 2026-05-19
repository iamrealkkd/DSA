#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>>t{101, vector<int>(10001, -1)};

    int solve(int e, int f)
    {
        // Base Cases
        if(f == 0 || f == 1)
            return f;

        if(e == 1)
            return f;

        // Memoization
        if(t[e][f] != -1)
            return t[e][f];

        int mn = INT_MAX;

        for(int k = 1; k <= f; k++)
        {
            int low, high;

            // Egg breaks
            if(t[e - 1][k - 1] != -1)
                low = t[e - 1][k - 1];
            else
            {
                low = solve(e - 1, k - 1);
                t[e - 1][k - 1] = low;
            }

            // Egg does not break
            if(t[e][f - k] != -1)
                high = t[e][f - k];
            else
            {
                high = solve(e, f - k);
                t[e][f - k] = high;
            }

            int temp = 1 + max(low, high);

            mn = min(mn, temp);
        }

        return t[e][f] = mn;
    }

    int superEggDrop(int k, int n)
    {
        return solve(k, n);
    }
};

int main()
{
    int k = 2; // eggs
    int n = 6; // floors

    Solution obj;

    cout << obj.superEggDrop(k, n);

    return 0;
}