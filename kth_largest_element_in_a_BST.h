//二叉搜索树的第k大节点


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void kthLargestCore(TreeNode* root, int k)
    {
        if (root == nullptr || k <= reverseInorder.size()) return;

        kthLargestCore(root->right, k);
        reverseInorder.push_back(root->val);
        kthLargestCore(root->left, k);   
    }

    int kthLargest(TreeNode* root, int k) {
        kthLargestCore(root, k);
        return reverseInorder[k - 1];
    }
private:
    vector<int> reverseInorder;
};