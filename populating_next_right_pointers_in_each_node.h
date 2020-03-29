

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* dfs(Node* root)
    {
        if (root == nullptr || root->right == nullptr || root->left == nullptr) return root;
        
        root->left->next = root->right;
        if (root->next) root->right->next = root->next->left;
        
        dfs(root->left);
        dfs(root->right);
        
        return root;
    }
    
    Node* connect(Node* root) {
        Node* n = root;
        return dfs(n);
    }
};