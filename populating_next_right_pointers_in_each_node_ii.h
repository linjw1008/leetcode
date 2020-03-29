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
    Node* connect(Node* root) {
       if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return root;

        Node* next = nullptr;
        Node* r = root;


        while (r->next != nullptr)
        {
            if (r->next->left != nullptr)
            {
                next = r->next->left;
                break;
            }
            else if (r->next->right != nullptr)
            {
                next = r->next->right;
                break;
            } 
            else r = r->next;
        }
        cout << endl;


        if (root->left == nullptr && root->right != nullptr)
        {
            root->right->next = next;
        } 
        else if (root->left != nullptr && root->right == nullptr)
        {
            root->left->next = next;
        }
        else if (root->left != nullptr && root->right != nullptr)
        {
            root->left->next = root->right;
            root->right->next = next;
        }

        //要从右开始遍历！！！
        connect(root->right);
        connect(root->left);

       return root; 
    }
};