class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<bool> prev(target+1, 0), cur(target+1, 0);
        prev[0] = cur[0] = true;
        
        if(arr[0] <= target) prev[arr[0]] = true;
        
        
        for(int i=1; i<n; i++){
            for(int k=1; k<=target; k++){
                bool notPick = prev[k];
                bool pick = false;
                if(arr[i] <= k) pick = prev[k-arr[i]];
                
                cur[k] = notPick | pick;
            }
            prev = cur;
        }
        return prev[target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        if(total%2 == 1) return false;
        int target = total/2;
        return isSubsetSum(nums, target);
    }
};