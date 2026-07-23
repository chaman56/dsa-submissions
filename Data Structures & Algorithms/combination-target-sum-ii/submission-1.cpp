class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<int>&c, int t, int i, vector<int>cur){
        if(t==0){
            res.push_back(cur);
            return;
        }
        if(t<0 || i>=c.size())return;

        cur.push_back(c[i]);
        dfs(c, t-c[i], i+1, cur);
        cur.pop_back();
        while(i+1<c.size() && c[i]==c[i+1])i++;
        dfs(c, t, i+1, cur);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, {});
        return res;
    }
};
