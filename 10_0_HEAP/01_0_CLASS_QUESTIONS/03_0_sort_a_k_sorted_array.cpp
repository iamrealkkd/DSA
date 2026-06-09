#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef priority_queue<
    int,
    vector<int>,
    greater<int>
> PPI;

vector<int> sortKSortedArray(vector<int>& arr, int k) {

    PPI minh;
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++) {

        minh.push(arr[i]);

        if (minh.size() > k) {
            ans.push_back(minh.top());
            minh.pop();
        }
    }

    while (!minh.empty()) {
        ans.push_back(minh.top());
        minh.pop();
    }

    return ans;
}

int main() {

    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    vector<int> ans = sortKSortedArray(arr, k);
    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}