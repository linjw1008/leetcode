//全排列

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return permute(nums, nums.size() - 1);
    }
    
    vector<vector<int>> permute(vector<int>& nums, int index) {
        vector<vector<int>> ret;
        
        if (index == 0)
        {
            ret.push_back({nums[index]});
            return ret;
        }
        
        vector<vector<int>> pre = permute(nums, index - 1);
        
        for (int i = 0; i < pre.size(); i++)
        {
            vector<int> tmp;
            for (int j = 0; j <= pre[i].size(); j++)
            {
                tmp = pre[i];
                tmp.insert(tmp.begin() + j, nums[index]);
                ret.push_back(tmp);
            }
        }
        
        return ret;
    }
};