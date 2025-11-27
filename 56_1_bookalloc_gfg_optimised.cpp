#include <bits/stdc++.h>
using namespace std;

// Check if it is possible to allocate books such that
// no student reads more than 'mid' pages.
bool isPossible(vector<int> &arr, int mid, int m) {
    int st = 1;   // number of students needed
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > mid) return false;  // single book exceeds mid → not possible

        if (sum + arr[i] > mid) {
            st++;           // allocate to next student
            sum = arr[i];   // reset sum
        } else {
            sum += arr[i];
        }
    }

    return st <= m;
}

int allocateBooks(vector<int> &arr, int m) {
    int n = arr.size();
    if (n < m) return -1; // edge case: more students than books

    int lo = *max_element(arr.begin(), arr.end());   // minimum possible (largest book)
    int hi = accumulate(arr.begin(), arr.end(), 0);  // maximum possible (sum of all books)
    int ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (isPossible(arr, mid, m)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {10, 20, 30, 40};
    int m = 2;

    cout << allocateBooks(arr, m);
    return 0;
}
