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
    int ans;
    void countNodes(TreeNode* root, int& k, int& val){
        if(!root)return;
        countNodes(root->left, k, val);
        k--; if(k==0){val = root->val; return;}
        countNodes(root->right, k, val);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        countNodes(root, k, ans);
        return ans;
    }
};
