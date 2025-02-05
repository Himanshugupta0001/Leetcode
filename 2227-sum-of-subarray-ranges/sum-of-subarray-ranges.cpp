class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n = nums.size();
        long long result = 0;
        for(long long i=0; i<n; i++){
            long long maxi = nums[i];
            long long mini = nums[i];
            for(long long j=i+1; j<n; j++){
                if(nums[j] > maxi){
                    maxi = nums[j];
                }
                else if(nums[j] < mini){
                    mini = nums[j];
                }
                result += (maxi-mini);
            }
        }
        return result;
    }
};