//只出现一次的数字
//异或

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
        {
            nums[0] = nums[i] ^ nums[0];
        }
        return nums[0];
    }
};