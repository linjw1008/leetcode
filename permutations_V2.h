//全排列

#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        permute(nums, ret, 0);
        return ret;
    }
    
    void permute(vector<int>& nums, vector<vector<int>>& ret, int index) {
        if (index == nums.size())
        {
            ret.push_back(nums);
            return;
        }
        
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            permute(nums, ret, index + 1);
            swap(nums[i], nums[index]);
        }
        
        return;
    }
};