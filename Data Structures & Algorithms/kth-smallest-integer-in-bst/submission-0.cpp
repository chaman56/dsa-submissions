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
    int countNodes(TreeNode* root, int previ, int& k){
        if(root == NULL) return 0;
        if(previ>k)return -1;
        int ctl = countNodes(root->left, previ, k);
        if(ctl == -1)return -1;
        if (previ+ctl+1 == k){
            ans = root->val;
            return -1;
        }
        int ctr = countNodes(root->right, previ + ctl + 1, k);
        if(ctr == -1)return -1;
        return 1 + ctl + ctr;
    }
    int kthSmallest(TreeNode* root, int k) {
        countNodes(root, 0, k);
        return ans;
    }
};
