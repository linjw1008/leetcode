//单词拆分
//暴力法、递归
//超出时间限制

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreak(s, wordDict, 0);
    }

    bool wordBreak(string s, vector<string>& wordDict, int start)
    {
        if(start == s.size()) return true;

        for(int end = start; end < s.size(); end++)
        {
            if(find(wordDict.begin(), wordDict.end(), s.substr(start, end - start + 1)) != wordDict.end() && wordBreak(s, wordDict, end + 1))
            {
                return true;
            }
        }

        return false;
    }
};