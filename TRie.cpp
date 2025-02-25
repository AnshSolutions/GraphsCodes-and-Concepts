#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndw;
    int c;

    TrieNode() {
        isEndw = false;
        c = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* pcrawl = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (pcrawl->children[idx] == nullptr) {
                pcrawl->children[idx] = new TrieNode();
            }
            pcrawl = pcrawl->children[idx];
            pcrawl->c++;
        }
        pcrawl->isEndw = true;
    }

    int search(string pre) {
        TrieNode* pCrawl = root;
        for (char ch : pre) {
            int idx = ch - 'a';
            if (pCrawl->children[idx] == nullptr) {
                return 0;
            }
            pCrawl = pCrawl->children[idx];
        }
        return pCrawl->c;
    }
    bool searchPrefix(string prefix) {
        trieNode* pCrawl = root;
        for (int i = 0; i < prefix.length(); i++) {
            int idx = prefix[i] - 'a';
            if (pCrawl->children[idx] == NULL) {
                return false;
            }
            pCrawl = pCrawl->children[idx];
        }

        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        Trie tr;
        int m, q;
        cin >> m;  // Number of words

        for (int i = 0; i < m; i++) {
            string word;
            cin >> word;
            tr.insert(word);
        }

        cin >> q;  // Number of prefix queries
        while (q--) {
            string prefix;
            cin >> prefix;
            cout << tr.search(prefix) << "\n";  // Print count of words with given prefix
        }
    }

    return 0;
}
