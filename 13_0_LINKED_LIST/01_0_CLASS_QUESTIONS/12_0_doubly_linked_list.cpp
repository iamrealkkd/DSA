#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void printForward() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void printBackward() {
        Node* temp = tail;

        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        cout << "NULL" << endl;
    }
};

int main() {

    DoublyList dll;

    dll.push_front(20);
    dll.push_front(10);

    dll.push_back(30);
    dll.push_back(40);

    cout << "Forward Traversal:\n";
    dll.printForward();

    cout << "\nBackward Traversal:\n";
    dll.printBackward();

    return 0;
}