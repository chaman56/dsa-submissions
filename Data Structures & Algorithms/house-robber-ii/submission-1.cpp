class Solution {
public:
    int rob(vector<int>& nums) {
        int yes = 0, no = 0, n = nums.size();
        if(n==1)return nums[0];
        for(int i = 1; i<n; i++){
            int t = no;
            no = max(yes, no);
            yes = nums[i]+t;
        }
        int mx = max(yes, no);
        yes = 0, no = 0;
        for(int i = n-2; i>=0; i--){
            int t = no;
            no = max(yes, no);
            yes = nums[i]+t;
        }
        return max(mx, max(yes, no));
    }
};
