#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double myPow(double x, int n) {
    if (n == 0) return 1.0;
    if (x == 0) return 0.0;
    if (x == 1) return 1.0;
    if (x == -1 && n % 2 == 0) return 1.0;
    if (x == -1 && n % 2 != 0) return -1.0;

    long long binform = n; // long long to handle large exponents
    if (n < 0) {
        x = 1 / x;
        binform = -binform;
    }

    double ans = 1.0;
    while (binform > 0) {
        if (binform % 2 == 1) {
            ans *= x;
        }
        x *= x;
        binform /= 2;
    }
    return ans;
}

int main() {
    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    double result = myPow(x, n);
    cout << "Result: " << result << endl;

    return 0;
}