//二叉树的中序遍历
//递归法

#include <vector>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &path)
    {
        if (root != NULL)
        {
            inorder(root->left, path);
            path.push_back(root->val);
            inorder(root->right, path);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }

        inorder(root, res);

        return res;
    }
};