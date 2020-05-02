//二叉树的最近公共祖先

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* ans;

    bool recurseTree(TreeNode* currentNode, TreeNode* p, TreeNode* q)
    {
        //终止条件
        if (currentNode == nullptr)
        {
            return false;
        }

        //查找左边是否有
        int left = recurseTree(currentNode->left, p, q) ? 1 : 0;
        //查找右边是否有
        int right = recurseTree(currentNode->right, p, q) ? 1 : 0;
    
        int mid = (currentNode->val == p->val || currentNode->val == q->val) ? 1 : 0;

        //如果左边或者右边有，说明本节点为公共祖先
        if (mid + left + right >= 2)
        {
            ans = currentNode;
        }

        return (mid + left + right > 0);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recurseTree(root, p, q);
        return ans;
    }
};