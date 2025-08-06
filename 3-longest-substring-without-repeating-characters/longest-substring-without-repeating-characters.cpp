class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        int l = 0;
        int r = 0;
        vector<int> hash(256, -1);
        while(r < n){
            if(hash[s[r]] != -1 && hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
            hash[s[r]] = r;
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};