class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            while(!ans.empty()){
                int prev = ans.back();
                int curr = nums[i];

                int GCD = gcd(prev, curr);
                if(GCD == 1){
                    break;
                }
                ans.pop_back();
                int LCM = prev / GCD*curr;
                nums[i] = LCM;
            }
            ans.push_back(nums[i]);
        }
        return ans;
    }
};