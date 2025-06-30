#include "trie.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype> 
using namespace std;

int main() {
    Trie trie;
    ifstream file("data/en_50k.txt"); // input file stream
    string line, word;
    int freq;

    while (getline(file, line)) { // insert all words and their frequencies from the txt file -> into the trie
        stringstream ss(line);
        ss >> word >> freq;
        trie.insert(word, freq);
    }

    string prefix;
    while (true) {
        cout << "Enter prefix (or type 'exit' to exit): ";
        cin >> prefix;
        transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower); 
        // tolower is a unary function to apply to each element
        if (prefix == "exit") break; // type exit to exit

        auto suggestions = trie.getSuggestions(prefix, 5); 
        // getsuggestions is the star function of this project
        // let the compiler automatically figure out the data type of suggestions
        // 5 is the maximum number of suggestions you want
        if (suggestions.empty()) {
            cout << "No suggestions found.\n";
        } else {
            cout << "Suggestions:\n";
            // pair represents each element inside suggestions, which is a pair<string, int>
            for (auto& pair : suggestions) {
                cout << pair.first << " (" << pair.second << ")\n";
            }
            
        }
    }

    return 0;
}

/*
Problems to fix ->
1. Trie doesnt support spaces currently(Only words, Not phrases) -> ex. Lazy Man 100 (Not supported)
2. Only a prefix based auto complete engine
3. Case sensitive -> ex. HERO (Upper-case not supported)
*/

/*
References ->
1. Words Repo -> https://github.com/hermitdave/FrequencyWords -> downloaded "en_50k.txt"
*/

/*
Comments ->
1. O(L) time complexity, L = length of prefix
*/