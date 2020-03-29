//把二叉搜索树转换为累加树

//参考中序遍历，从右到左遍历

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pre = 0;

    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root)
    {
       if (root != nullptr)
       {
           dfs(root->right);
           root->val = pre + root->val;
           pre = root->val;
           dfs(root->left);
       }
    }
};