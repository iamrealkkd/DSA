#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

typedef priority_queue<pair<int,int>> PPI;

vector<int> frequencySort(vector<int>& nums) {

    unordered_map<int,int> mp;

    for(int x : nums)
    {
        mp[x]++;
    }

    PPI maxh;

    for(auto &it : mp)
    {
        maxh.push({it.second, it.first});
    }

    vector<int> ans;

    while(!maxh.empty())
    {
        int freq = maxh.top().first;
        int ele  = maxh.top().second;

        for(int i = 1; i <= freq; i++)
        {
            ans.push_back(ele);
        }

        maxh.pop();
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,1,1,3,2,2,4};

    vector<int> ans = frequencySort(nums);

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}