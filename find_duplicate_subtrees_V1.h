//寻找重复的子树
//dfs法


#include <vector>
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> map;
        vector<TreeNode*> res;
        
        dfs(root, map, res);
        
        return res;
    }
    
    string dfs(TreeNode* root, unordered_map<string, int>& map, vector<TreeNode*>& res)
    {
        string ans = "";
        
        if (root == NULL) return "#";
        
        ans = ans + to_string(root->val) + ",";
        ans = ans + dfs(root->left, map, res) + ",";
        ans = ans + dfs(root->right, map, res);
        map[ans] += 1;
        
        if (map[ans] == 2) res.push_back(root); 
        
        return ans;
    }
};