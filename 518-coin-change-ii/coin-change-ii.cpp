class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int target=0; target<=amount; target++){
            dp[0][target] = (target%coins[0] == 0);
        } 

        for(int ind=1; ind<n; ind++){
            for(int target=0; target<=amount; target++){
                long long notTake = dp[ind-1][target];
                long long take = 0;
                if(coins[ind] <= target) take = dp[ind][target-coins[ind]];

                dp[ind][target] = take+notTake;
            }
        }
        return dp[n-1][amount];
    }
};