#include "common.h"

class WordDictionary {
public:
    vector<WordDictionary*> children;
    bool isWord;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        isWord = false;
        children.resize(26, NULL);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *node = this;
        for (int i = 0; i < word.size(); ++i)
        {
            if (node->children[word[i] - 'a'] == NULL)
            {
                node->children[word[i] - 'a'] = new WordDictionary;
            }
            node = node->children[word[i] - 'a'];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchCore(word, 0, this);
    }
    
    bool searchCore(string& word, int index, WordDictionary *node)
    {
        if (word.size() == index && node->isWord) return true;
        if (word.size() == index && !(node->isWord)) return false;

        if (word[index] == '.')
        {
            for (int i = 0; i < 26; ++i)
            {
                if (node->children[i] != NULL && searchCore(word, index + 1, node->children[i]))
                {
                    return true;
                }
            }
        }
        else
        {
            if (node->children[word[index] - 'a'] == NULL) return false;
            return searchCore(word, index + 1, node->children[word[index] - 'a']);
        }
        return false; 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */