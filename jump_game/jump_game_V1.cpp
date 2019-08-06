//贪心算法

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int len = nums.size();

        if(!len) return false;

        int farthest = 0;

        for(int i = 0; i < len; i++)
        {
            if (i > farthest) return false;
            farthest = max(farthest, i + nums[i]);
        }

        return true;

    }
};