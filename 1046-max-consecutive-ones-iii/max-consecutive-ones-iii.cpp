class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int no = 0;
        int l = 0;
        int r = 0;
        int ml = 0;

        while(r < n){
            if(nums[r] == 0){
                no++;
            }

            if(no > k){
                if(nums[l] == 0){
                    no--;
                }
                l = l+1;
            }
            if(no <= k){
                ml = max(ml, r-l+1);
            }
            r = r+1;
        }
        return ml;
    }
};