#include <iostream>
#include <stack>
using namespace std;

// Function to insert element in sorted stack
void insertSorted(stack<int> &st, int temp) {
    // Base condition
    if (st.empty() || st.top() <= temp) {
        st.push(temp);
        return;
    }

    // Remove top and recurse
    int val = st.top();
    st.pop();
    insertSorted(st, temp);

    // Push back removed element
    st.push(val);
}

// Function to sort stack using recursion
void sortStack(stack<int> &st) {
    // Base condition
    if (st.size() == 1) return;

    // Remove top element
    int temp = st.top();
    st.pop();

    // Sort remaining stack
    sortStack(st);

    // Insert temp in sorted position
    insertSorted(st, temp);
}

int main() {
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(7);
    st.push(6);
    st.push(4);
    st.push(5);
    st.push(9);

    sortStack(st);

    cout << "Sorted Stack (Top to Bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
