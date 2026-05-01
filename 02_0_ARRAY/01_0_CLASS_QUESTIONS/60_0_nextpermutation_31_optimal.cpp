#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& A){

        int pivot = -1, n = A.size();

        // Step 1: Find pivot (first decreasing element from right)
        for(int i = n - 2; i >= 0; i--){
            if(A[i] < A[i + 1]){
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot → array is in descending order → reverse it
        if(pivot == -1){
            reverse(A.begin(), A.end());
            return;
        }

        // Step 3: Find element just larger than pivot
        for(int i = n - 1; i > pivot; i--){
            if(A[i] > A[pivot]){
                swap(A[i], A[pivot]);
                break;
            }
        }

        // Step 4: Reverse the suffix after pivot
        int i = pivot + 1, j = n - 1;
        while(i < j){
            swap(A[i++], A[j--]);
        }
    }
};

int main() {
    vector<int> A = {1, 2, 3};

    Solution s;
    s.nextPermutation(A);

    cout << "Next Permutation: ";
    for(int x : A) cout << x << " ";
    cout << endl;

    return 0;
}
