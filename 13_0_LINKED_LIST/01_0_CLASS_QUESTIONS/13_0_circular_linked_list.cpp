#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
    Node* tail;

public:
    CircularList() {
        head = tail = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);

        if (tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void deleteAtHead() {
        if (head == NULL) return;
        else if (head == tail) {  // single node
            delete head;
            head = tail = NULL;
        } else {  // 2 or more
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void deleteAtTail() {
        if (head == NULL) return;
        else if (head == tail) {  // single node
            delete tail;
            head = tail = NULL;
        } else {  // 2 or more
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;
        }
    }

    void print() {
        if (head == NULL) return;

        Node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);

        cout << head->data << "(head)" << endl;
    }
};

int main() {
    CircularList cll;

    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);

    cout << "Original: ";
    cll.print();

    cll.deleteAtHead();
    cout << "After deleteAtHead: ";
    cll.print();

    cll.deleteAtTail();
    cout << "After deleteAtTail: ";
    cll.print();

    return 0;
}