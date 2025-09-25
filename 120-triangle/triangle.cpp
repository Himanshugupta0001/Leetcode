class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            dp[n-1][j] =  triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int neeche = triangle[i][j] + dp[i+1][j];
                int rightNeeche = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(neeche, rightNeeche);
            }
        }
        return dp[0][0];
    }
};