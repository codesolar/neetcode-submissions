/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(root->val == key)
        {
            if(root->right != NULL)
            {
                auto p = root->right;
                if(p->left == NULL)
                {
                    root->right = p->right;
                    root->val = p->val;
                    delete(p);
                }
                else
                {
                    auto q = p->left;
                    while(q->left != NULL) {
                        p = q;
                        q = q -> left;
                    }
                    p->left = q->right;
                    root->val = q->val;
                    delete(q);
                }
                return root;
            }
            else
            {
                return root->left;
            }
        }
        return root;
    }
};