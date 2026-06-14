#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, dead, profit;
};

class Solution {
public:
    vector<int> JobScheduling(Job arr[], int n) {
        // Sort by profit descending
        sort(arr, arr + n, [](Job a, Job b) {
            return a.profit > b.profit;
        });

        int maxDead = 0;
        for (int i = 0; i < n; i++)
            maxDead = max(maxDead, arr[i].dead);

        vector<int> Task(maxDead + 1, 0); // Task[j] = slot taken?
        vector<int> ans = {0, 0};         // {count, total profit}

        for (int i = 0; i < n; i++) {
            // Try to fit job in latest available slot before deadline
            for (int j = arr[i].dead; j > 0; j--) {
                if (!Task[j]) {
                    Task[j] = 1;
                    ans[0]++;
                    ans[1] += arr[i].profit;
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    Job arr[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };
    int n = 4;

    Solution obj;
    vector<int> result = obj.JobScheduling(arr, n);

    cout << "Jobs done: "    << result[0] << endl;
    cout << "Max profit: "   << result[1] << endl;
    // Expected: Jobs done: 2, Max profit: 60

    return 0;
}