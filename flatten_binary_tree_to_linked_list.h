#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
        {
            return;
        }
        if (root->left != nullptr)
        {
            flatten(root->left);
        }
        if (root->right != nullptr)
        {
            flatten(root->right);
        }

        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right)
        {
            root = root->right;
        }

        root->right = tmp;
    }
};