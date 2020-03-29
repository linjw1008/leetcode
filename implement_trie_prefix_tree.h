//实现前缀树

#include <vector>
#include <string>

using namespace std;

class Trie {
public:
    vector<Trie *> children;
    bool isWord;
    /** Initialize your data structure here. */
    Trie() {
        children.resize(26, NULL);
        isWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (auto &w : word)
        {
            if (node->children[w - 'a'] == NULL)
            {
                node->children[w - 'a'] = new Trie();
            }
            node = node->children[w - 'a'];
        }
        
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (auto &w : word)
        {
            if (node->children[w - 'a'] == NULL) return false;
            node = node->children[w - 'a'];
        }
        
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (auto &w : prefix)
        {
            if (node->children[w - 'a'] == NULL) return false;
            node = node->children[w - 'a'];
        }
        
        return true;    
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */