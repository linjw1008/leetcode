#ifndef _PRODUCT_OF_ARRAY_EXCEPT_SELF_V1_H_
#define _PRODUCT_OF_ARRAY_EXCEPT_SELF_V1_H_

//除自身以外数组的乘积
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int len;
    int right;
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        len = nums.size();
        vector<int> res(len, 1);
        res[0] = 1;
        for (int i = 1; i < len; i++)
            res[i] = nums[i - 1] * res[i - 1];
        right = 1;
        for (int i = len - 2; i >= 0; i--)
        {
            right = right * nums[i + 1];
            res[i] = right * res[i];
        }
        
        return res;
    }
};

#endif