#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int revNum = 0;

        while (x != 0) {
            int dig = x % 10;

            // Overflow check
            if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10) {
                return 0;
            }

            revNum = revNum * 10 + dig;
            x = x / 10;
        }

        return revNum;
    }
};

int main() {
    Solution obj;
    int x;
    cout << "Enter a number: ";
    cin >> x;

    int ans = obj.reverse(x);
    cout << "Reversed number: " << ans << endl;

    return 0;
}
