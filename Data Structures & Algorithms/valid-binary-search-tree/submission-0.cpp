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
    bool fun(TreeNode* root, int l, int r){
        if(root == NULL) return true;
        if(root->val > l and root->val < r){
            return fun(root->left, l, root->val) and fun(root->right, root->val, r);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return fun(root, INT_MIN, INT_MAX);
    }
};
