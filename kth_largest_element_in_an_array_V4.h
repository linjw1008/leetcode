//用小顶堆
//自定义仿函数

#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int left, int right, int k)
    {
        if (k - 1 > right)
            return -1;
        
        //利用快速排序的思想
        int low = left + 1, high = right, pivot = left;
        while (low <= high)
        {
            if (nums[pivot] > nums[low])
            {
                swap(nums[high], nums[low]);
                high--;
            }
            else
                low++;
        }
        low--;
        swap(nums[pivot], nums[low]);
        
        if (low == k - 1)
            return low;
        else if (low < k - 1)
            return findKthLargest(nums, low + 1, right, k);
        else
            return findKthLargest(nums, left, low - 1, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int index = findKthLargest(nums, 0, nums.size() - 1, k);
        return nums[index];
    }
};

