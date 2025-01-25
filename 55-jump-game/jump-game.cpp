class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;

        int cnt = nums[0];
        for(int i=0; i<n; i++){
            cnt--;
            if(cnt < 0) return false;
            cnt = max(cnt, nums[i]);
        }
        return true;
    }
};