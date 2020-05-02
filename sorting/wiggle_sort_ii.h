#include "common.h"

class Solution {
public:
    void quickSort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return;
        int low = left + 1;
        int high = right;
        int pivot = left;
        while (low <= high)
        {
            if (nums[low] > nums[pivot])
            {
                swap(nums[low], nums[high]);
                high--;
            }
            else
                low++;
        }
        low--;
        swap(nums[pivot], nums[low]);

        quickSort(nums, left, low - 1);
        quickSort(nums, low + 1, right);
    }

    void wiggleSort(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        vector<int> tmp = nums;

        int left = (nums.size() + 1) / 2 - 1, right = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i)
            nums[i] = i % 2 == 0 ? tmp[left--] : tmp[right--];
    }
};