#include "common.h"

class Trie
{
private:
    vector<Trie *> children;
    bool isWord;
    int index;
public:
    Trie()
    {
        children.resize(26, NULL);
        isWord = false;
    }
    
    void insert(string &word, int index)
    {
        Trie* node = this;
        for (int i = 0; i < word.size(); ++i)
        {
            if (node->children[word[i] - 'a'] == NULL)
                node->children[word[i] - 'a'] = new Trie;
            node = node->children[word[i] - 'a'];
        }
        node->isWord = true;
        node->index = index;
    }
    
    vector<int> getIndex(string &word)
    {
        vector<int> ans;
        int i = 0;
        Trie *node = this;
        for (i = 0; i < word.size(); ++i)
        {
            if (node->children[word[i] - 'a'] == NULL) break;
            node = node->children[word[i] - 'a'];
            if (node->isWord) ans.push_back(node->index);
        }
        
        if (i >= word.size() && node != NULL)
            for (int i = 0; i < 26; ++i)
                dfs(node->children[i], ans);

        return ans;
    }
    
    void dfs(Trie* node, vector<int> &indexList)
    {
        if (node == NULL) return;
        if (node->isWord) indexList.push_back(node->index);
        for (int i = 0; i < 26; ++i)
        {
            dfs(node->children[i], indexList);
        }
    }
};

class Solution {
public:
    bool isPalindrome(string &word, int left, int right)
    {
        while (left <= right)
            if (word[left++] != word[right--]) return false;
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;

        Trie wordTree;
        for (int i = 0; i < words.size(); ++i)
            wordTree.insert(words[i], i);
        
        string reverseWord;
        vector<int> indexList;
        for (int i = 0; i < words.size(); ++i)
        {
            //空字符串，特殊处理
            if (words[i] == "")
            {
                for (int j = 0; j < words.size(); ++j)
                {
                    if (i == j) continue;
                    if (isPalindrome(words[j], 0, words[j].size() - 1))
                    {
                        ans.push_back({i, j});
                        ans.push_back({j, i});
                    }
                }
                continue;
            }
            
            //正常处理
            reverseWord = words[i];
            reverse(reverseWord.begin(), reverseWord.end());
            indexList = wordTree.getIndex(reverseWord);
            for (int j = 0; j < indexList.size(); j++)
            {
                //cout << indexList[j] << " " << i << " " << reverseWord << endl;
                int index = indexList[j];
                if (index == i) continue;
                if (reverseWord.size() > words[index].size())
                {
                    //cout << "11" << endl;
                    if (isPalindrome(words[i], 0, reverseWord.size() - words[index].size() - 1))
                        ans.push_back({index, i});
                }
                else if (reverseWord.size() < words[index].size())
                {
                    //cout << "22 " << reverseWord.size() << " " << words[index].size() - 1 << endl;
                    if (isPalindrome(words[index], reverseWord.size(), words[index].size() - 1))
                        ans.push_back({index, i});
                }
                else
                    ans.push_back({index, i});
            }
        }
        
        return ans;
    }
};