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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL and subRoot == NULL) return true;
        if(root and subRoot){
            return sameTree(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
        } 
        if(root == NULL and subRoot) return false;
        return true;
    }
    bool sameTree(TreeNode* r1, TreeNode* r2){
        if(!r1 and !r2) return true;
        if(r1 and r2){
            if(r1->val == r2->val){
                return sameTree(r1->left, r2->left) and sameTree(r1->right, r2->right);
            }
            return false;
        }
        return false;
    }
};
