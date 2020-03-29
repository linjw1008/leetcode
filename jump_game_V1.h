class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        int len = nums.size();
        
        for (int i = 0; i < len; i++)
        {
            if (i > k) return false;
            k = max(k, nums[i] + i);
        }
        
        return true;
    }
};