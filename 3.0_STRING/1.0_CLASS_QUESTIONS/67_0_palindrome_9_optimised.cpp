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

    bool isPalindrome(int x) {
        if (x < 0) return false;

        int revNum = reverse(x);

        return x == revNum;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (obj.isPalindrome(n))
        cout << n << " is a Palindrome number." << endl;
    else
        cout << n << " is NOT a Palindrome number." << endl;

    return 0;
}
