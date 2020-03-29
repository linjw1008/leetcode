#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        int len = nums.size();
        vector<int> sum(len + 1, 0);

        //累加数组sum
        for (int i = 1; i <= len; i++)
        {
            sum[i] = nums[i - 1] + sum[i - 1];
        }
        
        for (int start = 0; start < len; start++)
        {
            for (int end = start + 1; end <= len; end++)
            {
                if (sum[end] - sum[start] == k)
                {
                    ret++;
                }
            }
        }

        return ret;
    }
};