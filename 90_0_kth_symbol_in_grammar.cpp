#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
         if (n == 1 && k == 1)
            return 0;

        int mid = pow(2, n - 1) / 2;

        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } else {
            return !kthGrammar(n - 1, k - mid);
        }
    }
};

int main() {
    Solution obj;
    int n, k;

    cout << "Enter n and k: ";
    cin >> n >> k;

    cout << "Kth Grammar value: " << obj.kthGrammar(n, k) << endl;

    return 0;
}