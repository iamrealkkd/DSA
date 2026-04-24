#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};

int main() {
    Solution obj;

    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "GCD is: " << obj.gcd(a, b) << endl;

    return 0;
}
