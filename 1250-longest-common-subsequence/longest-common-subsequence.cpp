class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1, 0), cur(m+1, 0);

        for(int j=0; j<=m; j++) prev[j] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    cur[j] = 1 + prev[j-1];
                }
                else{
                    int l1 = 0 + prev[j];
                    int l2 = 0 + cur[j-1];

                    cur[j] = max(l1, l2);
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};