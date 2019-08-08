//只出现一次的数字
//排序+双指针

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        
        sort(nums.begin(), nums.end());

        for(int i = 0, j = 1; j < len; i += 2, j += 2)
        {
            if(nums[i] != nums[j]) return nums[i];
        }
        return nums[len - 1];
    }
};