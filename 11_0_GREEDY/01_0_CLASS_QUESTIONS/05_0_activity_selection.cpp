#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

class Solution {
public:
    int activitySelection(vector<int>& start, vector<int>& finish) {
        int n = start.size();
        vector<pair<int,int>> timer;

        for (int i = 0; i < n; i++)
            timer.push_back({start[i], finish[i]});

        sort(timer.begin(), timer.end(), comp);

        int count = 1;
        int lastEnd = timer[0].second;

        for (int i = 1; i < n; i++) {
            if (timer[i].first > lastEnd) {
                count++;
                lastEnd = timer[i].second;
            }
        }
        return count;
    }
};

int main() {
    vector<int> start  = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    Solution obj;
    cout << "Max activities: " << obj.activitySelection(start, finish) << endl;
    // Expected: 4

    return 0;
}