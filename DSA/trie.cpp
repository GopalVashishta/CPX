#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Node structure for Trie
struct TrieNode {
    bool isEndOfWord;  // Indicates if this node marks the end of a word
    unordered_map<char, TrieNode*> children;

    TrieNode() : isEndOfWord(false) {}
};

// Trie data structure
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear(root);
    }

    // Insert a word into the Trie
    void insert(const string &word) {
        TrieNode *node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    // Search for a complete word in the Trie
    bool search(const string &word) const {
        TrieNode *node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end())
                return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    // Check if there is any word in the Trie that starts with the given prefix
    bool startsWith(const string &prefix) const {
        TrieNode *node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end())
                return false;
            node = node->children[ch];
        }
        return true;
    }

    // Remove a word from the Trie
    bool remove(const string &word) {
        return removeHelper(root, word, 0);
    }

private:
    TrieNode *root;

    // Helper to clear all nodes
    void clear(TrieNode *node) {
        for (auto &pair : node->children) {
            clear(pair.second);
        }
        delete node;
    }

    // Recursive helper for remove
    bool removeHelper(TrieNode *node, const string &word, size_t depth) {
        if (!node)
            return false;

        // If last character of word is reached
        if (depth == word.size()) {
            // This word is not present
            if (!node->isEndOfWord)
                return false;

            // Unmark this node as end of word
            node->isEndOfWord = false;

            // If node has no children, it can be deleted
            return node->children.empty();
        }

        char ch = word[depth];
        auto it = node->children.find(ch);
        if (it == node->children.end())
            return false;

        bool shouldDeleteChild = removeHelper(it->second, word, depth + 1);

        // If true, delete the mapping
        if (shouldDeleteChild) {
            delete it->second;
            node->children.erase(it);
            // Return true if no children and not end of another word
            return node->children.empty() && !node->isEndOfWord;
        }
        return false;
    }
};

// Example usage
int main() {
    Trie trie;
    trie.insert("apple");
    cout << boolalpha;
    cout << "Search apple: " << trie.search("apple") << "\n";   // true
    cout << "Search app: "   << trie.search("app") << "\n";     // false
    cout << "StartsWith app: " << trie.startsWith("app") << "\n"; // true
    trie.insert("app");
    cout << "Search app after insert: " << trie.search("app") << "\n"; // true

    trie.remove("apple");
    cout << "Search apple after removal: " << trie.search("apple") << "\n"; // false
    cout << "Search app remains: " << trie.search("app") << "\n";    // true

    return 0;
}
