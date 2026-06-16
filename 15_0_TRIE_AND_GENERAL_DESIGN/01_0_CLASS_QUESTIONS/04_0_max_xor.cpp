#include <bits/stdc++.h>
using namespace std;

// Binary Trie - 2 children only (0 and 1) instead of 26
struct Node {
    Node* links[2];
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    Node* get(int bit) {
        return links[bit];
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node() {
        links[0] = links[1] = NULL;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // num ko 32-bit binary mein insert karo (MSB se LSB)
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    // num ke saath max XOR dhundo trie mein
    // greedy: har bit pe opposite bit prefer karo
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {  // opposite bit exist karta hai?
                maxNum = maxNum | (1 << i);     // ye bit XOR mein 1 banega
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);          // opposite nahi mila, same lo
            }
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int>& arr1, vector<int>& arr2) {
    Trie trie;

    // arr1 ke saare elements insert karo
    for (auto& it : arr1) trie.insert(it);

    int maxi = 0;

    // arr2 ke har element ke saath max XOR nikalo
    for (auto& it : arr2) {
        maxi = max(maxi, trie.getMax(it));
    }

    return maxi;
}

int main() {
    // Example 1
    vector<int> arr1 = {6, 8, 1};
    vector<int> arr2 = {5, 9, 3};
    int n = arr1.size(), m = arr2.size();
    cout << maxXOR(n, m, arr1, arr2) << endl; // 15

    
    return 0;
}