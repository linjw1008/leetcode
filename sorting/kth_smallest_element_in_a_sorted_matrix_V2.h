#include "common.h"

//有序矩阵中第K小的元素
//方法二
//二分查找

class Solution {
public:
    int findNotLargerThanMid(vector<vector<int>>& matrix, int mid)
    {
        int i = 0;
        int j = matrix[0].size() - 1;
        int ans = 0;
        //利用元素已经排序， 按行查找
        while (i < matrix.size() && j >= 0)
        {
            if (matrix[i][j] <= mid)
            {
                ans += j + 1;
                i++;
            }
            else
                j--;
        }
        return ans;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0];
        int right = matrix[matrix.size() - 1][matrix[0].size() - 1];
        //每次查找保证第k小的数在left和right之间
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            //找到小于等于mid的元素的个数
            int count = findNotLargerThanMid(matrix, mid);
            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }
        
        return right;
    }
};