//打家劫舍III

#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int robCore(TreeNode* root, int isSelected, unordered_map<TreeNode*, int>& memIsSelected, unordered_map<TreeNode*, int>& memIsNotSelected)
    {
        int res = 0;
        if (isSelected && memIsSelected.find(root) != memIsSelected.end())
        {
            return memIsSelected[root];
        }
        else if (!isSelected && memIsNotSelected.find(root) != memIsNotSelected.end())
        {
            return memIsNotSelected[root];
        }

        if (root == nullptr)
        {
            res = 0;
        }
        else if (isSelected)
        {
            res = root->val + robCore(root->left, 0, memIsSelected, memIsNotSelected) + robCore(root->right, 0, memIsSelected, memIsNotSelected);
        }
        else
        {
            res = max(robCore(root->left, 1, memIsSelected, memIsNotSelected), robCore(root->left, 0, memIsSelected, memIsNotSelected)) + max(robCore(root->right, 1, memIsSelected, memIsNotSelected), robCore(root->right, 0, memIsSelected, memIsNotSelected));
        }

        if (isSelected)
        {
            memIsSelected[root] = res;
        }
        else
        {
            memIsNotSelected[root] = res;
        }

        return res;
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memIsSelected, memIsNotSelected;
        return max(robCore(root, 0, memIsSelected, memIsNotSelected), robCore(root, 1, memIsSelected, memIsNotSelected));
    }
};