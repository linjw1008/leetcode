#include "common.h"

//分治法

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }
    
    string longestCommonPrefix(vector<string> &strs, int left, int right) {
        if (right - left <= 1) return getCommonPrefix(strs[left], strs[right]);
        int mid = (left + right) / 2;
        string leftS = longestCommonPrefix(strs, left, mid);
        string rightS = longestCommonPrefix(strs, mid + 1, right);
        return getCommonPrefix(leftS, rightS);
    }
    
    string getCommonPrefix(string &left, string &right)
    {
        int len = min(left.size(), right.size());
        string ans;
        for (int i = 0; i < len; ++i)
        {
            if (left[i] != right[i])
                break;
            ans.push_back(left[i]);
        }
        
        return ans;
    }
    
};