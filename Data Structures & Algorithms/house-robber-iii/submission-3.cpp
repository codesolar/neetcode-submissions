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
unordered_map<TreeNode* ,int> map;
int rob(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if(map.find(root) != map.end()){
            return map[root];
        }

        int res = root->val;
        if (root->left) {
            res += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            res += rob(root->right->left) + rob(root->right->right);
        }

        res = max(res, rob(root->left) + rob(root->right));
        map[root] = res;
        return res;
    }
};