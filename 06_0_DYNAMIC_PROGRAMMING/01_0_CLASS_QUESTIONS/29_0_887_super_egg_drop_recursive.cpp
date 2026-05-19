#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int superEggDrop(int e, int f) {
        
        // Base Cases
        if (f == 0 || f == 1)
            return f;

        if (e == 1)
            return f;

        int mn = INT_MAX;

        for (int k = 1; k <= f; k++) {

            int breaks = superEggDrop(e - 1, k - 1);
            int notBreaks = superEggDrop(e, f - k);

            int temp = 1 + max(breaks, notBreaks);

            mn = min(mn, temp);
        }

        return mn;
    }
};

int main() {

    int k = 1; // eggs
    int n = 2; // floors

    Solution obj;

    cout << obj.superEggDrop(k, n);

    return 0;
}