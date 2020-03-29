//跳跃游戏
//回溯法，递归

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums, int index, vector<int>& mem) {
        if (mem[index] != -1)
        {
            return mem[index] == 1;
        }
        
        int len = nums.size();

        if (nums[index] >= len - index - 1)
        {
            return true;
        }

        int end = min(index + nums[index], len - 1);
        for (int i = index + 1; i <= end; i++)
        {
            if (mem[i] != -1)
            {
                if (mem[i] == 1)
                {
                    return true;
                }
            }
            else if (canJump(nums, i, mem))
            {
//                mem[i] = 1;
                return true;
            }
        }

        mem[index] = 0;
        return false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> mem(nums.size(), -1);
        return canJump(nums, 0, mem);
    }
};