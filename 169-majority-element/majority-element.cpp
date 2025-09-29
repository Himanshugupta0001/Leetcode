class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int ele = -1e9;
        for(int i=0; i<n; i++){
            if(cnt > 0){
                if(nums[i] == ele){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
            else if(cnt == 0){
                ele = nums[i];
                cnt++;
            }
        }
        return ele;
    }
};