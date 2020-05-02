#include "common.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL) continue;
            //交换左右子树
            swap(node->left, node->right);
            q.push(node->left);
            q.push(node->right);
        }

        return root;
    }
};