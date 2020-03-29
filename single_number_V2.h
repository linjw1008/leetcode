//只出现一次的数字
//利用哈希集实现

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> set;
        unordered_set<int>::iterator it;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if ((it = set.find(nums[i])) == set.end()) set.insert(nums[i]);
            else set.erase(it);
        }
        
        return *(set.begin());
        
        return ans;
    }
};