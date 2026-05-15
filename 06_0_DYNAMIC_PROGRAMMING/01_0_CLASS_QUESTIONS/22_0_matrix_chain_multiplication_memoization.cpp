#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &arr, int i, int j, int t[1001][1001])
    {
        if (i >= j)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        int mn = INT_MAX;

        for (int k = i; k <= j - 1; k++)
        {
            int temp_ans =
                solve(arr, i, k, t) +
                solve(arr, k + 1, j, t) +
                arr[i - 1] * arr[k] * arr[j];

            if (temp_ans < mn)
                mn = temp_ans;
        }

        return t[i][j] = mn;
    }

    int matrixMultiplication(vector<int> &arr)
    {
        static int t[1001][1001];

        memset(t, -1, sizeof(t));

        int i = 1;
        int j = arr.size() - 1;

        return solve(arr, i, j, t);
    }
};

int main()
{
    vector<int> arr = {2, 1, 3, 4};

    Solution obj;

    cout << obj.matrixMultiplication(arr);

    return 0;
}