#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            pair<int, pair<int,int>>
        > maxh;

        for(int i = 0; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y;

            maxh.push({dist, {x, y}});

            if(maxh.size() > k) {
                maxh.pop();
            }
        }

        vector<vector<int>> ans;

        while(!maxh.empty()) {

            int x = maxh.top().second.first;
            int y = maxh.top().second.second;

            ans.push_back({x, y});

            maxh.pop();
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> points = {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1}
    };

    int k = 2;

    Solution obj;

    vector<vector<int>> ans = obj.kClosest(points, k);

    for(auto &point : ans) {
        cout << "[" << point[0] << ", "
             << point[1] << "]\n";
    }

    return 0;
}