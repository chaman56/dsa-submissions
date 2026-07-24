class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<int>dp(amt+1, INT_MAX-1);
        dp[0] = 0;
        for(int i = 1; i<=amt; i++){
            for(int&c:coins){
                if(c>i)break;
                dp[i] = min(dp[i], 1+dp[i-c]);
            }
        }
        return dp[amt]==INT_MAX-1?-1:dp[amt];
    }
};
