#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* links[26];
    bool flag;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        flag = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }

        node->setEnd();
    }

    bool search(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }

        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");

    cout << trie.search("apple") << endl;     // 1
    cout << trie.search("app") << endl;       // 0
    cout << trie.startsWith("app") << endl;   // 1

    trie.insert("app");

    cout << trie.search("app") << endl;       // 1

    return 0;
}
// ==============================================================
// TRIE DATA STRUCTURE - COMPLETE NOTES
// ==============================================================
//
// WHAT IS TRIE?
// -------------
// Trie (pronounced "try") ek tree-based data structure hai
// jo strings ko character by character store karta hai
// "Re-TRIE-val" se naam aaya hai
//
// STRUCTURE:
// ----------
// - Har node ek character represent karta hai
// - Root node empty hota hai
// - Har node ke 26 children hote hain (a-z)
// - isEnd flag batata hai ki koi word yahan khatam hota hai
//
// VISUAL EXAMPLE:
// ---------------
// Insert: "cat", "car", "card", "care", "bat"
//
//           root
//          /    \
//         c      b
//         |      |
//         a      a
//        / \     |
//       t*  r*   t*
//          / \
//         d*  e*
//
// (* = isEnd true)
//
// "cat" aur "car" common prefix "ca" share karte hain
// iska matlab "ca" sirf ek baar store hoga → space efficient
//
// ==============================================================
// OPERATIONS & TIME COMPLEXITY
// ==============================================================
//
// 1. INSERT     → O(L)   L = length of word
// 2. SEARCH     → O(L)
// 3. PREFIX CHECK → O(L)
// 4. DELETE     → O(L)
//
// Space: O(N × L × 26)  N = total words, L = avg length
//
// ==============================================================
// TRIE vs OTHER DATA STRUCTURES
// ==============================================================
//
// | Operation      | Array  | HashSet | Trie  |
// |----------------|--------|---------|-------|
// | Insert         | O(N)   | O(L)    | O(L)  |
// | Search         | O(N×L) | O(L)    | O(L)  |
// | Prefix Search  | O(N×L) | ❌      | O(L)  |
// | Autocomplete   | ❌     | ❌      | ✅    |
// | Sorted Order   | ❌     | ❌      | ✅    |
//
// HashSet se fast search hota hai but PREFIX search nahi hota
// Trie mein PREFIX search naturally O(L) mein hota hai → main advantage
//
// ==============================================================
// WHERE IS TRIE USED? (REAL WORLD)
// ==============================================================
//
// 1. AUTOCOMPLETE
//    → Google search bar, VS Code intellisense, phone keyboard
//    → "nin" type karo → "ninja", "night" suggest karo
//
// 2. SPELL CHECKER
//    → Dictionary words trie mein store karo
//    → Misspelled word check karo O(L) mein
//
// 3. PREFIX SEARCH
//    → "kya koi word 'pre' se start hota hai?"
//    → Trie mein sirf 3 nodes traverse karo → done
//
// 4. WORD GAMES
//    → Boggle, Scrabble solvers
//    → Valid words fast dhundne ke liye
//
// 5. IP ROUTING (Longest Prefix Match)
//    → Routers network packets route karne ke liye trie use karte hain
//    → Binary trie hota hai (0 aur 1 children)
//
// 6. CONTACT SEARCH
//    → Phone mein "Ra" type karo → "Rahul", "Raj", "Ramesh" aata hai
//
// 7. BROWSER HISTORY
//    → URL prefix se history suggest karta hai browser
//
// ==============================================================
// WHEN TO USE TRIE IN CP/DSA?
// ==============================================================
//
// Jab bhi problem mein ye ho:
// ✅ Prefix existence check
// ✅ Longest/shortest prefix
// ✅ Count words with given prefix
// ✅ Autocomplete / word suggestion
// ✅ String search in dictionary
// ✅ XOR related problems (Binary Trie)
//
// ONE LINE RULE:
// → String problem + PREFIX ki baat → TRIE sochna sabse pehle
//
// ==============================================================
// TRIE NODE STRUCTURE
// ==============================================================

// struct TrieNode {
//     TrieNode* children[26]; // 26 pointers for a-z
//     bool isEnd;             // true = ek word yahan khatam hota hai
//     TrieNode() {
//         fill(children, children + 26, nullptr);
//         isEnd = false;
//     }
// };

// ==============================================================
// INSERT OPERATION
// ==============================================================
// - Root se shuru karo
// - Har character ke liye:
//   - Agar node exist nahi karta → naya banao
//   - Move karo us node pe
// - Last character ke baad isEnd = true

// void insert(TrieNode* root, const string& word) {
//     TrieNode* node = root;
//     for (char c : word) {
//         int i = c - 'a';
//         if (!node->children[i])
//             node->children[i] = new TrieNode();
//         node = node->children[i];
//     }
//     node->isEnd = true;
// }

// ==============================================================
// SEARCH OPERATION (exact word)
// ==============================================================
// - Root se shuru karo
// - Har character traverse karo
// - Agar koi node missing → false
// - Last node pe isEnd check karo

// bool search(TrieNode* root, const string& word) {
//     TrieNode* node = root;
//     for (char c : word) {
//         int i = c - 'a';
//         if (!node->children[i]) return false;
//         node = node->children[i];
//     }
//     return node->isEnd; // word exist karta hai tabhi true
// }

// ==============================================================
// PREFIX SEARCH (startsWith)
// ==============================================================
// - Search jaisa hi but isEnd check nahi karte end mein
// - Sirf itna chahiye ki path exist kare

// bool startsWith(TrieNode* root, const string& prefix) {
//     TrieNode* node = root;
//     for (char c : prefix) {
//         int i = c - 'a';
//         if (!node->children[i]) return false;
//         node = node->children[i];
//     }
//     return true; // path exist karta hai → prefix exist karta hai
// }