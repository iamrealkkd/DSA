#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all unique subsets
// nums -> remaining elements to process
// op -> current subset being formed
// mp -> map to keep track of subsets already added (to avoid duplicates)
// m -> vector of vectors storing all unique subsets
void solve(vector<int> nums, vector<int> op, map<vector<int>, bool> &mp, vector<vector<int>> &m)
{
    // BASE CASE: if no elements left to process
    if (nums.size() == 0)
    {
        // When nums is empty, current subset 'op' is complete
        // Check if this subset is already added in map
        if (!mp[op])
        {
            m.push_back(op);    // Add current subset to final result
            mp[op] = true;      // Mark this subset as added to avoid duplicates
        }
        return; // End this recursion branch
    }

    // CREATE TWO OPTIONS FOR CURRENT ELEMENT nums[0]
    vector<int> op1 = op;     // Option1: DO NOT include nums[0] in subset
    vector<int> op2 = op;     // Option2: INCLUDE nums[0] in subset
    op2.push_back(nums[0]);   // Include the first element in op2

    // Remove first element from remaining elements
    nums.erase(nums.begin());

    // RECURSION: explore both choices
    solve(nums, op1, mp, m);  // Path where current element is excluded
    solve(nums, op2, mp, m);  // Path where current element is included
}

// Function to generate all unique subsets
vector<vector<int>> uniqueSubsets(vector<int> &nums)
{
    // SORT the array to handle duplicates correctly
    // Sorting ensures subsets like {2,1} and {1,2} are treated the same
    sort(nums.begin(), nums.end());

    vector<vector<int>> m;     // Stores all unique subsets
    vector<int> op;            // Current subset being formed
    map<vector<int>, bool> mp; // Map to track duplicates

    // Start recursion
    solve(nums, op, mp, m);

    return m; // Return all unique subsets
}

int main()
{
    vector<int> nums = {1, 2, 2}; // Example input with duplicates

    // Generate all unique subsets
    vector<vector<int>> result = uniqueSubsets(nums);

    // PRINT ALL UNIQUE SUBSETS
    for (auto v : result)
    {
        cout << "{ ";
        for (auto x : v)
            cout << x << " "; // Print elements of current subset
        cout << "}" << endl;
    }

    return 0;
}

/*
WORKING EXPLANATION:

1. Start with empty subset: op = {}
2. For each element in nums, make two choices:
   a) Exclude the element (op1)
   b) Include the element (op2)
3. Remove the element from nums for the next recursion
4. Call recursion for both choices (binary tree of subsets)
5. Base case: when nums is empty, the current subset 'op' is complete
   - Check map to see if subset is already added
   - If not, push it to result and mark in map
6. Sorting ensures duplicates are handled correctly
   - e.g., {2,1} and {1,2} will be treated as same
7. After recursion finishes, 'm' contains all unique subsets
8. Final output prints all subsets in sorted order
*/