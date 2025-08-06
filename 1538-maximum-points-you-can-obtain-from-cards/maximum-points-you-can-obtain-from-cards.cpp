class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int maxi = 0;
        for(int i=0; i<k; i++){
            sum += cardPoints[i];
            maxi = sum;
        }
        int r = n-1;
        for(int i=(k-1); i>=0; i--){
            sum -= cardPoints[i];
            sum += cardPoints[r];
            maxi = max(sum, maxi);
            r--;
        }
        return maxi;
    }
};