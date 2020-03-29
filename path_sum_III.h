//路径总和 III

#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
        {
            return 0;
        }
        
        return findPath(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int findPath(TreeNode* root, int sum)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return ((root->val == sum) ? 1 : 0) + findPath(root->left, sum - root->val) + findPath(root->right, sum - root->val);
    }
};