#include "common.h"

class Solution {
public:
    static bool cmp(int a, int b)
    {   
        string A = to_string(a);
        string B = to_string(b);
        
        return A + B > B + A;
    }
    
    string largestNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(), nums.end(), cmp);
        
        //跳过开头的0
        int i = 0;
        while (i < nums.size() && nums[i] == 0)
            ++i;
        
        for (; i < nums.size(); ++i)
            ans = ans + to_string(nums[i]);
        
        //为0的特殊情况
        if (ans == "")
            ans = "0";
        
        return ans;
    }
};