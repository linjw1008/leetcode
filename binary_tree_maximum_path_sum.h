#include "common.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int ans = INT_MIN;
    
    int max_gain(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        
        //这里要排除负数
        int leftGain = max(0, max_gain(root->left));
        int rightGain = max(0, max_gain(root->right));
        
        //包含当前节点的路径
        int newPath = root->val + leftGain + rightGain;
        
        ans = max(newPath, ans);
        
        //返回以当前节点开头的最大路径
        return max(leftGain, rightGain) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return ans;
    }
};