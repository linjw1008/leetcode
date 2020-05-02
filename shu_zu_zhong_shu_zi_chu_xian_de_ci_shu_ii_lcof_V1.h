#include "common.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        int ans;
        for (int i = 0; i < nums.size(); ++i) map[nums[i]]++;
        for (auto &m : map)
        {
            if (m.second == 1)
            {
                ans = m.first;
                break;
            }
        }

        return ans;
    }
};