//一遍哈希表

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hmap;
                
        for(int i = 0; i < nums.size(); i++)
        {
            hmap.insert(map<int,int>::value_type(nums[i], i));
            if (hmap.count(target - nums[i]) > 0 && hmap[target - nums[i]] != i)
            {
                return {i, hmap[target - nums[i]]};
            }
            
        }
        
        return {0, 0};
    }
};