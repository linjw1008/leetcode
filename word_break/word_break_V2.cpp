//单词拆分
//递归、剪枝
//记录下已经查找过的后缀，减小时间复杂度

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> memo;

        return wordBreak(s, wordDict, 0, memo);
    }

    bool wordBreak(string s, vector<string>& wordDict, int start, unordered_map<int, bool> &memo)
    {
        if(start == s.size()) return true;

        if(memo.count(start) > 0) return memo[start];

        for(int end = start; end < s.size(); end++)
        {
            if(find(wordDict.begin(), wordDict.end(), s.substr(start, end - start + 1)) != wordDict.end() && wordBreak(s, wordDict, end + 1, memo))
            {
                memo[start] = true;
                return true;
            }
        }

        memo[start] = false;
        return false;
    }
};