class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ml = 0;
        int cnt = 0;
        while(r < n){
            if(nums[r] == 0){
                cnt++;
            }

            if(cnt > k){
                if(nums[l] == 0){
                    cnt--;
                }
                l = l+1;
            }
            if(cnt <= k){
                ml = max(ml, r-l+1);
            }
            r = r+1;
        }
        return ml;
    }
};