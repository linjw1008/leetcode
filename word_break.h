#include "common.h"

class Solution {
public:
    bool helper(string s, int begin, unordered_set<string>& dict, vector<int>& mem)
    {        
        if (begin == s.size())
            return true;

        if (mem[begin] != -1)
            return mem[begin];
   
        string curString;
        bool ans = false;
        
        for (int i = begin; i < s.size(); ++i)
        {
            curString += s[i];
            if (dict.find(curString) != dict.end())
                ans = helper(s, i + 1, dict, mem);
            if (ans) break;
        }
        
        cout << curString << " " << begin << endl;
        mem[begin] = ans == true ? 1 : 0;
        
        return ans;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<int> mem(s.size(), -1);
        for (int i = 0; i < wordDict.size(); ++i)
            dict.insert(wordDict[i]);
        
        return helper(s, 0, dict, mem);

    }

};