//用哈希表

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        int sum = 0;
        int len = nums.size();
        unordered_map<int, int> map;
        map[0] = 1;

        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
            if (map.count(sum - k) != 0)
            {
                ret = ret + map[sum - k];
            }

            if (map.count(sum) != 0)
            {
                map[sum]++;
            }
            else
            {
                map[sum] = 1;
            }
        }
        
        return ret;
    }
};