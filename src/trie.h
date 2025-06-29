// header file -> contains declarations (like function prototypes, class definitions)
// Header files are included in .cpp or .c files using #include "file.h"

#ifndef TRIE_H // If TRIE_H is not defined yet
#define TRIE_H // Define it now

#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
    bool isWord; // is it a word?
    int frequency; // frequency of the word having been typed
    unordered_map<char, TrieNode*> children;

    TrieNode() : isWord(false), frequency(0) {}
    // every node that's a prefix and not a word has 0 frequency
    // frequency is stored only at nodes that mark the end of real words, and it tells you how many times that word appeared or was added
};

class Trie {
private:
    TrieNode* root; // pointer to the root

    void dfs(TrieNode* node, string prefix, vector<pair<string, int>>& results); // depth first search of the tree to collect word suggestions

public:
    Trie();
    void insert(const string& word, int freq); 
    // Adds a word with a given frequency into the trie
    vector<pair<string, int>> getSuggestions(const string& prefix, int topN);
    //  Returns up to topN suggestions that start with the given prefix, sorted by frequency.
};

#endif // End of header file

// When program includes a header file more than once, the compiler can get confused and throw "already defined" errors