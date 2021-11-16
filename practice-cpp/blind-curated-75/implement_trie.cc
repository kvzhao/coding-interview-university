
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode() {}

    TrieNode(char c) : c(c), isEnd(false), shared(0) {};

    ~TrieNode() {
        for (auto child : children)
            delete child;
    }

private:
    char c = ' ';
    bool isEnd = false;
    int shared = 0;
    vector<TrieNode*> children;
};



// https://leetcode.com/problems/implement-trie-prefix-tree/discuss/58868/Implement-Trie-(Prefix-Tree)-C%2B%2B-Clean-Code-(array-or-map)
class Trie {
public:
    Trie() {}
    
    void insert(string word) {
        Trie* node = this;

        for (char c : word) {
            if (!node->next.count(c)) {
                node->next[c] = new Trie();
            }
            node = node->next[c];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        
        return false;
    }
    
    bool startsWith(string prefix) {
        return false;
    }
private:

    unordered_map<char, Trie*> next = {};
    bool isWord = false;
};


int main() {

    bool passed = true, ret;

    Trie* trie = new Trie();
    trie->insert("apple");
    ret = trie->search("apple");   // return True
    if (ret != true) passed = false;
    trie->search("app");     // return False
    if (ret != false) passed = false;
    trie->startsWith("app"); // return True
    if (ret != true) passed = false;
    trie->insert("app");
    trie->search("app");     // return True
    if (ret != true) passed = false;

    if (passed) cout << "passed\n";
    else cout << "failed\n";

    return 0;
}