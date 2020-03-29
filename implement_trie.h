//实现Trie（前缀树）

#include <string>

using namespace std;

class TrieNode {
private:
    TrieNode** children;
    const int maxLen = 26;
    bool isEnd;

public:
    TrieNode()
    {
        children = new TrieNode*[maxLen];
        for (int i = 0; i < maxLen; i++)
        {
            children[i] = nullptr;
        }
        isEnd = false;
    }

    bool IsContainKey(char ch)
    {
        return children[ch - 'a'] != nullptr;
    }

    TrieNode* GetChild(char ch)
    {
        return children[ch - 'a'];
    }

    void PutChild(char ch, TrieNode* node)
    {
        children[ch - 'a'] = node;
    }

    void SetEnd()
    {
        isEnd = true;
    }

    void ResetEnd()
    {
        isEnd = false;
    }

    bool IsEnd()
    {
        return isEnd;
    }
};

class Trie {
public:
    TrieNode* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* ptr = root;
        for (auto &ch : word)
        {
            if (!ptr->IsContainKey(ch))
            {
                TrieNode* tmp = new TrieNode;
                ptr->PutChild(ch, tmp);
            }
            ptr = ptr->GetChild(ch);
        }
        ptr->SetEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* ptr = root;
        for (auto &ch : word)
        {
            if (!ptr->IsContainKey(ch))
            {
                return false;
            }
            ptr = ptr->GetChild(ch);
        }
        return ptr->IsEnd();        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for (auto &ch : prefix)
        {
            if (!ptr->IsContainKey(ch))
            {
                return false;
            }
            ptr = ptr->GetChild(ch);
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