#include "common.h"

//暴力法

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if (strs.size() == 0) return "";
        string ans;
        int minIndex = 0;
        for (int i = 0; i < strs.size(); ++i)
        {
            if (strs[minIndex].size() > strs[i].size())
                minIndex = i;
        }
        for (int i = 0; i < strs[minIndex].size(); ++i)
        {
            for (int j = 0; j < strs.size(); ++j)
                if (strs[j][i] != strs[minIndex][i]) return ans;
            ans.push_back(strs[minIndex][i]);
        }
        
        return ans;
    }
};