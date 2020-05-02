#include "common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, int> inorderMap;
    int preIndex = 0;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        return buildCore(0, inorder.size() - 1, 0, preorder.size() - 1, preorder, inorder);
    }

    TreeNode* buildCore(int inLeft, int inRight, int preLeft, int preRight, vector<int>& preorder, vector<int>& inorder)
    {
        TreeNode* node = NULL;
        if (inLeft > inRight)
            return node;
        
        node = new TreeNode(preorder[preLeft]);

        //找出中序节点的位置
        int inIndex = inLeft;
        while (inIndex <= inRight && inorder[inIndex] != preorder[preLeft]) inIndex++;

        //preLeft + 1位左子树的根节点位置
        node->left = buildCore(inLeft, inIndex - 1, preLeft + 1, preRight, preorder, inorder);
        //找出前序遍历中右子树的根节点位置
        preLeft = preLeft + inIndex - inLeft + 1;
        node->right = buildCore(inIndex + 1, inRight, preLeft, preRight, preorder, inorder);

        return node;
    }
};