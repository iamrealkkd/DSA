#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mcm(vector<int> &arr, int i, int j)
    {
        if (i >= j)
            return 0;
        int mn = INT_MAX;

        for (int k = i; k <= j - 1; k++)
        {
            int temp_ans = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

            if (temp_ans < mn)
                mn = temp_ans;
        }

        return mn;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {40, 20, 30, 10, 30};
    int i = 1;
    int j = arr.size() - 1;
    cout << obj.mcm(arr, i, j);
}
