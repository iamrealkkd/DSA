#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {

    }

    void push(int x) { // O(n)
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << endl;   // 3
    cout << st.pop() << endl;   // 3
    cout << st.top() << endl;   // 2
    cout << st.empty() << endl; // 0 (false)

    st.pop();
    st.pop();
    cout << st.empty() << endl; // 1 (true)

    return 0;
}