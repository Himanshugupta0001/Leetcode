class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        if(nums[0] < nums[n-1]){
            cnt++;
        }
        for(int i=1; i<n; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
            }
        }
        if(cnt < 2){
            return true;
        }
        return false;
    }
};