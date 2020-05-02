#include "common.h"

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp = 0;
        int num1 = 0, num2 = 0;
        for (int i = 0; i < nums.size(); ++i)
            tmp ^= nums[i];
        
        //tmp肯定至少有一位为1，找出其中一位
        int num = 1;
        while ((tmp & num) == 0)
            num = num << 1;

        //分组
        //a和b肯定不会在num所代表的那一位同时为1，故可利用这一个特性，将nums分为两个数组，a和b分别在两个数组，对每个数组分别累积异或
        for (int i = 0; i < nums.size(); ++i)
        {
            if ((nums[i] & num) != 0)
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }

        return {num1, num2};
    }
};