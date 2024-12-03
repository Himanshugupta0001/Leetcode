class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            int l = nums[i];
            if(i > 1){
                l += dp[i-2];
            }
            int r = 0 + dp[i-1];
            dp[i] = max(l, r);
        }
        return dp[n-1];
    }
};