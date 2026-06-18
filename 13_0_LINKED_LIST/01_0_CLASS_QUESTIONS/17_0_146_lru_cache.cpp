#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // add after head (most recently used)
    void addNode(Node* newNode) {
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    // remove any node from middle
    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* node = m[key];
            int ans = node->val;

            // move to front (recently used)
            m.erase(key);
            delNode(node);
            addNode(node);
            m[key] = head->next;

            return ans;
        }
        return -1;
    }

    void put(int key, int val) {
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        // if at capacity, remove LRU (before tail)
        if (m.size() == limit) {
            Node* lruNode = tail->prev;
            m.erase(lruNode->key);
            delNode(lruNode);
        }

        Node* newNode = new Node(key, val);
        addNode(newNode);
        m[key] = head->next;
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;  // 1
    cache.put(3, 3);               // evicts key 2
    cout << cache.get(2) << endl;  // -1 (evicted)
    cache.put(4, 4);               // evicts key 1
    cout << cache.get(1) << endl;  // -1 (evicted)
    cout << cache.get(3) << endl;  // 3
    cout << cache.get(4) << endl;  // 4

    return 0;
}