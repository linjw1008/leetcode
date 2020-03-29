//只出现一次的数字
//利用异或实现


#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            ans ^= nums[i];
        }
        
        return ans;
    }
};