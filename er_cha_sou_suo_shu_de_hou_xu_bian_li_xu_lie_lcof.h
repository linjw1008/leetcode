#include "common.h"

class Solution {
public:
    bool verifyPostorderCore(vector<int>& postorder, int left, int right)
    {
        if (left >= right) return true;

        //根节点
        int root = postorder[right];

        //找出右子树的第一个下标
        int rightBegin = left;
        while (rightBegin < right && postorder[rightBegin] < root) rightBegin++;

        //判断右子树序列是否满足要求
        for (int i = rightBegin; i < right; ++i)
        {
            if (postorder[i] < root)
                return false;
        }

        return verifyPostorderCore(postorder, left, rightBegin - 1) && verifyPostorderCore(postorder, rightBegin, right - 1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorderCore(postorder, 0, postorder.size() - 1);
    }
};