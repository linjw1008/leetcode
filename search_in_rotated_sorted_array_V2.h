//搜索旋转排序数组
//只在有序序列进行查找

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
        {
            return -1;
        }

        int left = 0;
        int right = len - 1;
        int mid = 0;
        
        while (left <= right)
        {
            mid = (left + right) / 2;
            
            if (nums[mid] == target)
            {
                return mid;
            }

            
            //只在有序序列中查找
            if (nums[left] <= nums[mid])//[left, mid]有序
            {
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else 
                {
                    left = mid + 1;
                }
            }
            else // [mid + 1, right]有序
            {
                if (nums[mid] < target && target <= nums[right])
                {
                    left  = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};