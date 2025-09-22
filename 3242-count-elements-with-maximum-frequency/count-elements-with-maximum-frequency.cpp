class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(101);
        int cnt = 0;
        for(int i=0; i<n; i++){
            hash[nums[i]]++;
        }
        int maxi = *max_element(begin(hash), end(hash));
        for(int i=0; i<hash.size(); i++){
            if(maxi == hash[i]){
                cnt += hash[i];
            }
        }
        return cnt;
    }
};