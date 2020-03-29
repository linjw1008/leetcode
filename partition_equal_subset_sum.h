#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
        {
            return false;
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
        {
            return false;
        }

        int len = nums.size();
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int i = 0; i < len; i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};