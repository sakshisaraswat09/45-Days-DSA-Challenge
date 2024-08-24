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
    void solve(TreeNode* root){
        if(!root) return;
        TreeNode* node = root->left;
        root->left = root->right;
        root->right = node;
        solve(root->right);
        solve(root->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        solve(root);
        return root;
    }
};
