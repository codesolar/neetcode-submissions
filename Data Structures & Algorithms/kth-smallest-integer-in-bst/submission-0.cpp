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
    int fun(TreeNode* root, int k, int &count){
        if(root == NULL) return -1;
        int l = fun(root->left, k, count);
        if(l != -1) return l;
        count ++;
        if(count == k) return root->val;
        int r = fun(root->right, k, count);
        if(r != -1) return r;
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return fun(root, k, count);
    }
};
