//下一个排列

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        for(int i = len-1; i > 0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                for(int j = len-1; j >= i; j--)
                {
                    if(nums[i-1] < nums[j])
                    {
                        swap(nums[j], nums[i-1]);
                        reverse(nums.begin() + i, nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};