#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // helper
    int binSearch(vector<int>& arr, int tar, int st, int end) {
        if (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] == tar) return mid;
            else if (arr[mid] < tar) {
                return binSearch(arr, tar, mid + 1, end);
            } else {
                return binSearch(arr, tar, st, mid - 1);
            }
        }
        return -1;
    }

    int search(vector<int>& arr, int tar) {
        return binSearch(arr, tar, 0, arr.size() - 1);
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2, 4, 6, 8, 10, 14};
    int target = 6;

    int result = s.search(arr, target);
    cout << "Index of target " << target << " is: " << result << endl;

    return 0;
}
