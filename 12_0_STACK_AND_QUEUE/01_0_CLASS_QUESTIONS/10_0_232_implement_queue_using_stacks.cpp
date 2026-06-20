#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1; // for push
    stack<int> s2; // for pop/peek

public:
    MyQueue() {

    }

    void push(int x) { // O(1)
        s1.push(x);
    }

    int pop() { // amortized O(1)
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int ans = s2.top();
        s2.pop();
        return ans;
    }

    int peek() { // amortized O(1)
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.peek() << endl;   // 1
    cout << q.pop() << endl;    // 1
    cout << q.peek() << endl;   // 2
    cout << q.empty() << endl;  // 0 (false)

    q.pop();
    q.pop();
    cout << q.empty() << endl;  // 1 (true)

    return 0;
}