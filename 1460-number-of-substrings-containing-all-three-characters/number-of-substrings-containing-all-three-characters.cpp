class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int>st(3,0);
        int i=0,j=0;
        int ans=0;
        while(j<n)
        {
            st[s[j]-'a']++;
            while(st[0]>0&&st[1]>0&&st[2]>0)
            {
                ans+=n-j;
                st[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};