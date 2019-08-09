//单词拆分
//动态规划

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       bool* dp = new bool[s.size()+1] {false};

       dp[0] = true;

       for(int i = 1; i <= s.size(); i++)
       {
           for(int j = 0; j < i; j++)
           {
               if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
               {
                   dp[i] = true;
                   break;
               }
           }
       }
       return dp[s.size()];
    }
};