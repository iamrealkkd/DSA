#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0; // answer
        int lp = 0; // left pointer
        int rp = height.size() - 1; // right pointer

        while (lp < rp) {
            int w = rp - lp; // width
            int ht = min(height[lp], height[rp]); // height of water
            int currWater = w * ht; // current container area

            maxWater = max(maxWater, currWater); // update max

            // Move the pointer that points to the shorter line
            if (height[lp] < height[rp]) {
                lp++;
            } else {
                rp--;
            }
        }
        return maxWater;
    }
};

int main() {
    int n;
    cout << "Enter number of lines: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution obj;
    int result = obj.maxArea(height);

    cout << "Maximum Area: " << result << endl;

    return 0;
}