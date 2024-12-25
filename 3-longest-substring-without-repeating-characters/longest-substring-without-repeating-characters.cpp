class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> hash(256, -1);

        int l = 0;
        int r = 0;
        int ml = 0;

        while(r < n){
            if(hash[s[r]] != -1 && hash[s[r]] >= l){
                l = max(hash[s[r]] + 1, l);
            }
            hash[s[r]] = r;
            ml = max(ml, r-l+1);
            r++;
        }
        return ml;
    }
};