#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();

        // Pair profit+deadline, sort by profit desc
        vector<pair<int,int>> jobs;
        for (int i = 0; i < n; i++)
            jobs.push_back({profit[i], deadline[i]});
        sort(jobs.begin(), jobs.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });

        int maxDead = *max_element(deadline.begin(), deadline.end());
        vector<int> Task(maxDead + 1, 0);
        vector<int> ans = {0, 0}; // {count, total profit}

        for (int i = 0; i < n; i++) {
            for (int j = jobs[i].second; j > 0; j--) {
                if (!Task[j]) {
                    Task[j] = 1;
                    ans[0]++;
                    ans[1] += jobs[i].first;
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit   = {20, 10, 40, 30};

    Solution obj;
    vector<int> result = obj.jobSequencing(deadline, profit);

    cout << "Jobs done: "  << result[0] << endl;
    cout << "Max profit: " << result[1] << endl;
    // Expected: Jobs done: 2, Max profit: 60

    return 0;
}