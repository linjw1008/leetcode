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
        stack<TreeNode*> q;
        stack<TreeNode*> s;
        vector<vector<int>> ret;
        
        q.push(root);
        while (!q.empty() || !s.empty())
        {
            int index = 0;
            
            vector<int> tmp;
            
            if (!q.empty())
            {
                while (!q.empty())
                {
                    TreeNode* n = q.top();
                    q.pop();
                    
                    tmp.push_back(n->val);
                    if (n->left != nullptr) s.push(n->left);
                    if (n->right != nullptr) s.push(n->right);    
                }
                ret.push_back(tmp);
            }
            else
            {
                while (!s.empty())
                {                   
                    TreeNode* n = s.top();
                    s.pop();
                    
                    tmp.push_back(n->val);
                    if (n->right != nullptr) q.push(n->right);      
                    if (n->left != nullptr) q.push(n->left);      
                }
                ret.push_back(tmp);
            }
        }
        
        return ret;
    }
};