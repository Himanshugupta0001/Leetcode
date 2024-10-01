class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int ls = 0;
        int rs = 0;
        for(int i=0; i<k; i++){
            ls = ls + cardPoints[i];
        }

        int ri = n-1;
        int ml = ls;

        for(int i=k-1; i>=0; i--){
            ls = ls - cardPoints[i];
            rs = rs + cardPoints[ri];
            ri--;

            ml = max(ml, ls+rs);
        }
        return ml;
    }
};