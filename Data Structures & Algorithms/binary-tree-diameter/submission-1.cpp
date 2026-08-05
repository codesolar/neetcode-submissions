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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int left = 0, right = 0;
        if(root->left){
            left = 1 + height(root->left);
        }
        if(root->right){
            right = 1 + height(root->right);
        }
        return max(left + right, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    int height(TreeNode* root){
        if(root == NULL) return 0;
        if(root->left and !root->right) return 1 + height(root->left);
        if(!root->left and root->right) return 1 + height(root->right);
        if(!root->left and !root->right) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};
