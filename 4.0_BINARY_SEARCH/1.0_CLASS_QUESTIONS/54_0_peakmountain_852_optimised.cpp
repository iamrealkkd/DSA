#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int st = 1, end = A.size() - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) {
                return mid; // Found peak
            } 
            else if (A[mid - 1] < A[mid]) {
                st = mid + 1; // Move right
            } 
            else {
                end = mid - 1; // Move left
            }
        }

        return -1; // Should not happen for valid mountain array
    }
};

int main() {
    Solution obj;
    vector<int> A = {0, 2, 4, 6, 3, 1}; // Example mountain array

    int ans = obj.peakIndexInMountainArray(A);
    cout << "Peak index: " << ans << endl;
    cout << "Peak value: " << A[ans] << endl;

    return 0;
}
