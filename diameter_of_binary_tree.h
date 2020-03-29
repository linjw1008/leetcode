//二叉树的直径

#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int ret = 0;
    int depthOfBinaryTree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int lDepth = depthOfBinaryTree(root->left);
        int rDepth = depthOfBinaryTree(root->right);
        
        ret = max(ret, lDepth + rDepth);
        
        return max(lDepth, rDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depthOfBinaryTree(root);
        return ret;
    }
};