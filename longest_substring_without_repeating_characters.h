#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
        unordered_map<char, int> isVisited;
        int ans = 0;
        int curBegin = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (isVisited.find(s[i]) != isVisited.end() && isVisited[s[i]] >= curBegin)
                curBegin = isVisited[s[i]] + 1;
            isVisited[s[i]] = i;
            ans = max(ans, i - curBegin + 1);
        }
        
        return ans;
    }

};