class Solution {
public:
    int f(vector<int> &nums, int k){
        int n = nums.size();
        int cnt = 0;
        map<int, int> mp;
        int l = 0;
        int r = 0;

        while(r < n){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l = l+1;
            }
            cnt = cnt + (r-l+1);
            r = r+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};