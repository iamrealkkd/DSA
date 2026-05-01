#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        int st = 0, end = n - 1;

        if (n == 1) return A[0]; // if only one element, return it

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Edge cases (first and last element)
            if (mid == 0 && A[0] != A[1]) return A[mid];
            if (mid == n - 1 && A[n - 1] != A[n - 2]) return A[mid];

            // Found the unique element
            if (A[mid - 1] != A[mid] && A[mid] != A[mid + 1]) return A[mid];

            // Binary search logic
            if (mid % 2 == 0) { // even index
                if (A[mid - 1] == A[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else { // odd index
                if (A[mid - 1] == A[mid]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1; // should never reach here for valid input
    }
};

int main() {
    Solution sol;
    vector<int> A = {1, 1, 2, 2, 3, 4, 4, 5, 5}; // only 3 is unique

    int ans = sol.singleNonDuplicate(A);

    cout << "Single non-duplicate element: " << ans << endl;

    return 0;
}
