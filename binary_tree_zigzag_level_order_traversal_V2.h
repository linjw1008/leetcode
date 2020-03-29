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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return  vector<vector<int>>{};
        
        preOrder(root, 0);
        
        return ret;
    }
    
    void preOrder(TreeNode* root, int level)
    {
        if (root == nullptr) return;
        if (level >= ret.size()) ret.push_back(vector<int>());
        
        //从左向右
        if (level % 2 == 0)
        {
            ret[level].push_back(root->val);
        }
        else    //从右向左
        {
            ret[level].insert(ret[level].begin(), root->val);
        }
        preOrder(root->left, level + 1);
        preOrder(root->right, level + 1);
    }
    
private:
    vector<vector<int>> ret;
};