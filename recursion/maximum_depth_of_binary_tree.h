#ifndef _MAXIMUM_DEPTH_OF_BINARY_TREE_H_
#define _MAXIMUM_DEPTH_OF_BINARY_TREE_H_

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

#endif