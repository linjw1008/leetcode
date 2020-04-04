#include "common.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;

        int mid = left + (right - left >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        int ptr1 = left, ptr2 = mid + 1;
        int curPtr = 0;
        vector<int> tmp(right - left + 1);
        while (ptr1 <= mid && ptr2 <= right)
        {
            if (nums[ptr1] < nums[ptr2])
                tmp[curPtr++] = nums[ptr1++];
            else
                tmp[curPtr++] = nums[ptr2++];
        }

        while (ptr1 <= mid) tmp[curPtr++] = nums[ptr1++];
        while (ptr2 <= right) tmp[curPtr++] = nums[ptr2++];

        for (int i = 0; i < tmp.size(); ++i)
            nums[left + i] = tmp[i];
    }

    //不稳定
    //取最左侧元素作为分界点
    void quickSort1(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        //取left作为分界点
        int low = left + 1;
        int high = right;
        while (low <= high)
        {
            if (nums[low] > nums[left])
            {
                swap(nums[low], nums[high]);
                high--;
            }
            else low++;
        } 
        //退回到小于分界点数组的最右侧
        low--;
        swap(nums[left], nums[low]);
        quickSort1(nums, left, low - 1);
        quickSort1(nums, low + 1, right);
    }


    void insertSort(vector<int>& nums)
    {
        //最外层代表即将要插入的元素
        for (int i = 1; i < nums.size(); ++i)
        {
            int insertVal = nums[i];
            //内层负责找到外层元素需要插入的位置，并插入
            int j;
            for (j = i - 1; j >= 0; --j)
            {
                if (insertVal > nums[j]) break;
                else nums[j + 1] = nums[j]; 
            }
            nums[j + 1] = insertVal;
        }
    }
    
    //不稳定
    void selectSort(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            int selectedIndex = i;
            //找出最小值
            for (int j = i; j < nums.size(); ++j)
                selectedIndex = nums[selectedIndex] < nums[j] ? selectedIndex : j;
            swap(nums[selectedIndex], nums[i]);
        }
    }

    void bubbleSort(vector<int>& nums)
    {
        bool flag = false;
        while (!flag)
        {
            flag = true;
            for (int i = 1; i < nums.size(); ++i)
            {
                if (nums[i] < nums[i - 1])
                {
                    swap(nums[i], nums[i - 1]);
                    flag = false;
                }
            }
        }
    }
};