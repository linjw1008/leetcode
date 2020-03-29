//二叉搜索树中第K小的元素
public:
    void kthSmallestCore(TreeNode* root, int k)
    {
        if (root == nullptr || k <= inorder.size())
        {
            return;
        }
        
        kthSmallestCore(root->left, k);
        inorder.push_back(root->val);
        kthSmallestCore(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        kthSmallestCore(root, k);
        return inorder[k - 1];
    }
    
private:
    vector<int> inorder;
};