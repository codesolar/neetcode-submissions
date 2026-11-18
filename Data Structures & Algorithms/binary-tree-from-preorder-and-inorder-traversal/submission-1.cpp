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
    TreeNode* fun(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2){
        if((l1 > r1) or (l2 > r2)) return NULL;
        int root_ind = -1;
        int root_val = preorder[l1];
        for(int i = l2; i <= r2; i ++){
            if(inorder[i] == root_val)
            {
                root_ind = i;
                break;
            }
        }
        int left_node = root_ind - l2;
        int right_node = r2 - root_ind;
        auto root = new TreeNode(root_val);
        root->left = fun(preorder, inorder, l1 + 1, l1 + left_node, l2, root_ind - 1);
        root->right = fun(preorder, inorder, l1 + left_node + 1, r1, root_ind + 1, r2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return fun(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
