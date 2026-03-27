#include <iostream>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;

        if (k % 2 == 1)
            return kthGrammar(n - 1, (k + 1) / 2);
        else
            return 1 - kthGrammar(n - 1, k / 2);
    }
};

int main() {
    Solution obj;
    int n, k;

    cout << "Enter n and k: ";
    cin >> n >> k;

    int result = obj.kthGrammar(n, k);

    cout << "Kth Grammar value is: " << result << endl;

    return 0;
}