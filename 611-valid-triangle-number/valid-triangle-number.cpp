class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        sort(begin(nums), end(nums));
        for(int i=n-1; i>=2; i--){
            int l = 0;
            int r = i-1;
            while(l < r){
                if(nums[l] + nums[r] > nums[i]){
                    cnt += (r - l);
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return cnt;
    }
};