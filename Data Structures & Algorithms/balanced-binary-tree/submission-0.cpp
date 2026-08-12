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
    bool isBalanced(TreeNode* root) {
        return func(root).first;
    }
    pair<bool, int> func(TreeNode* root){
        if(root == NULL) return {true, -1};
        pair<bool, int> p1 = func(root->left);
        pair<bool, int> p2 = func(root->right);
        if(p1.first == true and p2.first == true)
        {
            if(abs(p1.second - p2.second) <= 1)
            {
                return {true, max(p1.second, p2.second) + 1};
            }
            else return {false, INT_MAX};
        }
        return {false, INT_MAX}; 
    }
};
