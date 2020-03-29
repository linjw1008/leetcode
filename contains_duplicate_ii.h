//存在重复元素 II

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            //本位置之前有相同值的元素
            if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k) return true;
            else map[nums[i]] = i;
        }
        
        return false;
    }
};