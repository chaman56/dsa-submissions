class Solution {
public:
    int rob(vector<int>& nums) {
        int y = nums[0], n = 0;
        for(int i = 1; i<nums.size(); i++){
            int tmp = n;
            n = max(y, n);
            y = nums[i]+tmp;
        }
        return max(y, n);
    }
};
