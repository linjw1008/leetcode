//存在重复元素

#include <unordered_set>
#include <vector>


using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        
        int i = 0;
        int len = nums.size();
        for (i = 0; i < len; i++)
        {
            if (set.find(nums[i]) == set.end())
            {
                set.insert(nums[i]);
            }
            else
            {
                break;
            }
        }
        
        return !(i == len);
    }
};