#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int assignHole(vector<int>& mices, vector<int>& holes) {

        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());

        int ans = 0;

        for (int i = 0; i < mices.size(); i++) {
            ans = max(ans, abs(mices[i] - holes[i]));
        }

        return ans;
    }
};

int main() {

    vector<int> mices = {4, -4, 2};
    vector<int> holes = {4, 0, 5};

    Solution obj;

    int ans = obj.assignHole(mices, holes);

    cout << "Minimum time required = " << ans << endl;

    return 0;
}