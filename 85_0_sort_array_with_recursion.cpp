#include <iostream>
#include <vector>

using namespace std;

// Function to insert an element into its correct position in a sorted vector
void insert(vector<int> &v, int temp) {
    // Base Condition: If vector is empty or temp is greater than the last element
    if (v.size() == 0 || v[v.size() - 1] <= temp) {
        v.push_back(temp);
        return;
    }

    // Induction: Remove the last element and try inserting temp in the smaller vector
    int val = v[v.size() - 1];
    v.pop_back();
    insert(v, temp);

    // After temp is inserted, push the removed element back
    v.push_back(val);
}

// Function to sort the vector using recursion
void sortArray(vector<int> &v) {
    // Base Condition: An array of size 1 is already sorted
    if (v.size() == 1) {
        return;
    }

    // Hypothesis: Assume sortArray can sort an array of size n-1
    int temp = v[v.size() - 1]; // Take out the last element
    v.pop_back();               // Reduce input size
    sortArray(v);               // Recursive call

    // Induction: Put the last element (temp) back into its correct sorted position
    insert(v, temp);
}

int main() {
    vector<int> v = {2, 3, 7, 6, 4, 5, 9};

    sortArray(v);

    cout << "Sorted Array: ";
    for (int x : v) {
        cout << x << " ";
    }
    return 0;
}