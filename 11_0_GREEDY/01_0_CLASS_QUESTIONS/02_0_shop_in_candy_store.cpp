#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {

        sort(prices.begin(), prices.end());

        int n = prices.size();

        int min_amount = 0, max_amount = 0;

        int i = 0, j = n - 1;

        // Minimum cost
        while (i <= j) {
            min_amount += prices[i];
            i++;
            j -= k;
        }

        // Maximum cost
        i = n - 1;
        j = 0;

        while (i >= j) {
            max_amount += prices[i];
            i--;
            j += k;
        }

        return {min_amount, max_amount};
    }
};

int main() {

    vector<int> prices = {3, 2, 1, 4};
    int k = 2;

    Solution obj;

    vector<int> ans = obj.minMaxCandy(prices, k);

    cout << "Minimum Cost = " << ans[0] << endl;
    cout << "Maximum Cost = " << ans[1] << endl;

    return 0;
}