class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), cur(amount+1, 0);
        for(int target=0; target<=amount; target++){
            prev[target] = (target%coins[0] == 0);
        } 

        for(int ind=1; ind<n; ind++){
            for(int target=0; target<=amount; target++){
                long long notTake = prev[target];
                long long take = 0;
                if(coins[ind] <= target) take = cur[target-coins[ind]];

                cur[target] = take+notTake;
            }
            prev = cur;
        }
        return prev[amount];
    }
};