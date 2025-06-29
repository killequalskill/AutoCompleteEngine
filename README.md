# Autocomplete Engine (C++)

A fast and efficient autocomplete engine built using **Trie** and **frequency-based ranking** in C++.  
Type a prefix and get top suggestions instantly — just like Google or your keyboard!

---

## Features
- Prefix search with top 5 suggestions
- Frequency-based ranking
- Built using Trie (Prefix Tree)
- Time complexity: O(L), where L = length of prefix

---

## How to Run

### 1. Compile
```bash
g++ -std=c++17 src/*.cpp -o autocomplete
```

### 2. Compile
```bash
./autocomplete
```
---

### Input Format
The wordlist file should be located at data/wordlist.txt and contain lines in this format: word frequency

## Sample Input(data/wordlist.txt)
hello 30
help 25
hell 20
helium 15
heap 12
hi 20
hop 40

---

## Sample Output
Enter prefix: he
Suggestions:
1. hello (30)
2. help (25)
3. hell (20)
4. helium (15)
5. heap (12)

---

Word frequency data used:
hermitdave/FrequencyWords (used en_50k.txt)

# Author
Rujul Krishna
CSE @ BITS Pilani Hyderabad Campus

---

## Future Enhancements

- Add support for case-insensitive queries
- Code should not be limited only to prefix search
- Add ability to insert new words at runtime  
- Store logs of user queries and suggestions  
- Implement fuzzy matching for typos  
- Create a web or GUI interface using React or SFML  

