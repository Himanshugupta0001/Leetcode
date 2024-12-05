class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<int> prev(target+1, 0), cur(target+1, 0);
        
        
        for(int k=0; k<=target; k++){
            if(k == 0 && arr[0] == 0) prev[k] = 2;
            else if(k == 0 || k == arr[0]){
                prev[k] = 1;
            }
            else prev[k] = 0;
        }
        
        
        for(int ind=1; ind<n; ind++){
            for(int k=0; k<=target; k++){
                int notTake = prev[k];
                int take = 0;
                if(k >= arr[ind]) take = prev[k-arr[ind]];
                
                cur[k] = take + notTake;
            }
            prev = cur;
        }
        return prev[target];
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        
        int n = arr.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += arr[i];
        }
        if(total - d < 0 || (total-d)%2 == 1) return false;
        return perfectSum(arr, (total-d)/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};