class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1; i<n; i++){
            int l = nums[i];
            if(i > 1){
                l += prev2;
            }
            int r = 0 + prev;
            int cur = max(l, r);

            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};