class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minProd = nums[0], maxProd = nums[0], mx = nums[0];
        for(int i = 1; i<n; i++){
            int tmp = maxProd*nums[i];
            maxProd = max(nums[i], max(minProd*nums[i], maxProd*nums[i]));
            minProd = min(nums[i], min(minProd*nums[i], tmp));
            mx = max(maxProd, mx);
        }
        return mx;
    }
};
