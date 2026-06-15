#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        fill(children, children + 26, nullptr);
        isEnd = false;
    }
};

TrieNode* root;

void insert(const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int i = c - 'a';
        if (!node->children[i])
            node->children[i] = new TrieNode();
        node = node->children[i];
    }
    node->isEnd = true;
}

bool checkIfPrefixExists(const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int i = c - 'a';
        if (!node->children[i] || !node->children[i]->isEnd)
            return false;
        node = node->children[i];
    }
    return true;
}

string completeString(vector<string>& nums) {
    root = new TrieNode();
    for (auto& s : nums) insert(s);

    string ans = "";
    for (auto& s : nums) {
        if (checkIfPrefixExists(s)) {
            if (s.length() > ans.length() ||
               (s.length() == ans.length() && s < ans))
                ans = s;
        }
    }

    return ans.empty() ? "None" : ans;
}

int main() {
    // Example 1
    vector<string> nums1 = {"n", "ni", "nin", "ninj", "ninja", "nil"};
    cout << completeString(nums1) << endl;  // ninja

    // Example 2
    vector<string> nums2 = {"ninja", "night", "nil"};
    cout << completeString(nums2) << endl;  // None

    return 0;
}