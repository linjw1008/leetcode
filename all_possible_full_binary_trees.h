#include "common.h"

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) 
    {
        vector<TreeNode*> ans;

        if (N == 1)
        {
            TreeNode* node = new TreeNode(0);
            ans.push_back(node);
        }
        else if (N % 2 == 1) //奇数
        {
            for (int i = 1; i < N - 1; i = i + 2)
            {
                vector<TreeNode*> left = allPossibleFBT(i);
                vector<TreeNode*> right = allPossibleFBT(N - 1 - i);
                for (int i = 0; i < left.size(); ++i)
                {
                    for (int j = 0; j < right.size(); ++j)
                    {
                        TreeNode* node = new TreeNode(0);
                        node->left = left[i];
                        node->right = right[j];
                        ans.push_back(node);        
                    }
                }
            }
        }

        return ans;
    }
};