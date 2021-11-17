
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

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
        Trie* node = this;
        for (char c : word) {
            if (!node->next.count(c)) {
                return false;
            }
            node = node->next[c];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (!node->next.count(c)) {
                return false;
            }
            node = node->next[c];
        }
        return true;
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
    ret = trie->search("app");     // return False
    if (ret != false) passed = false;
    ret = trie->startsWith("app"); // return True
    if (ret != true) passed = false;
    trie->insert("app");
    ret = trie->search("app");     // return True
    if (ret != true) passed = false;

    if (passed) cout << "passed\n";
    else cout << "failed\n";

    return 0;
}