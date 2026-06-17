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

    void pop_front() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        // Single node
        if (head == tail) {
            head = tail = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
    }

    void pop_back() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail;

        // Single node
        if (head == tail) {
            head = tail = NULL;
        }
        else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
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

    cout << "Original List:\n";
    dll.printForward();

    dll.pop_front();

    cout << "\nAfter pop_front():\n";
    dll.printForward();

    dll.pop_back();

    cout << "\nAfter pop_back():\n";
    dll.printForward();

    return 0;
}