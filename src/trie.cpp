#include "trie.h"
#include <queue>
#include <algorithm>
using namespace std;

// Trie:: is needed to define the functions outside the class

Trie::Trie()
{ // Constructor(sets root to a new node)
    root = new TrieNode();
}

void Trie::insert(const string &word, int freq)
{
    TrieNode *node = root; // Start from the root of the trie
    for (char ch : word)
    {                            // Go through each character in the input word
        if (!node->children[ch]) // If the current character's node does not exist, create a new one
            node->children[ch] = new TrieNode();
        node = node->children[ch]; // Move to the next node (for the current character)
    }
    node->isWord = true;
    node->frequency = freq;
    // Mark the final node as the end of a full word, and its freq for ranked suggestions
}

void Trie::dfs(TrieNode *node, string prefix, vector<pair<string, int>> &results)
{
    if (node->isWord) // If this node marks the end of a valid word, add the word (prefix) and its frequency to the results list
    {
        results.push_back({prefix, node->frequency});
    }
    for (auto &entry : node->children) // For each child node (letter and pointer pair) of the current node, recursively continue DFS with the updated prefix (add the current letter)
    {
        dfs(entry.second, prefix + entry.first, results);
    }
}

vector<pair<string, int>> Trie::getSuggestions(const string &prefix, int topN)
{
    TrieNode *node = root; // Start from the root of the trie
    for (char ch : prefix) // Go through each character in the input prefix
    {
        if (!node->children[ch]) // If any letter in the prefix doesn’t exist, return an empty list (no suggestions)
            return {};
        node = node->children[ch]; // Move to the next node for the current letter
    }

    vector<pair<string, int>> results; // Create a list to store suggestions and their frequencies
    dfs(node, prefix, results); // Run DFS from the last node of the prefix to collect all matching words

    // Sort by frequency (descending)
    sort(results.begin(), results.end(), [](auto &a, auto &b)
    { return a.second > b.second; });
    // Sort the results by frequency, highest first (using a lambda function)

    if (results.size() > topN)
        results.resize(topN); // Keep only the top N suggestions if there are more

    return results; // Return the final sorted list of word suggestions
}
