#include <bits/stdc++.h>
using namespace std;

// recursive function
void solve(vector<int> nums, vector<int> op, vector<vector<int>> &m)
{
    if (nums.size() == 0)
    {
        m.push_back(op);
        return;
    }

    vector<int> op1 = op;
    vector<int> op2 = op;

    op2.push_back(nums[0]);

    nums.erase(nums.begin());

    solve(nums, op1, m);
    solve(nums, op2, m);
}

// function to generate subsets
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> m;
    vector<int> op;
    solve(nums, op, m);
    return m;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    for (auto v : result)
    {
        cout << "{ ";
        for (auto x : v)
            cout << x << " ";
        cout << "}" << endl;
    }

    return 0;
}