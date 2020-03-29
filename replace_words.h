//单词替换
#include "common.h"

class Trie
{
public:
    vector<Trie *> children;
    bool isRoot = false;
    
    Trie()
    {
        children.resize(26, NULL);    
    }
    
    void insertRoot(string root)
    {
        Trie *node = this;
        for (int i = 0; i < root.size(); ++i)
        {
            if (node->children[root[i] - 'a'] == NULL)
            {
                node->children[root[i] - 'a'] = new Trie();
            }
            node = node->children[root[i] - 'a'];
        }
        node->isRoot = true;
    }
    
    string getRoot(string word)
    {
        Trie *node = this;
        string ans;
        for (int i = 0; i < word.size(); ++i)
        {            
            if (node->children[word[i] - 'a'] == NULL) return "";
            
            node = node->children[word[i] - 'a'];
            ans += word[i];
            if (node->isRoot) return ans;
        }
        
        return ans;
    }
};

class Solution {
private:
    
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie trie;
        for (auto d : dict)
        {
            trie.insertRoot(d);
        }
        
        string ans;
        string word;
        for (int i = 0; i < sentence.size(); ++i)
        {
            if (sentence[i] == ' ')
            {
                string add = trie.getRoot(word);
                ans = ans + (add == "" ? word : add) + ' ';
                word = "";
                continue;
            }
            word += sentence[i];
        }
        //处理最后一个词
        string add = trie.getRoot(word);
        ans = ans + (add == "" ? word : add);        
        
        return ans;
    }
};