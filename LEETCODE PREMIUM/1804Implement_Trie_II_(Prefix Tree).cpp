// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// int countWordsEqualTo(String word) Returns the number of instances of the string word in the trie.
// int countWordsStartingWith(String prefix) Returns the number of strings in the trie that have the string prefix as a prefix.
// void erase(String word) Erases the string word from the trie.



// Input
// ["Trie", "insert", "insert", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsStartingWith"]
// [[], ["apple"], ["apple"], ["apple"], ["app"], ["apple"], ["apple"], ["app"], ["apple"], ["app"]]
// Output
// [null, null, null, 2, 2, null, 1, 1, null, 0]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");               // Inserts "apple".
// trie.insert("apple");               // Inserts another "apple".
// trie.countWordsEqualTo("apple");    // There are two instances of "apple" so return 2.
// trie.countWordsStartingWith("app"); // "app" is a prefix of "apple" so return 2.
// trie.erase("apple");                // Erases one "apple".
// trie.countWordsEqualTo("apple");    // Now there is only one instance of "apple" so return 1.
// trie.countWordsStartingWith("app"); // return 1
// trie.erase("apple");                // Erases "apple". Now the trie is empty.
// trie.countWordsStartingWith("app"); // return 0



#include <unordered_map>
#include <string>
using namespace std;

class Node {
public:
    char data;
    unordered_map<char, Node*> children;
    int prefixCount;
    int wordCount;

    Node(char data) {
        this->data = data;
        this->prefixCount = 0;
        this->wordCount = 0;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node('\0');
    }

    void insert(string word) {
        Node* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new Node(ch);
            }
            curr = curr->children[ch];
            curr->prefixCount++;
        }
        curr->wordCount++;
    }

    int countWordsEqualTo(string word) {
        Node* curr = root;
        for (char ch : word) {
            if (!curr->children.count(ch)) {
                return 0;
            }
            curr = curr->children[ch];
        }
        return curr->wordCount;
    }

    int countWordsStartingWith(string prefix) {
        Node* curr = root;
        for (char ch : prefix) {
            if (!curr->children.count(ch)) {
                return 0;
            }
            curr = curr->children[ch];
        }
        return curr->prefixCount;
    }

    void erase(string word) {
        if (countWordsEqualTo(word) == 0) return;  // word not present

        Node* curr = root;
        for (char ch : word) {
            Node* next = curr->children[ch];
            next->prefixCount--;
            curr = next;
        }
        curr->wordCount--;
    }
};
