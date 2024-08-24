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
    int maxLength(TreeNode* root,int& maxi){
        if(!root) return 0;
        int l = maxLength(root->left,maxi);
        int r = maxLength(root->right,maxi);
        maxi = max(maxi,r+l);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxi = 0;
        int temp = maxLength(root,maxi);
        return maxi;
    }
};
