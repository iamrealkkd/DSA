#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kLargest(vector<int>& arr, int k) {

    priority_queue<int, vector<int>, greater<int>> minh;

    for (int i = 0; i < arr.size(); i++) {

        minh.push(arr[i]);

        if (minh.size() > k) {
            minh.pop();
        }
    }

    vector<int> ans;

    while (!minh.empty()) {
        ans.push_back(minh.top());
        minh.pop();
    }

    return ans;
}

int main() {

    vector<int> arr = {10, 7, 4, 3, 20, 15};
    int k = 3;

    vector<int> ans = kLargest(arr, k);
    while (!ans.empty()) {
        cout << ans.back() << " ";
        ans.pop_back();
    }

    cout << endl;

    return 0;
}