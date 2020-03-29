//子集

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsets(nums, nums.size() - 1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums, int index)
    {
        vector<vector<int>> ret;
        if (index == 0)
        {
            ret.push_back({});
            ret.push_back({nums[0]});
            return ret;
        }
        
        vector<vector<int>> nextSubsets = subsets(nums, index - 1);
        
        for (int i = 0; i < nextSubsets.size(); i++)
        {
            ret.push_back(nextSubsets[i]);
            nextSubsets[i].push_back(nums[index]);
            ret.push_back(nextSubsets[i]);
        }
        
        return ret;
    }  
};