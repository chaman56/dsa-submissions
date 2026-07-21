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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return vector<int>();
        map<int, int>mp;
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        int level = 0;
        while(!q.empty()){
            TreeNode* u = q.front();q.pop();
            if(u==nullptr){
                level++;
                if(!q.empty())q.push(nullptr);
                continue;
            }
            if(mp.find(level)==mp.end()){
                mp[level] = u->val;
            }
            if(u->right) q.push(u->right);
            if(u->left) q.push(u->left);
        }
        vector<int>v;
        for(auto& x: mp){
            v.push_back(x.second);
        }
        return v;
    }
};
