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
    int mx;
    int maxP(TreeNode* root){
        if(root == nullptr)return 0;
        int l = maxP(root->left);
        int r = maxP(root->right);
        mx = max(l + r + root->val , mx);
        return max(0, root->val + max(l, r));
    }
    int maxPathSum(TreeNode* root) {
        mx = INT_MIN;
        maxP(root);
        return mx;
    }
};
