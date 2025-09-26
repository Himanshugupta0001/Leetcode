class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = nums[i] + nums[j];
                int idx = lower_bound(nums.begin() + j + 1, nums.end(), sum) - nums.begin();
                cnt += (idx - 1 - j);
            }
        }
        return cnt;
    }
};