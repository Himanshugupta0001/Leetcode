class Solution {
public:
    long long int help(vector<int>& arr) {
        long long int n = arr.size();
        long long int prev = arr[0];
        long long int prev2 = 0;
        for(int i=1; i<n; i++){
            long long int l = arr[i];
            if(i > 1){
                l += prev2;
            }
            long long int r = 0 + prev;
            long long int cur = max(l, r);

            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
    long long int rob(vector<int>& nums) {
        long long int n = nums.size();
        vector<int> temp1(n-1), temp2(n-1);
        if(n == 1) return nums[0];
        for(int i=0; i<n; i++){
            if(i != 0){
                temp1.push_back(nums[i]);
            }
            if(i != n-1){
                temp2.push_back(nums[i]);
            }
        }
        long long int a = help(temp1);
        long long int b = help(temp2);
        return max(a,b);
    }
};