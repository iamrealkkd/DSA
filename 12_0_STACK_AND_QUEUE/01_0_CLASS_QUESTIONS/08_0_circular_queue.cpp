#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int currSize, cap;
    int f, r;

public:
    CircularQueue(int size) {
        cap = size;
        arr = new int[cap];
        f = 0;
        r = -1;
    }

    void push(int data) {
        if (currSize == cap) {
            cout << "CQ is FULL\n";
            return;
        }

        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    void pop() {
        if (empty()) {
            cout << "CQ is EMPTY\n";
            return;
        }

        f = (f + 1) % cap;
        currSize--;
    }

    int front() {
        if (empty()) {
            cout << "CQ is EMPTY\n";
            return -1;
        }
        return arr[f];
    }

    bool empty() { // O(1)
        return currSize == 0;
    }
};

int main() {
    CircularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4); // CQ is FULL (cap = 3)

    cout << cq.front() << endl; // 1
    cq.pop();
    cout << cq.front() << endl; // 2

    cq.push(5); // wraps around, reuses freed slot
    cq.pop();
    cq.pop();
    cout << cq.front() << endl; // 5

    return 0;
}