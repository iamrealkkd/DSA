#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {

        int idx = m + n - 1;  
        int i = m - 1;        
        int j = n - 1;        

        while(i >= 0 && j >= 0){
            if(A[i] >= B[j]){
                A[idx--] = A[i--];
            } else {
                A[idx--] = B[j--];
            }
        }

        while(j >= 0){
            A[idx--] = B[j--];
        }
    }
};

int main() {
    vector<int> A = {1, 2, 3, 0, 0, 0};
    vector<int> B = {2, 5, 6};
    int m = 3;
    int n = 3;

    Solution s;
    s.merge(A, m, B, n);

    cout << "Merged Array: ";
    for(int x : A) cout << x << " ";
    cout << endl;

    return 0;
}
