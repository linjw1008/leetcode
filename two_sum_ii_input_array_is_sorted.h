#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //双指针法
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            if (numbers[left] + numbers[right] > target) right--;
            else if (numbers[left] + numbers[right] < target) left++;
            else break;
        }
        return {left + 1, right + 1};
    }
};