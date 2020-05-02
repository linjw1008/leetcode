//自身以外数组的乘积

#include <vector>

using namespace std;

//方法一
//定义两个数组，一个数组记录左边所有数的乘积，另一个数组记录右边所有数的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> L(nums.size(), 0);
        vector<int> R(nums.size(), 0);
        vector<int> ret;
        L[0] = nums[0];
        R[nums.size() - 1] = nums[nums.size() - 1]; 
        
        
        for (int i = 1; i < nums.size(); ++i)
        {
            L[i] = L[i - 1] * nums[i];
        }
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            R[i] = R[i + 1] * nums[i];
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == 0) ret.push_back(R[i + 1]);
            else if (i == nums.size() - 1) ret.push_back(L[i - 1]);
            else ret.push_back(L[i - 1] * R[i + 1]);
        }
        
        return ret;
    }
};
