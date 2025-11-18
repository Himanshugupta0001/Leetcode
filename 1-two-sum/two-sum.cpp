class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n = nums.size();
       unordered_map<int, int> mp;
       for(int i=0; i<n; i++){
            int val = nums[i];
            int more = target-val;
            if(mp.find(more) != mp.end()){
                return {mp[more], i};
            }
            mp[val] = i;
       }
       return {};
    }
};