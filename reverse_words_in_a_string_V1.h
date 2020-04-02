#include "common.h"

class Solution {
public:
    string reverseWords(string s) {
        //非原地算法
        vector<string> words;
        string ans;
        int i = 0;
        while (i < s.size())
        {
            if (s[i] != ' ')
            {
                string word;
                while (i < s.size() && s[i] != ' ')
                    word += s[i++];
                words.push_back(word);
            }
            else 
                i++;
        }
        if (words.size() != 0)
            ans = ans + words[words.size() - 1];
        for (int j = words.size() - 2; j >= 0; --j)
            ans = ans + " " + words[j];
        
        return ans;
    }
};