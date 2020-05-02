#include "common.h"

//有序矩阵中第K小的元素
//方法一
//小顶堆

class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> queue;
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
                queue.push(matrix[i][j]);
        }
        
        for (int i = 1; i < k; ++i)
            queue.pop();
        
        return queue.top();
    }
};