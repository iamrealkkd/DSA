#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef priority_queue<pair<int, int>> PPI;

vector<int> kClosest(vector<int>& arr, int k, int x) {

    PPI maxh;

    for (int i = 0; i < arr.size(); i++) {

        maxh.push({abs(arr[i] - x), arr[i]});

        if (maxh.size() > k) {
            maxh.pop();
        }
    }

    vector<int> ans;

    while (!maxh.empty()) {
        ans.push_back(maxh.top().second);
        maxh.pop();
    }

    return ans;
}

int main() {

    vector<int> arr = {5, 6, 7, 8, 9};
    int k = 3;
    int x = 7;

    vector<int> ans = kClosest(arr, k, x);
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}