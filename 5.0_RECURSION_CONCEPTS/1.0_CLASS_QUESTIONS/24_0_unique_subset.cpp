#include <bits/stdc++.h>
using namespace std;

// recursive function
void solve(vector<int> nums, vector<int> op, map<vector<int>, bool> &mp, vector<vector<int>> &m)
{
    if (nums.size() == 0)
    {
        if (!mp[op]) // check if subset already added
        {
            m.push_back(op);
            mp[op] = true;
        }
        return;
    }

    vector<int> op1 = op;
    vector<int> op2 = op;

    op2.push_back(nums[0]);

    nums.erase(nums.begin());

    solve(nums, op1, mp, m);
    solve(nums, op2, mp, m);
}

// function to generate unique subsets
vector<vector<int>> uniqueSubsets(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // sort to handle duplicates correctly
    vector<vector<int>> m;
    vector<int> op;
    map<vector<int>, bool> mp;
    solve(nums, op, mp, m);
    return m;
}

int main()
{
    vector<int> nums = {1, 2, 2}; // example with duplicates

    vector<vector<int>> result = uniqueSubsets(nums);

    for (auto v : result)
    {
        cout << "{ ";
        for (auto x : v)
            cout << x << " ";
        cout << "}" << endl;
    }

    return 0;
}