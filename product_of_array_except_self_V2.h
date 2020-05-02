//自身以外数组的乘积

#include <vector>

using namespace std;


//方法二
//原地算法
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //原地算法
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        for (int i = 1; i < ans.size(); ++i)
            ans[i] = ans[i - 1] * nums[i];
        int rightProduct = 1;

        for (int i = ans.size() - 1; i >= 1; --i)
        {
            ans[i] = rightProduct * ans[i - 1];
            rightProduct = rightProduct * nums[i];
        }
        ans[0] = rightProduct;

        return ans;
    }
};