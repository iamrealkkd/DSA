#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDays(int S, int N, int M) {
        int sunday     = S / 7;
        int buyingDays = S - sunday;
        int totalFood  = S * M;
        int ans        = 0;

        if (totalFood % N == 0)
            ans = totalFood / N;
        else
            ans = totalFood / N + 1;

        if (ans <= buyingDays)
            return ans;
        else
            return -1;
    }
};

int main() {
    Solution obj;

    cout << obj.minimumDays(3, 20, 5)  << endl; // Expected: 2
    cout << obj.minimumDays(10, 20, 30) << endl; // Expected: -1

    return 0;
}