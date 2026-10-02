#include <iostream>
#include <vector>

using namespace std;

int recursion(const vector<int> &nums, int i, bool prevPick) {
  int n = nums.size();

  // Base Case: Jab pure array ke elements process ho jayein
  if (i == n) {
    return (prevPick == true) ? 1 : 0;
  }

  // Case 1: Agar pichla element pick ho chuka hai (Continuous Subarray
  // continuation)
  if (prevPick) {
    int pickInSubarr =
        recursion(nums, i + 1, true); // Continue subarray with next element
    int stopHere = 1;                 // Terminate current subarray here
    return (pickInSubarr + stopHere);
  }
  // Case 2: Agar abhi tak koi element pick nahi hua hai
  else {
    int startNewFromNext =
        recursion(nums, i + 1, false); // Skip current element
    int startNewFromCurr =
        recursion(nums, i + 1, true); // Start new subarray from current element
    return (startNewFromNext + startNewFromCurr);
  }
}

int main() {
  vector<int> nums = {2, 2, 3, 6, 5};

  // Initial call: index i = 0, prevPick = false
  int totalSubarrays = recursion(nums, 0, false);
  cout <<  totalSubarrays << endl;//n * (n + 1)/2

  return 0;
}