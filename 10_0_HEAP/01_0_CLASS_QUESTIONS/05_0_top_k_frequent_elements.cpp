#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

typedef priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> PPI;

vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int, int> mp;

    // Count frequencies
    for (int x : nums) {
        mp[x]++;
    }

    PPI minh;

    for (auto it = mp.begin(); it != mp.end(); it++) {

        minh.push({it->second, it->first});

        if (minh.size() > k) {
            minh.pop();
        }
    }

    vector<int> ans;

    while (!minh.empty()) {
        ans.push_back(minh.top().second);
        minh.pop();
    }

    return ans;
}

int main() {

    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 4};
    int k = 2;

    vector<int> ans = topKFrequent(nums, k);

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}